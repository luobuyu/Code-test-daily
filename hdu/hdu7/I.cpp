#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e5 + 10;
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
int x, y;
int a[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#endif
    t = read();
    while (t--)
    {
        n = read(), x = read(), y = read();
        if( n * 1LL >= 1LL * x * y + 1LL || n < x + y - 1)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        int cur = n;
        for (int i = n - y + 1; i <= n; i++)
        {
            a[i] = cur--;
        }
        // 需要放 cur 个数，总共有 x-1块
        int index = n - y;
        for (int i = x - 1; i >= 1; i--)
        {
            int len = min(cur - (i - 1), y);
            for (int j = index - len + 1; j <= index; j++)
            {
                a[j] = cur--;
            }
            index -= len;
        }

        for(int i = 1; i <= n; i++)
        {
            printf("%d%c", a[i], " \n"[i==n]);
        }
        
    }
    return 0;
}