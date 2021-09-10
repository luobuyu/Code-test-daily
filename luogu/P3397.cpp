#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 5e6 + 10;
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
int a[maxn];
int p[maxn];
struct Node
{
    int d, s, t;
}node[maxn];

bool check(int x)
{
    memset(p, 0, sizeof(p));
    for (int i = 1; i <= x; i++)
    {
        p[node[i].s] += node[i].d * 1LL;
        p[node[i].t + 1] -= node[i].d * 1LL;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += p[i];
        if(sum > a[i])
            return 0;
    }
    return 1;
}

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
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for(int i = 1; i <= m; i++)
        node[i].d = read(), node[i].s = read(), node[i].t = read();
    int l = 1, r = m;
    if(check(m))
    {
        printf("0\n");
        return 0;
    }
    else
    {
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
            {
                l = mid + 1;
                ans = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        printf("-1\n%d\n", ans + 1);

    }

    return 0;
}