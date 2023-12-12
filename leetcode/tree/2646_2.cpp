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
    vector<vector<int>> fa;
    vector<int> freq;
    vector<vector<int>> dp;
    vector<int> dep;
    vector<int> log2;
    void dfs(int u, int fa)
    {
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (v == fa)
                continue;
            dep[v] = dep[u] + 1;
            this->fa[v][0] = u;
            dfs(v, u);
        }
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
    void dfs3(int u, int fa)
    {
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (v == fa)
                continue;
            dfs3(v, u);
            freq[u] += freq[v];
        }
    }
    int query(int x, int y)
    {
        if (dep[x] < dep[y])
            swap(x, y);
        int tmp = dep[x] - dep[y];
        while (dep[x] != dep[y])
        {
            x = fa[x][log2[tmp]];
            tmp -= (1 << log2[tmp]);
        }
        if (x == y)
            return x;
        for (int i = log2[dep[x]]; i >= 0; --i)
        {
            if (fa[x][i] != fa[y][i])
            {
                x = fa[x][i];
                y = fa[y][i];
            }
        }
        return fa[x][0];
    }
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        g.resize(n);
        freq.resize(n);
        dep.resize(n);
        dp.resize(n, vector<int>(2));
        fa.resize(n, vector<int>(7));
        log2.resize(n + 1);
        // dp[u][0] 不减半，dp[u][1] u减半
        for (int i = 2; i <= n; ++i)
            log2[i] = log2[i >> 1] + 1;
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(0, -1);
        for (int i = 1; i <= 6; ++i)
        {
            for (int u = 0; u < n; ++u)
            {
                fa[u][i] = fa[fa[u][i - 1]][i - 1];
            }
        }
        for (auto &trip : trips)
        {
            cout << trip[0] << ", " << trip[1] << ", ";
            int lca = query(trip[0], trip[1]);
            cout << lca << endl;
            freq[trip[0]]++;
            freq[trip[1]]++;
            freq[lca]--;
            if (fa[lca][0] != lca)
                freq[fa[lca][0]]--;
        }
        dfs3(0, -1);
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
    vector<vector<int>> edges = {{3, 14}, {7, 14}, {8, 12}, {10, 12}, {11, 1}, {12, 13}, {13, 2}, {2, 4}, {4, 6}, {6, 5}, {5, 1}, {1, 9}, {9, 0}, {0, 14}};
    vector<int> price = {126, 128, 48, 6, 154, 78, 16, 36, 44, 84, 38, 56, 136, 116, 140};
    vector<vector<int>> trips = {{9, 12}, {14, 1}, {8, 8}, {5, 12}, {4, 1}, {4, 12}, {14, 5}, {2, 10}, {0, 12}, {4, 14}, {5, 1}, {12, 12}, {12, 10}, {14, 14}, {5, 10}, {4, 6}, {8, 14}, {0, 6}, {11, 7}, {10, 6}, {6, 11}, {8, 4}, {14, 12}, {12, 7}, {1, 2}, {4, 7}, {12, 6}, {12, 12}, {6, 2}, {10, 9}, {1, 2}, {11, 12}, {0, 14}, {9, 11}, {13, 6}, {5, 9}, {0, 2}, {1, 0}, {8, 0}, {4, 6}, {0, 7}, {2, 12}, {3, 11}, {9, 9}, {6, 6}, {10, 11}, {12, 8}, {11, 6}, {6, 10}, {8, 0}, {4, 2}, {7, 10}, {11, 3}, {3, 8}, {4, 9}, {1, 7}, {9, 1}, {4, 9}, {2, 11}, {12, 5}, {1, 8}, {10, 10}, {5, 6}, {1, 2}, {10, 11}, {3, 1}, {1, 0}, {12, 1}, {6, 8}, {0, 9}, {4, 2}, {11, 4}, {9, 6}, {7, 5}, {9, 4}, {12, 10}, {8, 7}, {7, 8}, {14, 14}, {7, 7}, {10, 9}, {14, 10}, {10, 2}, {11, 9}, {13, 1}, {0, 4}, {9, 9}, {4, 12}, {4, 1}, {10, 2}, {5, 3}, {9, 12}, {4, 11}, {7, 7}, {14, 8}, {0, 6}, {12, 7}, {0, 7}};
    cout << solution.minimumTotalPrice(15, edges, price, trips) << endl;
    return 0;
}