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
const int maxn = 1e3 + 10;
const int maxm = 1e6 + 10;
int t, n, m, k;

int fa[maxn], dfn[maxn], pre[maxn], tp[maxn], match[maxn], tim;
queue<int> q;

struct Edge
{
    int v, next;
} edge[maxm << 1];
int head[maxn], cnt;
bool vis[maxn];
inline void addEdge(int u, int v)
{
    ++cnt;
    edge[cnt] = {v, head[u]};
    head[u] = cnt;
}
int findFa(int u)
{
    return fa[u] == u ? u : (fa[u] = findFa(fa[u]));
}
int getLca(int x, int y)
{
    tim++;
    x = findFa(x);
    y = findFa(y);
    while (dfn[x] != tim)
    {
        dfn[x] = tim;
        x = findFa(pre[match[x]]);
        if (y)
            swap(x, y);
    }
    return x;
}
void blossom(int x, int y, int lca)
{
    while (findFa(x) != lca)
    {
        pre[x] = y;
        y = match[x];
        if (tp[y] == 2)
        {
            tp[y] = 1;
            q.push(y);
        }
        if (findFa(x) == x)
            fa[x] = lca;
        if (findFa(y) == y)
            fa[y] = lca;
        x = pre[y];
    }
}
bool bfs(int s)
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    memset(pre, 0, sizeof(pre));
    memset(tp, 0, sizeof(tp));
    while (!q.empty())
        q.pop();
    tp[s] = 1; // 标记类型
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].v;
            if (findFa(v) == findFa(u) || tp[v] == 2)
                continue;
            if (!tp[v]) // 未标记的
            {
                pre[v] = u;
                tp[v] = 2;
                if (!match[v]) // 未匹配，记为匹配
                {
                    for (int now = v, last; now != 0; now = last)
                    {
                        last = match[pre[now]];
                        match[now] = pre[now];
                        match[pre[now]] = now;
                    }
                    return true;
                }
                tp[match[v]] = 1, q.push(match[v]);
            }
            else // 标记的（找过了，环）
            {
                int lca = getLca(u, v);
                blossom(u, v, lca);
                blossom(v, u, lca);
            }
        }
    }
    return false;
}
int a[maxn][maxn];
string s[maxn];

int notequal(string a, string b)
{
    int ret = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
            ret++;
    }
    return ret;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (notequal(s[i], s[j]) == 2)
            {
                a[i][j] = a[j][i] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && a[i][j] == 1)
            {
                addEdge(i, j);
                addEdge(j, i);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (!match[i])
            ans += bfs(i);
    printf("%d\n", n - ans);

    return 0;
}