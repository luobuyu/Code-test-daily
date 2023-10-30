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
// class Solution
// {
// public:
//     const static int maxn = 1e5 + 10;
//     const static int maxm = 1e5 + 10;
//     const int INF = 0x3f3f3f3f;
//     vector<vector<int>> g;
//     vector<vector<int>> dp;
//     int dfs(int u, int fa, int upper, vector<int> &coins, int k)
//     {
//         dp[u][0] = min(coins[u], upper) - k;
//         dp[u][1] = min(coins[u], upper);
//         int ret = 0;
//         for (int i = 0; i < g[u].size(); ++i)
//         {
//             int v = g[u][i];
//             if (v == fa)
//                 continue;
//             dp[u][0] += dfs(v, u, INF, coins, k);
//             dp[u][1] += dfs(v, u, floor(coins[u] / 2), coins, k);
//         }
//         return max(dp[u][0], dp[u][1]);
//     }
//     int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k)
//     {
//         int n = coins.size();
//         g.resize(n);
//         dp.resize(n, vector<int>(2));
//         for (auto &edge : edges)
//         {
//             int u = edge[0];
//             int v = edge[1];
//             g[u].emplace_back(v);
//             g[v].emplace_back(u);
//         }
//         for (int i = 0; i < n; ++i)
//         {
//             cout << dp[i][0] << ", " << dp[i][1] << endl;
//         }
//         int ret = dfs(0, -1, INF, coins, k);
//         return max(dp[0][0], dp[0][1]);
//     }
// };
class Solution
{
public:
    vector<vector<int>> memo; // -1 表示没有计算过
    int dfs(int i, int j, int fa, int k, vector<int> &coins, vector<vector<int>> &g)
    {
        auto &res = memo[i][j]; // 注意这里是引用
        if (res != -1)
        { // 之前计算过
            return res;
        }
        int res1 = (coins[i] >> j) - k;
        int res2 = coins[i] >> (j + 1);
        for (int ch : g[i])
        {
            if (ch == fa)
                continue;
            res1 += dfs(ch, j, i, k, coins, g); // 不右移
            if (j < 13)
            {                                           // j+1 >= 14 相当于 res2 += 0，无需递归
                res2 += dfs(ch, j + 1, i, k, coins, g); // 右移
            }
        }
        return res = max(res1, res2); // 记忆化
    }
    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k)
    {
        int n = coins.size();
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        memo.resize(n, vector<int>(14, -1));
        return dfs(0, 0, -1, k, coins, g);
    }
};

int t,
    n,
    m,
    k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<vector<int>> a = {{0, 1}, {0, 2}, {0, 4}, {2, 3}};
    vector<int> b = {5, 6, 8, 7, 4};
    cout << solution.maximumPoints(a, b, 7) << endl;
    return 0;
}