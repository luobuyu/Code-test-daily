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

int cnt = 0;
int head[maxn];
struct Edge
{
    int u, v, next;
} edge[maxn];
inline void addEdge(int u, int v)
{
    ++cnt;
    edge[cnt] = {u, v, cnt};
    head[u] = cnt;
}

void dfs(int u, int fa)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == fa)
            continue;
        dfs(v, u);
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
        addEdge(v, u);
    }

    for (int i = 1; i <= n; i++)
    {
        tarjan(i);
    }

    return 0;
}