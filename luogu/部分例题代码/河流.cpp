#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
const int inf = 1 << 30;

vector<int> adj[maxn];
int w[maxn], dis[maxn], n, K, dp[maxn][maxn][maxn];
bool onpath[maxn]; //记录所有点在不在0-当前DFS到的节点的路径上

void dfs(int u)
{
    onpath[u] = true;
    for (int i = 0; i <= n; i++)
    for (int j = 0; j <= K; j++)
    if (!onpath[i]) dp[u][i][j] = inf;
    else if (u != i || i == 0) dp[u][i][j] = (dis[u] - dis[i]) * w[u];
    else dp[u][i][j] = j ? 0 : inf;

    for (auto v: adj[u]) {
        dis[v] += dis[u]; dfs(v);
        for (int j = 0; j <= n; j++)
        {
            if (!onpath[j]) continue; //j 不是祖先，直接退出
            for (int k = K; k >= 0; k--) { //倒着枚举，否则会出问题
                dp[u][j][k] += dp[v][j][0];
                for (int l = 1; l <= k; l++) // 枚举v 子树增加的伐木场数量
                    dp[u][j][k] = min(dp[u][j][k], dp[u][j][k - l] + min(dp[v][j][l], dp[v][v][l]));
            }
        }
    }
    onpath[u] = false;
}
int main()
{
    scanf("%d %d", &n, &K);
    for (int father, i = 1; i <= n; i++)
        scanf("%d %d %d", &w[i], &father, &dis[i]), adj[father].push_back(i);
    dfs(0);
    printf("%d", dp[0][0][K]);
}