#include <bits/stdc++.h>

using namespace std;
const int maxn = 1000 + 10;
char a[maxn][maxn];
int n, m;
int dx[10] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[10] = {-1, 0, 1, 1, 1, 0, -1, -1};
void dfs(int x, int y)
{
    a[x][y] = '.';
    for (int i = 0; i < 8; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx >= n || newy < 0 || newy >= m || a[newx][newy] == '.')
            continue;
        dfs(newx, newy);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'W')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
