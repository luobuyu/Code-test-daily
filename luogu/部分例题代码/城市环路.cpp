#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;
const int inf = 1 << 30;
typedef long long ll;

vector<int> adj[maxn];
int dp[maxn][2], par[maxn], p[maxn];
bool onRing[maxn], vis[maxn];
int Ring[maxn], tot;
int f[maxn][2][2], n;

void findRing(int u)
{
    vis[u] = true;
    for (auto v: adj[u])
    if (v != par[u]) {
        if (!vis[v]) par[v] = u, findRing(v);
        else if (!onRing[u]) {
            onRing[v] = true; Ring[++tot] = v;
            for (int t = u; t != v; t = par[t])
                onRing[t] = true, Ring[++tot] = t;
        }
    }
}
void dfs(int u)
{
    dp[u][1] = p[u]; dp[u][0] = 0;
    for (auto v: adj[u])
    if (!onRing[v] && v != par[u])
        dfs(v), dp[u][1] += dp[v][0], dp[u][0] += max(dp[v][0], dp[v][1]);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    for (int u, v, i = 1; i <= n; i++)
        scanf("%d %d", &u, &v), adj[u].push_back(v), adj[v].push_back(u);
    findRing(0); 
    for (int i = 0; i < n; i++)
        if (onRing[i]) dfs(i);

    f[1][0][0] = dp[Ring[1]][0];
    f[1][1][1] = dp[Ring[1]][1];
    for (int i = 2; i <= tot; i++)
    for (int j = 0; j <= 1; j++)
        f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1]) + dp[Ring[i]][0],
        f[i][j][1] = dp[Ring[i]][1] + f[i - 1][j][0]; 

    double k; cin >> k;
    printf("%.1lf", k * max(f[tot][0][1], max(f[tot][1][0], f[tot][0][0])));
}