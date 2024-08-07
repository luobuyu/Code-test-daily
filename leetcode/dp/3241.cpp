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
    vector<vector<int>> dp; // dp[u][0] 子树最大值，dp[u][1] 子树次大值
    vector<vector<int>> g;
    vector<int> ans;
    vector<int> max_v;
    int dfs(int u, int fa)
    {
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (v == fa)
                continue;
            int dep = dfs(v, u) + (v % 2 ? 1 : 2);
            if (dep > dp[u][0])
            {
                max_v[u] = v;
                dp[u][1] = dp[u][0];
                dp[u][0] = dep;
            }
            else if (dep > dp[u][1])
                dp[u][1] = dep;
        }
        return dp[u][0];
    }
    void dfs2(int u, int fa)
    {
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            int w = (u % 2 ? 1 : 2);
            if (v == fa)
                continue;
            int up = 0;
            if (v == max_v[u])
            { // v 是 u 的最大子树上的。
                // 考虑父节点次大子树，与当前节点最大子树
                up = dp[u][1] + w;
            }
            else
            {
                // v 不是最大子树，考虑父节点最大子树，子节点最大子树
                up = dp[u][0] + w;
            }
            if (up > dp[v][0])
            {
                dp[v][1] = dp[v][0];
                dp[v][0] = up;
                max_v[v] = u;
            }
            else if (up > dp[v][1])
            {
                dp[v][1] = up;
            }
            ans[v] = dp[v][0];
            dfs2(v, u);
        }
    }
    vector<int> timeTaken(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        dp.resize(n, vector<int>(2));
        g.resize(n);
        ans.resize(n);
        max_v.resize(n);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(0, -1);
        ans[0] = dp[0][0];
        dfs2(0, -1);
        return ans;
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
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<vector<int>> edges = {{0, 1}, {0, 2}};
    solution.timeTaken(edges);
    return 0;
}