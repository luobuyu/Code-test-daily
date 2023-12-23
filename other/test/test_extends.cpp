// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
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
int t, n, m, k;

struct Point_2
{
private:
    double xx, yy;

public:
    Point_2() {}
    Point_2(double _x, double _y) : xx(_x), yy(_y) {}

    Point_2 operator-(const Point_2 &p) const
    {
        return Point_2(xx - p.x(), yy - p.y());
    }
    Point_2 operator+(const Point_2 &p) const
    {
        return Point_2(xx + p.x(), yy + p.y());
    }
    Point_2 operator/(const double &k) const
    {
        return Point_2(xx / k, yy / k);
    }
    Point_2 operator*(const double &k) const
    {
        return Point_2(xx * k, yy * k);
    }
    double x() const
    {
        return xx;
    }
    double y() const
    {
        return yy;
    }
};

struct Segment_2
{
private:
    Point_2 start, end;

public:
    Segment_2() {}
    Segment_2(Point_2 _start, Point_2 _end) : start(_start), end(_end) {}
    Point_2 source()
    {
        return start;
    }
    Point_2 target()
    {
        return end;
    }
};

struct Vector_2 : public Point_2
{
    Vector_2(int _x, int _y)
    {
    }
};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Vector_2 v1(1, 1), v2(0, 1);
    Point_2 p1(1, 1), p2(0, 1);

    return 0;
}