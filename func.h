#pragma once
#include "structs.h"

bool PointInCircle(Point p, Circle c);
bool PointInRectangle(Point p, Rectangle r);

bool PointOnCircle(Point p, Circle c);
bool PointOnRectangle(Point p, Rectangle r);

bool CrossTwoCircles(Circle c1, Circle c2);
bool CrossTwoRectangles(Rectangle r1, Rectangle r2);
bool CrossCircleRectangle(Circle c, Rectangle r);

bool CircleInCircle(Circle c1, Circle c2);
bool RectangleInRectangle(Rectangle r1, Rectangle r2);
bool CircleInRectangle(Circle c, Rectangle r);
bool RectangleInCircle(Rectangle r, Circle c);