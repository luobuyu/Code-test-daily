#include <bits/stdc++.h>
#define ll long long
#define lll long long
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
const double pi = acos(-1.0);
int t, n, m, k;
int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < -1 ? -1 : 1;
}
struct Point
{
    double x, y;
    // 构造
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point polar(double length, double angle)
    {
        return Point(length * cos(angle), length * sin(angle));
    }
    // 读入
    void
    input()
    {
        scanf("%lf %lf", &x, &y);
    }
    /********重载运算符***********/
    // 恒等
    bool operator==(const Point &b) const
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    // 比较
    bool operator<(const Point &b) const
    {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }
    bool operator>(const Point &b) const
    {
        return b < *this;
    }
    bool operator<=(const Point &b) const
    {
        return !(*this > b);
    }
    bool operator>=(const Point &b) const
    {
        return !(*this < b);
    }
    // 运算
    Point operator-(const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    Point operator+(const Point &b) const
    {
        return Point(x + b.x, y + b.y);
    }
    double distance(Point p)
    {
        return (*this - p).length();
    }
    /**************向量部分**************/
    // 叉积
    double operator^(const Point &b) const
    {
        return x * b.y - y * b.x;
    }
    // 点积
    double operator*(const Point &b) const
    {
        return x * b.x + y * b.y;
    }
    // 数乘
    Point operator*(const double &k) const
    {
        return Point(x * k, y * k);
    }
    Point operator/(const double &k) const
    {
        return Point(x / k, y / k);
    }
    // 模（长度）
    double length()
    {
        return sqrt(x * x + y * y);
    }
    // 长度平方
    double lengthPow2()
    {
        return x * x + y * y;
    }

    /*************一些常用算法***************/
    // 夹角，传入角的两边，this为顶点
    double rad(Point a, Point b)
    {
        Point &p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)), (a - p) * (b - p)));
    }
    // 向量夹角
    double rad(Point a)
    {
        Point &p = *this;
        return fabs(atan2(fabs(p ^ a), p * a));
    }

    // 化为长度为 r 的向量，可以用来求单位向量
    Point trunc(double r)
    {
        double l = length();
        if (!sgn(l))
            return *this;
        r /= l;
        return (*this) * r;
    }
};
struct Line
{
    // 使用向量表示直线
    Point s, e;
    /*****构造********/
    Line() {}
    Line(Point _s, Point _e) : s(_s), e(_e) {}

    bool operator==(Line l)
    {
        return (s == l.s) && (e == l.e);
    }
    // 点斜式，给出一个点和倾斜角
    Line(Point p, double angle)
    {
        s = p;
        if (sgn(angle - pi / 2) == 0)
            e = s + Point(0, 1);
        else
            e = s + Point(1, tan(angle));
    }
    // 一般式 ax+by+c=0
    Line(double a, double b, double c)
    {
        if (sgn(a) == 0)
            s = Point(0, -c / b), e = Point(1, -c / b);
        else if (sgn(b) == 0)
            s = Point(-c / a, 0), e = Point(-c / a, 1);
        else
            s = Point(0, -c / b), e = Point(1, (-c - a) / b);
    }
    // 输入两个点
    void input()
    {
        s.input(), e.input();
    }
    void adjust()
    {
        if (e < s)
            swap(s, e);
    }
    // 线段长度
    double length()
    {
        return s.distance(e);
    }
    // 倾斜角 [0, pi)
    double angle()
    {
        double k = atan2(e.y - s.y, e.x - s.x);
        if (sgn(k) < 0)
            k += pi;
        if (sgn(k - pi) == 0)
            k -= pi;
        return k;
    }
    // 两直线交点，注意判断直线与线段关系不能直接使用求交点，判断交点位置
    Point crossPoint(Line v)
    {
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
    // 点和直线关系
    // -1左侧 1右侧 0直线上
    int relationPoint(Point p)
    {
        int c = sgn((p - s) ^ (e - s));
        return c;
    }
    // 两直线位置关系
    // 0 重合，1 平行，-1 相交
    int relationLine(Line v)
    {
        if ((*this).parallel(v))
            if (v.relationPoint(e) == 0)
                return 0;
            else
                return 1;
        else
            return -1;
    }
    // 直线和线段关系, 传入线段
    // -1 规范相交，1 非规范相交，0 不相交
    int relationSeg(Line v)
    {
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        if ((d1 ^ d2) == -2)
            return -1;
        return (d1 == 0 || d2 == 0);
    }

    // 直线向量平行
    bool parallel(Line v)
    {
        return sgn((e - s) ^ (v.e - v.s)) == 0;
    }
    // 直线向量垂直
    bool vertical(Line v)
    {
        return sgn((e - s) * (v.e - v.s));
    }
};

struct Circle
{
    Point c;
    double r;
    Circle(){};
    Circle(Point _c, double _r)
    {
        c = _c;
        r = _r;
    }
    Circle(double x, double y, double r)
    {
        c = Point(x, y);
        r = r;
    }
    void input()
    {
        c.input();
        scanf("%lf", &r);
    }
    pair<Point, Point> circleCrossCircle(Circle p)
    {
        Line v(c, p.c);
        double vd = v.length();
        double du = acos(r * r + p.r * p.r - vd * vd) / (2 * r * vd);
        double vdu = v.angle();
        return {c + c.polar(du + vdu, r), c + c.polar(vdu - du, r)};
    }
    // 圆与圆之间的关系，-1 相交， 0 相切， 1 相离
    int relationCircle(Circle p)
    {
        return (sgn(p.r + r - c.distance(p.c)));
    }

    Point symmetryPoint(Point x)
    {
        return Point(2 * r - x.x, 2 * r - x.y);
    }
};
Circle a[maxn];
pair<Point, bool> b[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    for (int _i = 1; _i <= tcase; _i++)
    {
        double r;
        read(n, r);
        Circle c(0, 0, r);
        for (int i = 1; i <= n; i++)
        {
        }
    }
    return 0;
}