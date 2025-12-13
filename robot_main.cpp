#include <iostream>
#include <limits>
#include <cmath> 
#include <iomanip>
#include "robot.h" 

using namespace std;
using namespace robotics;

const int GRID_WIDTH = 21;
const int GRID_HEIGHT = 11;
const int MAP_SCALE = 5; 

float get_numeric_input(const string& prompt) {
    float value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Gecersiz girdi! Lütfen gecerli bir sayi girin: ";
    }
    return value;
}

void drawMap(const Robot& robot) {
    float rx = robot.getX();
    float ry = robot.getY();
    
    int center_x = GRID_WIDTH / 2;
    int center_y = GRID_HEIGHT / 2;
    
    int map_x = center_x + static_cast<int>(round(rx / MAP_SCALE));
    int map_y = center_y - static_cast<int>(round(ry / MAP_SCALE));

    bool is_on_map = (map_x >= 0 && map_x < GRID_WIDTH && 
                      map_y >= 0 && map_y < GRID_HEIGHT);

    cout << "\n--- ASCII Harita Görselleştirme (Ölçek: 1 birim = " << MAP_SCALE << "m) ---\n";
    
    for (int j = 0; j < GRID_HEIGHT; ++j) {
        for (int i = 0; i < GRID_WIDTH; ++i) {
            
            if (i == map_x && j == map_y && is_on_map) {
                cout << 'R'; 
            } else if (i == center_x && j == center_y) {
                cout << 'O'; 
            } else if (i == center_x || j == center_y) {
                cout << '+';
            }
            else {
                cout << '.';
            }
        }
        cout << endl;
    }

    if (!is_on_map) {
        cout << "\nUYARI: Robotun pozisyonu haritanin disinda! (Grid: " << map_x << ", " << map_y << ")\n";
    }
    
    cout << "Pozisyon (Grid): (" << map_x << ", " << map_y << ") | Gercek: (" << rx << ", " << ry << ")\n";
}

int main() {
    Robot robot; 
    int choice;

    cout << "Robot Dead Reckoning Simulator baslatildi. Baslangic Pose:\n";
    robot.printPose(); 

    while (true) {
        cout << "\n====================\n";
        cout << "     ROBOT MENU\n";
        cout << "====================\n";
        cout << "1) Ilerlet (Move)\n";
        cout << "2) Döndür (Rotate)\n";
        cout << "3) Pozisyonu Goster (Show Pose)\n";
        cout << "4) Sifirla (Reset)\n";
        cout << "5) Harita Ciz (ASCII Görselleştirme)\n"; 
        cout << "6) Cikis (Exit)\n";
        cout << "Seciminiz: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nGeçersiz menü girdisi! Lütfen 1-6 arasi bir sayi girin.\n";
            continue;
        }

        if (choice == 6) {
            cout << "Program sonlandiriliyor.\n";
            break;
        }

        switch (choice) {
            case 1: {
                float d = get_numeric_input("  Ilerleme mesafesini girin: ");
                robot.move(d);
                cout << "Hareket edildi. Yeni Pose:\n";
                robot.printPose();
                break;
            }
            case 2: {
                float a = get_numeric_input("  Dönüs acisini girin (derece): ");
                robot.rotate(a);
                cout << "Dönüs yapildi. Yeni Pose:\n";
                robot.printPose();
                break;
            }
            case 3: {
                robot.printPose();
                break;
            }
            case 4: {
                robot.reset();
                cout << "Robot pozisyonu (0, 0, 0°) olarak sifirlandi.\n";
                robot.printPose();
                break;
            }
            case 5: {
                drawMap(robot);
                break;
            }
            default: {
                cout << "Hata: Gecersiz menü secimi (" << choice << "). Lütfen 1-6 arasi secin.\n";
                break;
            }
        }
    }
    return 0;
}
