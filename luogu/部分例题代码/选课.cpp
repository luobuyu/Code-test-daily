#include <bits/stdc++.h>

using namespace std;

const int maxn = 405;

vector<int> adj[maxn];
int s[maxn], n, m, dp[maxn][maxn];

void dfs(int u)
{
    for (int j = 1; j <= m; j++) dp[u][j] = s[u];
    for (auto v: adj[u]) {
        dfs(v);
        for (int j = m; j >= 1; j--) // 注意倒着枚举
        for (int k = 0; k < j; k++)
            dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
    }
}
int main()
{
    scanf("%d %d", &n, &m); ++m;
    for (int father, i = 1; i <= n; i++)
        scanf("%d %d", &father, &s[i]), adj[father].push_back(i);
    dfs(0);
    printf("%d", dp[0][m]);
}