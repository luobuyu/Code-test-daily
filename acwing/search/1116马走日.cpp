#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 20;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool vis[maxn][maxn];
int n, m, x, y;
int ans = 0;
void dfs(int x, int y, int cnt)
{
    if (cnt == n * m)
    {
        ans++;
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx >= n || newy < 0 || newy >= m)
            continue;
        if (vis[newx][newy])
            continue;
        dfs(newx, newy, cnt + 1);
    }
    vis[x][y] = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tcase;
    cin >> tcase;
    while (tcase--)
    {
        ans = 0;
        cin >> n >> m >> x >> y;
        dfs(x, y, 1);
        cout << ans << endl;
    }

    return 0;
}