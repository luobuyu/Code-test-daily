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
    n = 30;
    printf("   ");
    for (int i = 1; i <= n; i++)
    {
        printf("%2d ", i);
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%2d ", i);
        for (int j = 1; j <= n; j++)
        {
            if (__gcd(i, j) > 1)
            {
                printf("%2d ", 1);
            }
            else
            {
                printf("%2d ", 0);
            }
        }
        printf("\n");
    }
    return 0;
}