#include "robot.h"
#include <iostream>
#include <cmath>
#include <limits>

using namespace robotics;

Robot::Robot() {
    x = 0;
    y = 0;
    heading = 0;
}

void Robot::move(float distance) {
    float rad = heading * M_PI / 180.0f;
    x += distance * cos(rad);
    y += distance * sin(rad);

}

void Robot::rotate(float angle_deg) {
    heading += angle_deg;

    if (heading >= 360) heading -= 360;
    if (heading < 0) heading += 360;

}

void Robot::reset(){
    x = 0;
    y = 0;
    heading = 0;

}

float Robot::getX() const {
    return x;
}

float Robot::getY() const {
    return y;
}

float Robot::getHeading() const {
    return heading;
}

void Robot::printPose() const{
    std::cout << "Position: (x=" << x
              << ", y=" << y
              << "), heading=" << heading << " degrees\n";
}
