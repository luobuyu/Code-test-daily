#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
const int inf = 1 << 30;
typedef long long ll;

vector<int> adj[maxn];
int sz[maxn]; //u内部的点数
ll sum1[maxn]; //u内部的距离和
ll sum2[maxn]; //u外部的距离和
int n, ans;
void dfs(int u, int fa)
{
    sz[u] = 1;
    for (auto v: adj[u])
    if (v != fa)
        dfs(v, u), sz[u] += sz[v], sum1[u] += sz[v] + sum1[v];
}
void dfs2(int u, int fa)
{
    for (auto v: adj[u])
    if (v != fa)
        sum2[v] = sum2[u] + (sum1[u] - sum1[v] - sz[v]) + (n - sz[v]), dfs2(v, u);
    if (sum1[u] + sum2[u] > sum1[ans] + sum2[ans]) ans = u;
}
int main()
{
    scanf("%d", &n);
    for (int u, v, i = 1; i < n; i++)
        scanf("%d %d", &u, &v), adj[u].push_back(v), adj[v].push_back(u);
    ans = 1; dfs(1, 0); dfs2(1, 0);
    printf("%d", ans);
}