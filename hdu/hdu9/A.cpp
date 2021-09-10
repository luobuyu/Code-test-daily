#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e6 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
vector<int> g[maxn];
int size[maxn];
ll ans;
void dfs1(int u)
{
    size[u] = 1;
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        dfs1(v);
        size[u] += size[v];
    }
}

void dfs2(int u, ll k)
{
    ans = max(ans, k);
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        dfs2(v, k + n - size[v]);
    }
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

    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n);
        int x;
        for(int i = 0; i <= n; i++)
        {
            g[i].clear();
        }
        for (int i = 2; i <= n; i++)
        {
            read(x);
            g[x].push_back(i);
        }

        ans = 0;
        dfs1(1);
        dfs2(1, 0);
        for (int i = 1; i <= n; i++)
        {
            ans += size[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}