#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int read()
{
    int x = 0, flag = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    }
    if (flag)
        return -x;
    return x;
}
int t, n, m, k;


int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    
#else
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#endif
    t = read();
    int i, j;
    while (t--)
    {
        n = read();
        for (i = 2; i <= n / 2; ++i)
            for (j = 1; j < i; ++j)
                printf("%d %d\n", j, i);
        for (i = n / 2 + 1; i < n; ++i)
            for (j = 1; j <= n - i; ++j)
                printf("%d %d\n", j, i);
        for (i = 1; i <= n / 2; ++i)
            for (j = n - i + 1; j <= n; ++j)
                printf("%d %d\n", i, j);
        for (i = n / 2 + 1; i < n; ++i)
            for (j = i + 1; j <= n; ++j)
                printf("%d %d\n", i, j);
        printf("%d----------------------\n", n);
    }
    return 0;
}