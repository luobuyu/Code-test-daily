#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 10;
int n, m, q, k;
char g[maxn][maxn];
char str[maxn] = "tencent";
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int len = 7;
int ans = 0;
void dfs(int index, int x, int y)
{
    if(index == len)
        ans++;
    for (int i = 0; i < 4; ++i)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx < 0 || newx >= n || newy < 0 || newy >= m || g[newx][newy] != str[index]) continue;
        dfs(index + 1, newx, newy);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> g[i];
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(g[i][j] == 't')  {
                dfs(1, i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}