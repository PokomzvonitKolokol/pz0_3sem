#include <cmath>
#include <iostream>
#include "structs.h"
using namespace std;


Point ReadPoint(double x, double y) {
    return Point{ x, y };
};
void PrintPoint(Point p) {
    cout << p.x << " " << p.y << endl;
}



Circle ReadCircle(double x, double y, double r) {
    return Circle{
        r,
        Point{x, y}
    };
}
void PrintCircle(Circle c) {
    cout << c.p.x << " " << c.p.y << " " << c.r << endl;
}
double LengthCircle(Circle c) {
    return 2 * M_PI * c.r;
}
double SquareCircle(Circle c) {
    return pow(c.r, 2) * M_PI;
}



Rectangle ReadRectangle(double x, double y, double l) {
    return Rectangle{
        Point{x, y},
        l
    };
}
void PrintRectangle(Rectangle r) {
    cout << r.p.x << " " << r.p.y << " " << r.l << endl;
}
double Perimeter(Rectangle r) {
    return 4 * r.l;
}
double SquareRectangle(Rectangle r) {
    return  r.l * r.l;
}