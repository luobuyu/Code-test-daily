#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 5e5 + 5;
const ll inf = 1ll << 50;

struct edge{
    int v, w;
};
vector<edge> adj[maxn];
vector<edge> tmp[maxn]; //记录虚数的节点

int par[maxn][20], dep[maxn], minw[maxn][20], dfn[maxn], idx;
int seq[maxn], flag[maxn], tim, n, m, k;
ll dp[maxn][2];
//par[u][j] 表示 u 的2^j 祖先， minw[u][j] 表示 u-par[u][j]路径上的最小值
//dfn[u] 记录 u 在 dfs 序的位置，idx 是全局标记
//seq 记录虚树上的节点，flag[u] = tim表示 u 是当前询问中的资源点

void dfs(int u)
{
    dfn[u] = ++idx; //dfs序
    for (int j = 1; j < 20; j++)
        par[u][j] = par[par[u][j - 1]][j - 1],
        minw[u][j] = min(minw[u][j - 1], minw[par[u][j - 1]][j - 1]);
    for (auto e: adj[u])
    if (e.v != par[u][0])
        dep[e.v] = dep[u] + 1, par[e.v][0] = u, minw[e.v][0] = e.w, dfs(e.v);
}

int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    for (int d = dep[u] - dep[v], k = 0; d; d >>= 1, ++k)
        if (d & 1) u = par[u][k];
    if (u == v) return u;
    for (int j = 19; j >= 0; j--)
    if (par[u][j] != par[v][j])
        u = par[u][j], v = par[v][j];
    return par[u][0];
}
int minedge(int u, int v) //返回 u 到 祖先 v 路径上的最小边
{
    int ans = 1 << 30;
    for (int d = dep[u] - dep[v], k = 0; d; d >>= 1, ++k)
        if (d & 1) ans = min(ans, minw[u][k]), u = par[u][k];
    return ans;
}
bool cmp(int x, int y) {return dfn[x] < dfn[y];}

void solve(int u)
{
    dp[u][0] = (flag[u] == tim ? inf : 0);
    dp[u][1] = 0;
    for (auto e : tmp[u]) {
        solve(e.v);
        if (dp[u][0] != inf)
            dp[u][0] += min(dp[e.v][0], dp[e.v][1] + e.w);
        dp[u][1] += min(dp[e.v][0], dp[e.v][1]);
    }
}
int main()
{
    scanf("%d", &n);
    for (int u, v, w, i = 1; i < n; i++)
        scanf("%d %d %d", &u, &v, &w),
        adj[u].push_back((edge){v, w}),
        adj[v].push_back((edge){u, w});
    
    dfs(1);

    scanf("%d", &m);
    while (m--) {
        /* 清零上一次的数组 */
        for (int i = 1; i <= k; i++) tmp[seq[i]].clear();

        scanf("%d", &k); ++tim; //全局标记
        for (int i = 1; i <= k; i++)
            scanf("%d", &seq[i]), flag[seq[i]] = tim;
        sort(seq + 1, seq + k + 1, cmp); // 按照dfs序排序
        for (int i = k; i > 1; i--) //之所以倒着写，是为了省事
            seq[++k] = lca(seq[i], seq[i - 1]);
        seq[++k] = 1; // 确保根在虚树中
        sort(seq + 1, seq + k + 1, cmp); // 按照dfs序排序
        k = unique(seq + 1, seq + k + 1) - seq - 1; // 去重
        for (int i = 2; i <= k; i++)
        {
            int father = lca(seq[i - 1], seq[i]); //seq[i] 在虚树上的 father 一定是 lca..
            tmp[father].push_back((edge){seq[i], minedge(seq[i], father)});
        }
        solve(1);
        printf("%lld\n", dp[1][0]);
    }
}