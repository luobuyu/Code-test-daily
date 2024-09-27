#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int n, m, q, k;
char a[maxn];
char b[maxn][maxn];
const int INF = 0x3f3f3f3f;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void dfs(int x, int y, char aim, int n, int m)
{
    b[x][y] = '.';
    for (int i = 0; i < 4; ++i)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx < 0 || newx >= n || newy < 0 || newy >= m || b[newx][newy] == '.' || b[newx][newy] != aim) continue;
        dfs(newx, newy, aim, n, m);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    cin >> a;
    int ans = INF;
    for (int i = 1; i <= n; ++i)
    {
        if(n % i != 0) continue;
        // 行数是 i
        int size = n / i;
        for (int j = 0; j < n; ++j)
        {
            b[j / size][j % size] = a[j];
        }
        int cnt = 0;
        for (int r = 0; r < i; ++r)
        {
            for (int c = 0; c < size; ++c)
            {
                if(b[r][c] != '.')
                {
                    dfs(r, c, b[r][c], i, size);
                    ++cnt;
                }
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}