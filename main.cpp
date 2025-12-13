#include <iostream>
#include "Calculator.h"
#include <limits>

using namespace std;

int main() {
    Calculator calc;
    int choice;

    while (true) {
        cout << "\n CALCULATOR MENU\n";
        cout << "1. Addition\n";
        cout << "2. Substraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Square\n";
        cout << "6. Exponentiation\n";
        cout << "7. MOdulus\n";
        cout << "8. Exit\n";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number between 1 and 8.\n";
            continue;
        }

        if (choice == 8) {
            cout << "Program finished. \n";
            break;
        }
    try {
        if (choice == 1) {
            float a, b;
            cin >> a >> b;
            cout << "Result: " << calc.addition(a, b) << endl;
        }
        else if (choice == 2) {
            float a, b;
            cin >> a >> b;
            cout << "Result: " << calc.substraction(a, b) << endl;
        }
        else if (choice == 3) {
            float a, b;
            cin >> a >> b;
            cout << "Result: " << calc.multiplication(a, b) << endl;
        }
        else if (choice == 4) {
            float a, b;
            cin >> a >> b;
            cout << "Result: " << calc.division(a, b) << endl;
        }
        else if (choice == 5) {
            float a;
            cin >> a;
            cout << "Result: " << calc.square(a) << endl;
        }
        else if (choice == 6) {
            float a, b;
            cin >> a >> b;
            cout << "Result: " << calc.exponentiation(a, b) << endl;
        }
        else if (choice == 7) {
            int a, b;
            cin >> a >> b;
            cout << "Result: " << calc.modulus(a, b) << endl;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
}
return 0;
}
