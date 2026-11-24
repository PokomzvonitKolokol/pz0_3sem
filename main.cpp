#include <iostream>
#include "figures.h"
#include "func.h"
#include "structs.h"

using namespace std;


int main() {

    Point p1 = ReadPoint(1, 1);
    Point p2 = ReadPoint(3, 0);
    Point p3 = ReadPoint(10, 10);

    Circle c1 = ReadCircle(0, 0, 3);
    Circle c2 = ReadCircle(4, 0, 2);
    Circle c3 = ReadCircle(0, 0, 1);

    Rectangle r1 = ReadRectangle(-2, 2, 4);
    Rectangle r2 = ReadRectangle(-1, 1, 1);
    Rectangle r3 = ReadRectangle(1, 1, 4);

    cout << "Point p1: ";
    PrintPoint(p1);
    cout << "Circle c1: ";
    PrintCircle(c1);
    cout << "Rectangle r1: ";
    PrintRectangle(r1);
    cout << endl;

    cout << "Length of c1: " << LengthCircle(c1) << endl;
    cout << "Square of c1: " << SquareCircle(c1) << endl;
    cout << "Perimeter of r1: " << Perimeter(r1) << endl;
    cout << "Square of r1: " << SquareRectangle(r1) << endl;
    cout << endl;

    cout << "p1 in c1: " << PointInCircle(p1, c1) << endl;
    cout << "p3 in c1: " << PointInCircle(p3, c1) << endl;
    cout << "p1 in r1: " << PointInRectangle(p1, r1) << endl;
    cout << "p3 in r1: " << PointInRectangle(p3, r1) << endl;
    cout << endl;

    cout << "p2 on c1: " << PointOnCircle(p2, c1) << endl;
    cout << "p1 on c1: " << PointOnCircle(p1, c1) << endl;
    cout << "(2, 0) on r1: " << PointOnRectangle(ReadPoint(2, 0), r1) << endl;
    cout << "p1 on r1: " << PointOnRectangle(p1, r1) << endl;
    cout << endl;

    cout << "c1 cross c2: " << CrossTwoCircles(c1, c2) << endl;
    cout << "c1 cross c3: " << CrossTwoCircles(c1, c3) << endl;
    cout << "r1 cross r3: " << CrossTwoRectangles(r1, r3) << endl;
    cout << "r1 cross r2: " << CrossTwoRectangles(r1, r2) << endl;
    cout << "c1 cross r1: " << CrossCircleRectangle(c1, r1) << endl;
    cout << "c3 cross r1: " << CrossCircleRectangle(c3, r1) << endl;
    cout << endl;

    cout << "c3 in c1: " << CircleInCircle(c3, c1) << endl;
    cout << "c2 in c1: " << CircleInCircle(c2, c1) << endl;
    cout << "r2 in r1: " << RectangleInRectangle(r2, r1) << endl;
    cout << "r3 in r1: " << RectangleInRectangle(r3, r1) << endl;
    cout << "c3 in r1: " << CircleInRectangle(c3, r1) << endl;
    cout << "c1 in r1: " << CircleInRectangle(c1, r1) << endl;
    cout << "r1 in c1: " << RectangleInCircle(r1, c1) << endl;
    cout << "r2 in c1: " << RectangleInCircle(r2, c1) << endl;

    return 0;
}
