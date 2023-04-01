#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = nextChar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = nextChar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = nextChar();
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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int n, m, k;
int t[maxn];
int head[maxn], cnt;
struct Edge
{
    int u, v, w, next;
} edge[maxn];

inline void addEdge(int u, int v, int w)
{
    edge[++cnt] = {u, v, w, head[u]};
    head[u] = cnt;
}

ll a[maxn], b[maxn], ans[maxn];
ll sum[maxn], siz[maxn];
ll SUM;
void dfs1(int u, int fa)
{
    sum[u] = t[u];
    siz[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v, w = edge[i].w;
        if (v == fa)
            continue;
        dfs1(v, u);
        sum[u] += sum[v];
        siz[u] += siz[v];
        a[u] += a[v] + 1ll * w * siz[v];
        b[u] += b[v] + 1ll * w * sum[v];
    }
}

void dfs2(int u, int fa)
{
    ans[u] = b[u] + a[u] * t[u];
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v, w = edge[i].w;
        if (v == fa)
            continue;
        a[v] += 1ll * w * (n - siz[v]) + a[u] - a[v];
        b[v] += 1ll * w * (SUM - sum[v]) + b[u] - b[v];
        b[v] -= 1ll * w * sum[v];
        a[v] -= 1ll * w * siz[v];
        dfs2(v, u);
    }
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(t[i]);
    }
    for (int i = 1, u, v, w; i < n; i++)
    {
        read(u, v, w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    dfs1(1, 0);
    SUM = sum[1];
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}