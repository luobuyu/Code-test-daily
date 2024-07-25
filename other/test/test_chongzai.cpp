#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double pi = acos(-1);
class Point
{

public:
    double x, y;
    // 重载负号
    Point operator-() const
    {
        return Point(-x, -y);
    }
    // 重载四则运算
    Point operator-(const Point &p) const
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator+(const Point &p) const
    {
        return Point(x + p.x, y + p.y);
    }
    Point operator/(const double &k) const
    {
        return Point(x / k, y / k);
    }
    Point operator*(const double &k) const
    {
        return Point(x * k, y * k);
    }
    Point operator*=(const double &k)
    {
        x = x * k;
        y = y * k;
        return *this;
    }
    // 叉积
    double operator^(const Point &p) const
    {
        return x * p.y - y * p.x;
    }
    // 点积
    double operator*(const Point &p) const
    {
        return x * p.x + y * p.y;
    }
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point rotatePoint(const Point &p, double angle)
    {
        double c = cos(angle), s = sin(angle);
        Point v = (*this) - p;
        return Point(p.x + v.x * c - v.y * s, p.y + v.x * s + v.y * c);
    }
};

double distance(Point &a, Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
// b      a
//    c
int main()
{
    Point a(-160.31086357992604, 19.660965000000001);
    Point b(-160.81335642007400, 19.660965000000001);
    Point c(-160.56211000000005, 17.980670000000003);
    double disdiv2 = distance(a, b) / 2;
    double radius = distance(a, c);
    double h = sqrt(radius * radius - disdiv2 * disdiv2);
    double delta = radius - h;
    double angle = atan2(disdiv2, h) * 2;
    Point d = c.rotatePoint(a, -(pi * 17.0 / 36));
    Point v = d - a;
    cout << setprecision(10);
    cout << radius << endl;
    cout << delta << endl;
    cout << angle << endl;
    cout << d.x << ", " << d.y << endl;
    cout << v.x << ", " << v.y << endl;
    return 0;
}