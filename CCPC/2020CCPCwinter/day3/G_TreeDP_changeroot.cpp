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
const int maxn = 5e5 + 10;
const int maxm = 5e5 + 10;
int t, n, m, k;

struct Node
{
    ll u, v, w, next;
} edge[maxm << 1];
int head[maxn], cnt;
inline void addEdge(ll u, ll v, ll w)
{
    edge[++cnt] = {u, v, w, head[u]};
    head[u] = cnt;
}
ll siz[maxn]; //以1为根，x的子树中国家数量;
ll sum[maxn]; //以1为根，x的子树中到国家并返回的路径和;
ll res[maxn]; //以x为根，到所有国家并返回的路径和;

ll Fmax[maxn];  //以1为根，到子树的最大值;
ll Smax[maxn];  //以1为根，到子树的次大值;
ll neber[maxn]; //以1为根时，最大值那个节点;

ll Up[maxn]; //以1为根，x通过父亲走到国家的最大值;
ll ans[maxn];
bool flag[maxn];
// 先算出以1作为根的答案，起点到所有特殊点的所有边权加起来乘以2
void dfs1(int u, int fa)
{
    if (flag[u])
        siz[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v, w = edge[i].w;
        if (v == fa)
            continue;
        dfs1(v, u);
        siz[u] += siz[v];
        sum[u] += sum[v];
        if (siz[v])
        {
            sum[u] += 2 * w;
            if (Fmax[v] + w >= Fmax[u])
            {
                Smax[u] = Fmax[u];
                Fmax[u] = Fmax[v] + w;
                neber[u] = v;
            }
            else
            {
                Smax[u] = max(Smax[u], Fmax[v] + w);
            }
        }
    }
}

void dfs2(int u, int fa)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v, w = edge[i].w;
        if (v == fa)
            continue;
        if (k - siz[v])
        {
            if (neber[u] == v)
                Up[v] = max(Up[u], Smax[u]) + w;
            else
                Up[v] = max(Up[u], Fmax[u]) + w;
        }
        res[v] = res[u] - sum[v];
        if (siz[v])
            res[v] -= w * 2;
        res[v] += sum[v];
        if (k - siz[v])
            res[v] += 2 * w;
        dfs2(v, u);
    }
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n, k);
    ll u, v, w;
    for (int i = 1; i < n; i++)
    {
        read(u, v, w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    for (int i = 1, x; i <= k; i++)
    {
        read(x);
        flag[x] = siz[x] = 1;
    }
    dfs1(1, 0);

    res[1] = sum[1];
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        ans[i] = res[i] - max(Up[i], Fmax[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}