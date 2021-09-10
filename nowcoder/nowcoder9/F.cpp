#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 2e6 + 10;
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

struct Node
{
    int a, id;
    bool operator<(const Node& x) const
    {
        return a < x.a;
    }
}node[maxn];
int tot[maxn];
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
    n = read();
    m = read();
    int k;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        k = read();
        while(k--)
        {
            node[++cnt].a = read();
            node[cnt].id = i;
        }
    }
    sort(node + 1, node + 1 + cnt);
    int l = 1, r = 1;
    int p = 0;
    int ans = 1e9;
    while (r <= cnt && l <= r)
    {
        while(p < m && r <= cnt)
        {
            if(!tot[node[r].id])
            {
                p++;
            }
            tot[node[r].id]++;
            r++;
        }
        while (p == m && l <= r)
        {

            if (--tot[node[l].id] == 0)
            {
                p--;
            }
            l++;
        }
        ans = min(ans, node[r - 1].a - node[l - 1].a);
    }
    printf("%d\n", ans);
    return 0;
}