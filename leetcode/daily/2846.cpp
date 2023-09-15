// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
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
    const static int maxn = 1e1 + 10;
    const static int maxm = 1e1 + 10;
    const int INF = 0x3f3f3f3f;
    struct Node
    {
        int v, w;
        Node(int _v, int _w) : v(_v), w(_w) {}
    };
    // 倍增法求lca
    int preSum[maxn][27] = {};
    int fa[maxn][11] = {};
    int dep[maxn] = {};
    int log2[maxn] = {};
    vector<Node> g[maxn];
    int n, m;
    void dfs(int u, int father)
    {

        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i].v, w = g[u][i].w;
            if (v == father)
                continue;
            for (int i = 1; i <= 26; ++i)
            {
                preSum[v][i] = preSum[u][i];
            }
            fa[v][0] = u;
            preSum[v][w] += 1;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }
    void init()
    {
        // 求 fa 数组
        for (int i = 1; i <= 10; ++i)
        {
            for (int u = 0; u < n; ++u)
            {
                if (fa[u][i - 1] != -1)
                    fa[u][i] = fa[fa[u][i - 1]][i - 1];
                else
                    fa[u][i] = -1;
            }
        }
        log2[0] = log2[1] = 0;
        for (int i = 2; i <= n; ++i)
        {
            log2[i] = log2[i >> 1] + 1;
        }
    }
    int lca(int u, int v)
    {
        if (dep[u] < dep[v])
            swap(u, v);
        int tmp = dep[u] - dep[v];
        while (tmp != 0)
        {
            u = fa[u][log2[tmp]];
            tmp -= 1 << log2[tmp];
        }
        if (u == v)
            return u;
        for (int i = log2[dep[u]]; i >= 0; --i)
        {
            if (fa[u][i] != fa[v][i])
            {
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    }
    vector<int> minOperationsQueries(int _n, vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        n = _n;
        m = edges.size();
        int q = queries.size();
        for (auto &edge : edges)
        {
            // edge[0] += 1;
            // edge[1] += 1;
            g[edge[0]].emplace_back(edge[1], edge[2]);
            g[edge[1]].emplace_back(edge[0], edge[2]);
        }
        dfs(0, -1);
        init();
        vector<int> ret;
        for (auto &query : queries)
        {
            int u = query[0], v = query[1];
            int fa = lca(u, v);
            int maxx = 0, sum = 0;
            for (int i = 1; i <= 26; ++i)
            {
                int cnt = preSum[u][i] + preSum[v][i] - 2 * preSum[fa][i];
                maxx = max(maxx, cnt);
                sum += cnt;
            }
            ret.push_back(sum - maxx);
        }
        return ret;
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
    vector<vector<int>> a = {{6, 2, 1}, {5, 2, 1}, {4, 2, 2}, {7, 4, 4}, {1, 7, 4}, {0, 1, 4}, {3, 2, 2}, {8, 3, 1}};
    vector<vector<int>> q = {{6, 8}};
    solution.minOperationsQueries(7, a, q);
    return 0;
}