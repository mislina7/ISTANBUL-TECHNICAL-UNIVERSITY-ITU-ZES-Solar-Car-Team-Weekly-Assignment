#include <iostream>
#include <iomanip>
#include <cstdint>
#include <memory>
#include <cmath>

using namespace std;

struct Point{
     float x, y, z;
};

float zero_distance(const Point& p){
     return sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
}
float distance(const Point& a, const Point & b) {
     return sqrt(
          pow(a.x - b.x, 2) +
          pow(a.y - b.y, 2) +
          pow(a.z - b.z, 2)
     );
}
     

     int region(const Point& p) {
          if (p.x >= 0 && p.y >= 0 && p.z >= 0) return 1;
          else if (p.x < 0 && p.y >= 0 && p.z >= 0) return 2;
          else if (p.x < 0 && p.y < 0 && p.z >= 0) return 3;
          else if (p.x >= 0 && p.y < 0 && p.z >= 0) return 4;
          else if (p.x >= 0 && p.y >= 0 && p.z < 0) return 5;
          else if (p.x < 0 && p.y >= 0 && p.z < 0) return 6;
          else if (p.x < 0 && p.y < 0 && p.z < 0) return 7;
          else return 8;
}




string compare(const Point& p1, const Point& p2) {

     if (zero_distance(p1) > zero_distance(p2))
          return "Point 1 is farther from zero.";
     else if (zero_distance(p2) > zero_distance(p1)) 
          return "Point 2 is farther from zero.";
     else
          return "Both are at the same distance from zero.";
}



bool is_in_same_region(const Point& p1, const Point& p2) {
     return region(p1) == region(p2);
}

int main() {

cout << "---2 Point Structure---" << endl;
Point A = {2, 4, 6};
Point B = {-2, -1, 3};

cout << "A zero distance: " << zero_distance(A) << endl;
cout << "B zero distance: " << zero_distance(B) << endl;

cout << "\nDistance between A an d B: " << distance(A, B) << endl;

cout << "\nCompare: " << compare(A, B) << endl;

cout << "\nA region: " << region(A) << endl;
cout << "B region : " << region(B) << endl;

cout << "\nAre A and B in the same region? ";
cout << (is_in_same_region(A, B) ? "Yes" : "No") << endl;
return 0;
}
