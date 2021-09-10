#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e6 + 10;
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
bool vis[maxn];
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
#endif
#endif
    t = read();
    int p;
    while (t--)
    {
        p = read();
        bool flag = true;
        memset(vis, false, sizeof(vis));
        a[1] = 1, vis[1] = true;
        int last = 1;
        for (int i = 2; i <= p - 1; i++)
        {
            int two = last * 2 % p;
            if (!vis[two])
            {
                a[i] = two;
                vis[two] = 1;
                last = two;
            }
            else
            {
                int three = last * 3 % p;
                if (!vis[three])
                {
                    a[i] = three;
                    vis[three] = true;
                    last = three;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            for (int i = 1; i <= p - 1; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}