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
    vector<vector<int>> g;
    vector<int> freq;
    vector<vector<int>> dp;
    bool dfs(int u, int fa, int end)
    {
        freq[u]++;
        if (u == end)
            return true;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (v == fa)
                continue;
            if (dfs(v, u, end))
                return true;
        }
        freq[u]--;
        return false;
    }
    void dfs2(int u, int fa, vector<int> &price)
    {
        dp[u][0] = freq[u] * price[u];
        dp[u][1] = dp[u][0] >> 1;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (v == fa)
                continue;
            dfs2(v, u, price);
            dp[u][0] += min(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        g.resize(n);
        freq.resize(n);
        dp.resize(n, vector<int>(2));
        // dp[u][0] 不减半，dp[u][1] u减半
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        for (auto &trip : trips)
        {
            dfs(trip[0], -1, trip[1]);
        }
        dfs2(0, -1, price);
        return min(dp[0][0], dp[0][1]);
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
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}};
    vector<int> price = {2, 2, 10, 6};
    vector<vector<int>> trips = {{0, 3}, {2, 1}, {2, 3}};
    cout << solution.minimumTotalPrice(4, edges, price, trips) << endl;
    return 0;
}