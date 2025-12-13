#include "Calculator.h"
#include <iostream>
#include <cmath>


float Calculator::addition(float a, float b) {
    return a + b;
}

float Calculator::substraction(float a, float b) {
    return a - b;
}

float Calculator::multiplication(float a, float b) {
    return a * b;
}
float Calculator::division(float a, float b) {
    if (b == 0)
        throw "Division by zero eror!";
    return a / b;
}

float Calculator::square(float a) {
    return a * a;
}

float Calculator::exponentiation(float a, float b) {
    return pow(a, b);
}
int Calculator::modulus(int a, int b) {
    if (b == 0)
        throw "MOdulo by zero error!";
    return a % b;
}
