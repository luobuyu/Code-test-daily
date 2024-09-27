// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
namespace FAST_IO
{
    static string buf_line;
    static int _i;
    static int _n;
    static char _ch;
    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        _ch = buf_line[_i++];
        while (_ch < '0' || _ch > '9')
        {
            if (_ch == '-')
                flag = -1;
            _ch = buf_line[_i++];
        }
        while (_ch >= '0' && _ch <= '9')
        {
            x = (x << 3) + (x << 1) + (_ch ^ 48), _ch = buf_line[_i++];
        }
        x *= flag;
        return true;
    }

    template <class T, class... _T>
    inline bool read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline bool getline()
    {
        if (!getline(cin, buf_line))
            return false;
        _i = 0, _n = buf_line.length();
        return true;
    }
    template <class T>
    inline void show(T *a, int n)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            cout << a[i];
        }
        cout << "]";
    }

    bool endofl()
    {
        if (_i >= _n)
            return true;
        if (_i == 0)
            return false;
        if (buf_line[_i - 1] == ']')
        {
            _i++;
            return true;
        }
        return false;
    }

    template <class T, std::size_t Num>
    inline void show(T a[][Num], int n, int m)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            show(a[i], m);
        }
        cout << "]";
    }

} // namespace FAST_IO
using namespace FAST_IO;

// int init = []
// {
//     /*********** fast_read ***************/
//     freopen("user.out", "w", stdout);
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     /*************************************/

//     while (true)
//     {
//         if (!getline())
//             break;

//         getline();
//     }
//     exit(0);
//     return 0;
// }();

#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();

        // 用于表示四个方向的移动（上、下、左、右）
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // BFS 队列，存储 (x, y, 当前健康值)
        queue<tuple<int, int, int>> q;
        q.push({0, 0, health});

        // 用于记录已经访问过的格子及对应健康值
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = health;

        while (!q.empty())
        {
            auto [x, y, curHealth] = q.front();
            q.pop();

            // 到达终点
            if (x == m - 1 && y == n - 1)
            {
                return curHealth > 0;
            }

            // 进行四个方向的遍历
            for (auto [dx, dy] : directions)
            {
                int newX = x + dx;
                int newY = y + dy;
                int newHealth = curHealth;

                // 检查边界条件
                if (newX < 0 || newX >= m || newY < 0 || newY >= n)
                {
                    continue;
                }

                // 如果是“不安全”区域，健康值减少
                if (grid[newX][newY] == 1)
                {
                    newHealth -= 1;
                }

                // 如果健康值不为正，无法继续
                if (newHealth <= 0)
                {
                    continue;
                }

                // 如果当前路径的健康值比之前到达这个点的健康值高，继续探索
                if (newHealth > visited[newX][newY])
                {
                    visited[newX][newY] = newHealth;
                    q.push({newX, newY, newHealth});
                }
            }
        }

        // 无法到达终点
        return false;
    }
};
int t, n, m, k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;

    return 0;
}