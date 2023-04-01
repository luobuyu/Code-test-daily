#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0;
    char ch = getchar();
    bool f = 1;
    for (; ch > '9' || ch < '0'; ch = getchar())
        if (ch == '-')
            f = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? x : -x;
}
int n, m, N;
int k;
int dir[4][4] = {
    {0, 1, 2, 3},
    {0, 3, 2, 1},
    {2, 3, 0, 1},
    {2, 1, 0, 3}};
int Type[4][4] = {
    {1, 0, 0, 3},
    {0, 2, 1, 1},
    {2, 1, 3, 2},
    {3, 3, 2, 0}};
int main()
{
    n = read();
    m = read();
    N = n * n;
    while ((N >> k & 1) == 0)
        ++k;
    //cout << ceil(1.l * n / m);
    int now = N >> 2, type = 0;
    int l = 1, r = n, u = n, d = 1;
    while (now)
    {
        int t = (int)ceil(1.l * m / now) - 1;
        switch (dir[type][t])
        {
        case 0:
            r = l + r >> 1;
            u = u + d >> 1;
            type = Type[type][0];
            break;
        case 1:
            r = l + r >> 1;
            d = (u + d >> 1) + 1;
            type = Type[type][1];
            break;
        case 2:
            l = (l + r >> 1) + 1;
            d = (u + d >> 1) + 1;
            type = Type[type][2];
            break;
        case 3:
            l = (l + r >> 1) + 1;
            u = (u + d >> 1);
            type = Type[type][3];
        }
        m -= now * t;
        now >>= 2;
    }
    printf("%d %d", l, d);
    return 0;
}