// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
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
const double eps = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
vector<pair<int, int>> g[maxn];
int ans = INF;
int dfn[maxn], low[maxn], dfn_clock = 0;
int cnt;
void init()
{
    dfn_clock = 0;
    cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
        dfn[i] = low[i] = 0;
    }
    ans = INF;
}

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++dfn_clock;
    ++cnt;
    int times = 0;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if (v == fa && !times)
        {
            ++times;
            continue;
        }
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
            {
                ans = min(ans, w);
            }
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (read(n, m), n && m)
    {
        init();
        for (int i = 1, u, v, w; i <= m; ++i)
        {
            read(u, v, w);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        tarjan(1, 0);

        if (cnt != n)
            cout << 0 << endl;
        else if (ans == 0)
            cout << 1 << endl;
        else if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}