#include <bits/stdc++.h>
#define ll long long
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

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
vector<int> g[maxn];
int s, e;
int vis[maxn];
int times = 0;
int cnt[maxn];
void dfs(int u)
{
    if(u == e)
    {
        times++;
        for(int i = 1; i <= n; i++)
        {
            cnt[i] += vis[i];
        }
        return;
    }
    for(int i = 0; i < g[u].size(); i++)
    {
        if(vis[g[u][i]] == 1) continue;
        vis[g[u][i]] = 1;
        dfs(g[u][i]);
        vis[g[u][i]] = 0;
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, m);
    for(int i = 1, u, v; i <= m; i++)
    {
        read(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[s] = 1;
    read(s, e);
    dfs(s);
    int ans = 0;
    // cout << times << endl;
    // for(int i = 1; i <= n; i++)
    // {
    //     cout << i << " " << cnt[i] << endl;
    // }
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == times && times && i != s && i != e)
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}