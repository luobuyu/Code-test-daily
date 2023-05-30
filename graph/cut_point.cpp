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
int **adj;
int *deg;
struct UF
{
    vector<int> fa;
    int count;
    UF() {}
    UF(int n) : fa(n), count(n)
    {
        for (int i = 0; i < n; ++i)
            fa[i] = i;
    }
    void init(int n)
    {
        fa.resize(n);
        count = n;
        for (int i = 0; i < n; ++i)
            fa[i] = i;
    }
    // int find(int u)
    // {
    //     if (u == fa[u])
    //     {
    //         return u;
    //     }
    //     else
    //     {
    //         return fa[u] = find(fa[u]);
    //     }
    //     // cout << u << ", " << fa[u] << endl;
    //     // return u == fa[u] ? u : fa[u] = find(fa[u]);
    // }

    int find(int u)
    {
        int root = u;
        while (fa[root] != root)
        {
            root = fa[root];
        }
        int tmp;
        while (u != root)
        {
            tmp = fa[u];
            fa[u] = root;
            u = tmp;
        }
        return root;
    }

    void unite(int u, int v)
    {
        int up = find(u), vp = find(v);
        if (up != vp)
        {
            fa[up] = vp;
            count--;
        }
    }
    bool connect(int u, int v) { return find(u) == find(v); }
    int getCount() { return count; }
};
struct Edge
{
    int u, v;
};
Edge *edges;

int *dfn, *low, dfn_clock;
bool *is_cut;
UF uf;
void read_instance()
{
    read(n, n, m);
    edges = new Edge[m]();
    adj = new int *[n]();
    deg = new int[n]();
    for (int i = 0, u, v; i < m; ++i)
    {
        read(u, v);
        // u--;
        // v--;
        edges[i] = {u, v};
        deg[u]++;
        deg[v]++;
    }
    for (int i = 0; i < n; ++i)
        adj[i] = new int[deg[i]]();
    int *tmp = new int[n]();
    for (int i = 0, u, v; i < m; ++i)
    {
        u = edges[i].u;
        v = edges[i].v;
        adj[u][tmp[u]++] = v;
        adj[v][tmp[v]++] = u;
    }
    delete[] tmp;

    dfn = new int[n]();
    low = new int[n]();
    is_cut = new bool[n]();
    dfn_clock = 0;
}

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++dfn_clock;
    int cnt = 0;
    for (int i = 0, v; i < deg[u]; ++i)
    {
        v = adj[u][i];
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (u != fa && low[v] >= dfn[u])
                is_cut[u] = true;
            ++cnt;
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (u == fa && cnt >= 2)
        is_cut[u] = true;
}

void dfs(int u, int fa)
{
    for (int i = 0; i < deg[u]; ++i)
    {
        int v = adj[u][i];
        if (v == fa)
            continue;
        if (is_cut[v])
        {
            uf.unite(u, v);
            dfs(v, u);
        }
    }
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("./socfb-Indiana.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    read_instance();
    for (int i = 0; i < n; ++i)
    {
        if (!dfn[i])
        {
            tarjan(i, i);
        }
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        if (is_cut[i])
        {
            ++cnt;
            ans.emplace_back(i);
        }
    }
    uf.init(n);
    for (auto &u : ans)
    {
        dfs(u, -1);
    }
    int connect = 0;
    for (int i = 0; i < n; ++i)
    {
        if (is_cut[i] && (uf.find(i) == i))
        {
            connect++;
        }
    }
    cout << cnt << endl;
    cout << connect << endl;
    return 0;
}