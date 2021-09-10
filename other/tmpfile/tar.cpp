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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

int head[maxn], cnt;
struct Edge
{
    int u, v, next;
} edge[maxm << 1];

inline void addEdge(int u, int v)
{
    cnt++;
    edge[cnt] = {u, v, head[u]};
    head[u] = cnt;
}
int dfn[maxn], dfn_clock, low[maxn], scc[maxn], scc_cnt;
stack<int> sta;
void tarjan(int u)
{
    low[u] = dfn[u] = ++dfn_clock;
    sta.push(u);
    for (int i = head[u], v; i; i = edge[i].next)
    {
        v = edge[i].v;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            if (!scc[v])
            {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    if (low[u] == dfn[u])
    {
        scc_cnt++;
        for (;;)
        {
            int x = sta.top();
            sta.pop();
            scc[x] = scc_cnt;
            if (x == u)
                break;
        }
    }
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, m);
    for (int i = 1, u, v; i <= m; i++)
    {
        read(u, v);
        addEdge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\t%d\n", i, scc[i]);
    }
    return 0;
}