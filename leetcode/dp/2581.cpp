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
    vector<int> ans;
    unordered_set<long long> s;
    bool count(long long u, long long v)
    {
        return s.count((u << 32) | v);
    }
    void insert(long long u, long long v)
    {
        s.insert((u << 32) | v);
    }

    void dfs1(int u, int fa)
    {
        // unordered_set<int> son;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (v == fa)
                continue;
            if (count(u, v))
                ++ans[0];
            dfs1(v, u);
        }
    }
    void dfs2(int u, int fa)
    {
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (v == fa)
                continue;
            ans[v] = ans[u];
            if (count(u, v))
                ans[v]--;
            if (count(v, u))
                ans[v]++;
            dfs2(v, u);
        }
    }
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses, int k)
    {
        int n = edges.size() + 1;
        g.resize(n);
        ans.resize(n);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        for (auto &edge : guesses)
        {
            int u = edge[0], v = edge[1];
            insert(u, v);
        }
        // 先假设 0 为根，遍历一遍，找到几个为 true 的
        dfs1(0, -1);
        dfs2(0, -1);
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (ans[i] >= k)
                ++cnt;
        }
        return cnt;
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
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {4, 2}};
    vector<vector<int>> guesses = {{1, 3}, {0, 1}, {1, 0}, {2, 4}};
    solution.rootCount(edges, guesses, 3);
    return 0;
}