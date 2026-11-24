#include <cmath>
#include <algorithm>
#include "structs.h"
using namespace std;

const double EPS = 1e-5;


static double Left(Rectangle r) { return r.p.x; }
static double Right(Rectangle r) { return r.p.x + r.l; }
static double Top(Rectangle r) { return r.p.y; }
static double Bottom(Rectangle r) { return r.p.y - r.l; }

static double Distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}



bool PointInCircle(Point p, Circle c) {
    return Distance(p, c.p) < c.r - EPS;
}

bool PointInRectangle(Point p, Rectangle r) {
    return p.x > Left(r) + EPS && p.x < Right(r) - EPS &&
           p.y > Bottom(r) + EPS && p.y < Top(r) - EPS;
}



bool PointOnCircle(Point p, Circle c) {
    return fabs(Distance(p, c.p) - c.r) < EPS;
}

bool PointOnRectangle(Point p, Rectangle r) {
    bool insideOrOn = p.x > Left(r) - EPS && p.x < Right(r) + EPS &&
                      p.y > Bottom(r) - EPS && p.y < Top(r) + EPS;
    return insideOrOn && !PointInRectangle(p, r);
}



bool CrossTwoCircles(Circle c1, Circle c2) {
    double d = Distance(c1.p, c2.p);
    return d > fabs(c1.r - c2.r) - EPS && d < c1.r + c2.r + EPS;
}

static bool RectangleStrictlyInside(Rectangle r1, Rectangle r2) {
    return Left(r1) > Left(r2) + EPS && Right(r1) < Right(r2) - EPS &&
           Bottom(r1) > Bottom(r2) + EPS && Top(r1) < Top(r2) - EPS;
}

bool CrossTwoRectangles(Rectangle r1, Rectangle r2) {
    bool overlap = Left(r1) < Right(r2) + EPS && Left(r2) < Right(r1) + EPS &&
                   Bottom(r1) < Top(r2) + EPS && Bottom(r2) < Top(r1) + EPS;
    return overlap && !RectangleStrictlyInside(r1, r2) && !RectangleStrictlyInside(r2, r1);
}

bool CrossCircleRectangle(Circle c, Rectangle r) {
    Point p = c.p;

    double minDist;
    if (PointInRectangle(p, r)) {
        minDist = min({p.x - Left(r), Right(r) - p.x, Top(r) - p.y, p.y - Bottom(r)});
    } else {
        double dx = max({Left(r) - p.x, 0.0, p.x - Right(r)});
        double dy = max({Bottom(r) - p.y, 0.0, p.y - Top(r)});
        minDist = sqrt(dx * dx + dy * dy);
    }

    double maxDx = max(fabs(p.x - Left(r)), fabs(p.x - Right(r)));
    double maxDy = max(fabs(p.y - Top(r)), fabs(p.y - Bottom(r)));
    double maxDist = sqrt(maxDx * maxDx + maxDy * maxDy);

    return c.r > minDist - EPS && c.r < maxDist + EPS;
}



bool CircleInCircle(Circle c1, Circle c2) {
    return Distance(c1.p, c2.p) + c1.r < c2.r + EPS;
}

bool RectangleInRectangle(Rectangle r1, Rectangle r2) {
    return Left(r1) > Left(r2) - EPS && Right(r1) < Right(r2) + EPS &&
           Bottom(r1) > Bottom(r2) - EPS && Top(r1) < Top(r2) + EPS;
}

bool CircleInRectangle(Circle c, Rectangle r) {
    return c.p.x - c.r > Left(r) - EPS && c.p.x + c.r < Right(r) + EPS &&
           c.p.y - c.r > Bottom(r) - EPS && c.p.y + c.r < Top(r) + EPS;
}

bool RectangleInCircle(Rectangle r, Circle c) {
    Point corners[4] = {
        {Left(r), Top(r)}, {Right(r), Top(r)},
        {Left(r), Bottom(r)}, {Right(r), Bottom(r)}
    };
    for (Point corner : corners) {
        if (Distance(corner, c.p) > c.r + EPS) {
            return false;
        }
    }
    return true;
}
