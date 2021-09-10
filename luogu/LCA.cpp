#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 500 + 10;
const int maxm = 1e5 + 10;
int n, m, k;
struct Edge
{
    int v, next;
}edge[maxn];
int head[maxn], cnt;
inline void addEdge(int u, int v)
{
    ++cnt;
    edge[cnt] = {v, head[u]};
    head[u] = cnt;
}

int fa[17][maxn], dep[maxn];

// 求出深度
void dfs(int u, int p)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v==p)continue;
        dep[v] = dep[u] + 1;
        fa[0][v] = u;
        dfs(v, u);
    }
}

void build()
{
    for(int j = 1; j <= 17; j++)
        for(int i = 1; i <= n; i++)
            fa[j][i] = fa[j - 1][fa[j - 1][i]];
}

int query(int u, int v)
{
    if(dep[u] < dep[v])
        swap(u, v);
    int tmp = dep[u] - dep[v];
    for(int i = 17; i >= 0; i--)
    {
        if(tmp >= (1<<i))
        {
            u = fa[i][u];
            tmp -= (1 << i);
        }
    }
    for(int i = 17; i >= 0; i--)
    {
        if(fa[i][u] != fa[i][v])
        {
            u = fa[i][u];
            v = fa[i][v];
        }
    }
    return fa[0][u];
}

int eulorder[maxn], cnt;

void dfs(int u, int p)
{
    eulorder[++cnt] = u;
    for (int i = head[u]; i; i=edge[i].next)
    {
        int v = edge[i].v;
        if(v == p) continue;
        dfs(v, u);
        eulorder[++cnt] = u;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    return 0;
}