// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll long long
#define PII pair<int, int>
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

auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
    bool check(int mid, vector<vector<int>> &grid)
    {
        if (grid[0][0] <= mid)
            return false;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        q.push({0, mid});
        vis[0][0] = true;
        while (q.size())
        {
            auto out = q.front();
            q.pop();
            int x = out.first / m;
            int y = out.first % m;
            int dis = out.second;
            if (x == n - 1 && y == m - 1)
                return true;
            for (int i = 0; i < 4; ++i)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx == n - 1 && newy == m - 1 && grid[newx][newy] >= dis + 1)
                    return true;
                if (newx < 0 || newx >= n || newy < 0 || newy >= m || grid[newx][newy] <= 0 ||
                    grid[newx][newy] <= dis + 1 || vis[newx][newy])
                    continue;
                q.push({newx * m + newy, dis + 1});
                vis[newx][newy] = true;
            }
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 2)
                    grid[i][j] = -2;
                if (grid[i][j] == 0)
                    grid[i][j] = INF;
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (q.size())
        {
            auto out = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                int newx = out.first + dx[i];
                int newy = out.second + dy[i];
                if (newx < 0 || newx >= n || newy < 0 || newy >= m || grid[newx][newy] <= 0 || grid[newx][newy] != INF)
                    continue;
                grid[newx][newy] = min(grid[newx][newy], grid[out.first][out.second] + 1);
                q.push({newx, newy});
            }
        }
        int l = 0, r = m * n, ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid, grid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans == m * n ? 1e9 : ans;
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
    vector<vector<int>> a = {{0, 2, 0, 0, 0, 0, 0}, {0, 0, 0, 2, 2, 1, 0}, {0, 2, 0, 0, 1, 2, 0}, {0, 0, 2, 2, 2, 0, 2}, {0, 0, 0, 0, 0, 0, 0}};
    cout << solution.maximumMinutes(a) << endl;
    return 0;
}