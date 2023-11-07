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
    long long ans = 0;
    vector<vector<int>> g;
    vector<int> values;
    vector<vector<long long>> dp;
    // dp[u][0] 表示子树健康， dp[u][1] 子树不健康，所有的都选了。
    int n;
    void dfs(int u, int fa)
    {
        dp[u][0] = 0;
        dp[u][1] = 0;
        long long tmp1 = 0;
        long long tmp2 = 0;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (v == fa)
                continue;
            dfs(v, u);
            tmp1 += dp[v][1];
            tmp2 += dp[v][0];
        }
        if (g[u].size() == 1 && u != 0)
        {
            dp[u][0] = 0;
            dp[u][1] = values[u];
        }
        else
        {
            dp[u][0] = max(tmp1, tmp2 + values[u]);
            dp[u][1] = tmp1 + values[u];
        }
    }
    long long maximumScoreAfterOperations(vector<vector<int>> &edges, vector<int> &_values)
    {
        n = edges.size() + 1;
        values = _values;
        g.resize(n);
        dp.resize(n, vector<long long>(2));
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(0, -1);
        // for (int i = 0; i < n; ++i)
        // {
        //     cout << dp[i][0] << ", " << dp[i][1];
        // }
        return dp[0][0];
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
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}};
    vector<int> values = {20, 10, 9, 7, 4, 3, 5};
    solution.maximumScoreAfterOperations(edges, values);
    return 0;
}