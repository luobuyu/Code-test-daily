#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const string target = "tencent";
int m, n, res = 0;

void dfs(vector<vector<char>> &g, int x, int y, int i)
{
    if (i >= 6)
    {
        res++;
        return;
    }
    for (auto &dir : dirs)
    {
        int next_x = x + dir[0], next_y = y + dir[1];
        if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m)
            continue;
        if (g[next_x][next_y] != target[i + 1])
            continue;
        dfs(g, next_x, next_y, i + 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            g[i][j] = s[j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 't')
                dfs(g, i, j, 0);
        }
    }
    cout << res << endl;
}
// 64 位输出请用 printf("%lld")