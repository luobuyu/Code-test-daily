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
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int value1[maxn];
vector<int> g1[maxn], g2[maxn];

int dfn[maxn], low[maxn], dfn_clock = 0;
int st[maxn], top = -1;
bool vis[maxn];
int scc_id[maxn], value2[maxn], scc_cnt = 0;

int indeg[maxn], dp[maxn];
void tarjan(int u)
{
    dfn[u] = low[u] = ++dfn_clock;
    vis[u] = true;
    st[++top] = u;
    for (int i = 0; i < g1[u].size(); ++i)
    {
        int v = g1[u][i];
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        }
        else
        {
            if (vis[v])
                low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u])
    {
        ++scc_cnt;
        while (true)
        {
            scc_id[st[top]] = scc_cnt;
            vis[st[top]] = false;
            value2[scc_cnt] += value1[st[top]];
            if (st[top--] == u)
                break;
        }
    }
}

void topo()
{
    queue<int> q;
    for (int i = 1; i <= scc_cnt; ++i)
    {
        if (!indeg[i])
        {
            q.push(i);
            dp[i] = value2[i];
        }
    }
    while (q.size())
    {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < g2[u].size(); ++i)
        {
            int v = g2[u][i];
            dp[v] = max(dp[v], dp[u] + value2[v]);
            --indeg[v];
            if (!indeg[v])
                q.push(v);
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
    read(n, m);
    for (int i = 1; i <= n; ++i)
        read(value1[i]);
    for (int i = 1, u, v; i <= m; ++i)
    {
        read(u, v);
        g1[u].emplace_back(v);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!dfn[i])
            tarjan(i);
    }
    // 建立新图
    for (int u = 1; u <= n; ++u)
    {
        int uu = scc_id[u];
        for (int j = 0; j < g1[u].size(); ++j)
        {
            int v = g1[u][j];
            int vv = scc_id[v];
            if (uu == vv)
                continue;
            g2[uu].emplace_back(vv);
            indeg[vv]++;
        }
    }
    // topo 排序
    topo();
    int ans = 0;
    for (int i = 1; i <= scc_cnt; ++i)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}