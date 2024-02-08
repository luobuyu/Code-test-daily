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
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> g;
    vector<int> node;
    vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
    bool check(int mid)
    {
        int n = g.size();
        queue<pair<int, int>> q;
        // 打标记
        for (auto &x : node)
            q.push({x, 0});
        while (q.size())
        {
            auto out = q.front();
            q.pop();
            if (out.second >= mid)
                continue;
            int x = out.first / n;
            int y = out.first % n;

            for (int i = 0; i < 4; ++i)
            {
                int newx = x + dx[i], newy = y + dy[i];
                if (newx < 0 || newx >= n || newy < 0 || newy >= n || g[newx][newy] == 1)
                    continue;
                q.push({newx * n + newy, out.second + 1});
                g[newx][newy] = 1;
            }
        }
        if (g[0][0] == 1 || g[n - 1][n - 1] == 1)
            return false;
        q.push({0, 0});
        g[0][0] = 2;
        while (q.size())
        {
            auto out = q.front();
            q.pop();
            if (out.first == n * n - 1)
                return true;
            int x = out.first / n;
            int y = out.first % n;
            for (int i = 0; i < 4; ++i)
            {
                int newx = x + dx[i], newy = y + dy[i];
                if (newx < 0 || newx >= n || newy < 0 || newy >= n || g[newx][newy] != 0)
                    continue;
                q.push({newx * n + newy, 0});
                g[newx][newy] = 2;
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int l = 0, r = n;
        int ans = 0;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    node.emplace_back(i * n + j);
            }
        }
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            g = grid;
            if (check(mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans + 1;
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
    vector<vector<int>> a = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
    solution.maximumSafenessFactor(a);
    return 0;
}