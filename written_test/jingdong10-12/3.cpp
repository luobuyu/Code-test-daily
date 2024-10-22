#include <bits/stdc++.h>

using namespace std;
const int maxn = 20;
const int INF = 0x3f3f3f3f;
int n, m, k, t;
char g[maxn][maxn];
int dis[maxn][maxn];
unordered_set<int> vis_len;
void dfs(int x, int y, int d)
{
    // 向右
    dis[x][y] = min(dis[x][y], d);
    for (int j = y + 1; j < m; ++j)
    {
        int dis = j - y;
        if (g[x][j] == '*' && (dis == 1 || !vis_len.count(dis)))
        {
            vis_len.insert(dis);
            dfs(x, j, d + 1);
            vis_len.erase(dis);
        }
    }
    for (int i = x + 1; i < n; ++i)
    {
        int dis = i - x;
        if (g[i][y] == '*' && (dis == 1 || !vis_len.count(dis)))
        {
            vis_len.insert(dis);
            dfs(i, y, d + 1);
            vis_len.erase(dis);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("./int.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> g[i];
    }
    memset(dis, 0x3f, sizeof(dis));
    dfs(0, 0, 0);
    if (dis[n - 1][m - 1] < INF)
    {
        cout << dis[n - 1][m - 1];
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}