#pragma once
#include "structs.h"


Point ReadPoint(double x, double y);
void PrintPoint(Point p);


Circle ReadCircle(double x, double y, double r);
void PrintCircle(Circle c);
double LengthCircle(Circle c);
double SquareCircle(Circle c);

Rectangle ReadRectangle(double x, double y, double l);
void PrintRectangle(Rectangle r);
double Perimeter(Rectangle r);
double SquareRectangle(Rectangle r);