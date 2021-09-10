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
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m1, m2, k;

ll a[maxn << 2][maxn << 2];
struct TwoSeg
{
    ll MAX[maxn << 2][maxn << 2];
    ll MIN[maxn << 2][maxn << 2];
    ll minv, maxv;
    void push_upx(int deep, int rt)
    {
        MAX[deep][rt] = max(MAX[deep << 1][rt], MAX[deep << 1 | 1][rt]);
        // MIN[deep][rt] = min(MIN[deep << 1][rt], MIN[deep << 1 | 1][rt]);
    }
    void push_upy(int deep, int rt)
    {
        MAX[deep][rt] = max(MAX[deep][rt << 1], MAX[deep][rt << 1 | 1]);
        // MIN[deep][rt] = min(MIN[deep][rt << 1], MIN[deep][rt << 1 | 1]);
    }
    void buildy(int ly, int ry, int deep, int rt, int flag)
    {
        //y轴范围ly,ry;deep,rt;标记flag
        if (ly == ry)
        {
            if (flag != -1)
                MAX[deep][rt] = a[flag][ly];
            else
                push_upx(deep, rt);
            return;
        }
        int m = (ly + ry) >> 1;
        buildy(ly, m, deep, rt << 1, flag);
        buildy(m + 1, ry, deep, rt << 1 | 1, flag);
        push_upy(deep, rt);
    }
    void buildx(int lx, int rx, int deep)
    {
        //建树x轴范围lx,rx;deep
        if (lx == rx)
        {
            buildy(1, n, deep, 1, lx);
            return;
        }
        int m = (lx + rx) >> 1;
        buildx(lx, m, deep << 1);
        buildx(m + 1, rx, deep << 1 | 1);
        buildy(1, n, deep, 1, -1);
    }
    void updatey(int Y, int val, int ly, int ry, int deep, int rt, int flag)
    {
        //单点更新y坐标;更新值val;当前操作y的范围ly,ry;deep,rt;标记flag
        if (ly == ry)
        {
            if (flag)
                MAX[deep][rt] = MIN[deep][rt] = val;
            else
                push_upx(deep, rt);
            return;
        }
        int m = (ly + ry) >> 1;
        if (Y <= m)
            updatey(Y, val, ly, m, deep, rt << 1, flag);
        else
            updatey(Y, val, m + 1, ry, deep, rt << 1 | 1, flag);
        push_upy(deep, rt);
    }
    void updatex(int X, int Y, int val, int lx, int rx, int deep)
    {
        //单点更新范围x,y;更新值val;当前操作x的范围lx,rx;deep
        if (lx == rx)
        {
            updatey(Y, val, 1, n, deep, 1, 1);
            return;
        }
        int m = (lx + rx) >> 1;
        if (X <= m)
            updatex(X, Y, val, lx, m, deep << 1);
        else
            updatex(X, Y, val, m + 1, rx, deep << 1 | 1);
        updatey(Y, val, 1, n, deep, 1, 0);
    }
    void queryy(int Yl, int Yr, int ly, int ry, int deep, int rt)
    {
        //询问区间y轴范围y1,y2;当前操作y的范围ly,ry;deep,rt
        if (Yl <= ly && ry <= Yr)
        {
            // minv = min(MIN[deep][rt], minv);
            maxv = max(MAX[deep][rt], maxv);
            return;
        }
        int m = (ly + ry) >> 1;
        if (Yl <= m)
            queryy(Yl, Yr, ly, m, deep, rt << 1);
        if (m < Yr)
            queryy(Yl, Yr, m + 1, ry, deep, rt << 1 | 1);
    }
    void queryx(int Xl, int Xr, int Yl, int Yr, int lx, int rx, int rt)
    {
        //询问区间范围x1,x2,y1,y2;当前操作x的范围lx,rx;rt
        if (Xl <= lx && rx <= Xr)
        {
            queryy(Yl, Yr, 1, n, rt, 1);
            return;
        }
        int m = (lx + rx) >> 1;
        if (Xl <= m)
            queryx(Xl, Xr, Yl, Yr, lx, m, rt << 1);
        if (m < Xr)
            queryx(Xl, Xr, Yl, Yr, m + 1, rx, rt << 1 | 1);
    }
} seg;

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int x1, y1, x2, y2, k;
    read(n, m1, m2);
    for (int i = 1; i <= m1; i++)
    {
        read(x1, y1, x2, y2, k);
        a[x1][y1] += k;
        a[x1][y2 + 1] -= k;
        a[x2 + 1][y1] -= k;
        a[x2 + 1][y2 + 1] += k;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    seg.buildx(1, n, 1);
    while (m2--)
    {
        read(x1, y1, x2, y2);
        seg.maxv = -1;
        seg.queryx(x1, x2, y1, y2, 1, n, 1);
        printf("%lld\n", seg.maxv);
    }
    return 0;
}