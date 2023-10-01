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
    vector<vector<int>> g, rg;
    vector<int> vis; // 0, 1, 2未访问，正在访问，访问过
    vector<int> ans;
    vector<int> dfn;
    int dfn_clock = 0;
    vector<int> st;
    int top = -1;
    // dfs 找环
    void dfs(int u)
    {
        vis[u] = 1;
        dfn[u] = ++dfn_clock;
        st[++top] = u;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (vis[v] == 1)
            {
                int size = dfn[u] - dfn[v] + 1;
                while (true)
                {
                    ans[st[top]] = size;
                    if (st[top] == v)
                        break;
                    --top;
                }
            }
            else if (vis[v] == 0)
            {
                dfs(v);
            }
        }
        vis[u] = 2;
    }
    int dfs2(int u)
    {
        if (ans[u])
            return ans[u];
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            ans[u] = dfs2(v) + 1;
        }
        return ans[u];
    }
    vector<int> countVisitedNodes(vector<int> &edges)
    {
        int n = edges.size();
        g.resize(n);
        dfn.resize(n), ans.resize(n);
        vis.resize(n);
        st.resize(n);
        for (int i = 0; i < n; ++i)
        {
            int u = i, v = edges[i];
            g[u].emplace_back(v);
        }
        for (int i = 0; i < n; ++i)
        {
            if (!dfn[i])
                dfs(i);
        }
        for (int i = 0; i < n; ++i)
        {
            if (!ans[i])
                dfs2(i);
        }
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
    vector<int> a = {8, 17, 14, 8, 14, 12, 16, 11, 4, 14, 19, 6, 8, 8, 2, 10, 2, 1, 1, 18};
    vector<int> b = {3, 6, 1, 0, 5, 7, 4, 3};
    vector<int> c = {1, 2, 3, 4, 0};
    solution.countVisitedNodes(b);
    return 0;
}