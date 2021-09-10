#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
const int maxn = 1e4 + 10;
struct vec
{
    double x, y;
    vec(const double &x0 = 0, const double &y0 = 0) : x(x0), y(y0) {}
    vec operator+(const vec &t) const { return vec(x + t.x, y + t.y); }
    vec operator-(const vec &t) const { return vec(x - t.x, y - t.y); }
    vec operator*(const double &t) const { return vec(x * t, y * t); }
    vec operator/(const double &t) const { return vec(x / t, y / t); }
    const double len2() const { return x * x + y * y; }
    const double len() const { return sqrt(len2()); }
    vec norm() const { return *this / len(); }
    vec rotate_90_c() { return vec(y, -x); }
};

double dot(const vec &a, const vec &b) { return a.x * b.x + a.y * b.y; }
double crs(const vec &a, const vec &b) { return a.x * b.y - a.y * b.x; }

vec lin_lin_int(const vec &p0, const vec &v0, const vec &p1, const vec &v1)
{
    double t = crs(p1 - p0, v1) / crs(v0, v1);
    return p0 + v0 * t;
}

vec circle(const vec &a, const vec &b, const vec &c)
{
    return lin_lin_int((a + b) / 2, (b - a).rotate_90_c(), (a + c) / 2, (c - a).rotate_90_c());
}

int n;
vec pot[maxn];

double solve(vec pot[])
{
    random_shuffle(pot + 1, pot + n + 1);
    vec o;
    double r2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((pot[i] - o).len2() > r2)
        {
            o = pot[i], r2 = 0;
            for (int j = 1; j < i; j++)
            {
                if ((pot[j] - o).len2() > r2)
                {
                    o = (pot[i] + pot[j]) / 2, r2 = (pot[j] - o).len2();
                    for (int k = 1; k < j; k++)
                    {
                        if ((pot[k] - o).len2() > r2)
                        {
                            o = circle(pot[i], pot[j], pot[k]), r2 = (pot[k] - o).len2();
                        }
                    }
                }
            }
        }
    }
    return sqrt(r2);
}
struct Node
{
    double a, b, c;
} node[maxn];
int main()
{
    // #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf%lf", &node[i].a, &node[i].b, &node[i].c);
    for (int i = 1; i <= n; i++)
    {
        pot[i].x = node[i].a;
        pot[i].y = node[i].b;
    }
    double ans = 1e9;
    ans = min(ans, solve(pot));
    for (int i = 1; i <= n; i++)
    {
        pot[i].x = node[i].a;
        pot[i].y = node[i].c;
    }
    ans = min(ans, solve(pot));
    for (int i = 1; i <= n; i++)
    {
        pot[i].x = node[i].b;
        pot[i].y = node[i].c;
    }
    ans = min(ans, solve(pot));
    printf("%.10lf\n", ans * 2);
    return 0;
}