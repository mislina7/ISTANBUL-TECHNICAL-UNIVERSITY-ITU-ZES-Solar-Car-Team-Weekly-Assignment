#ifndef ROBOT_H
#define ROBOT_H

namespace robotics {

class Robot {
private:
    float x;
    float  y;
    float heading;
public:

    Robot();

    void move(float distance);
    void rotate(float angle_deg);
    void reset();

    float getX() const;
    float getY() const;
    float getHeading() const;

    void printPose() const;

};

}

#endif
    



