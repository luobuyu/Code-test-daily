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
    vector<int> indeg;
    vector<int> ans;
    void dfs(int u, vector<int> &ring)
    {
        ring.emplace_back(u);
        indeg[u] = -1;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (indeg[v] == 1)
                dfs(v, ring);
        }
    }
    void dfs2(int u)
    {
        for (int i = 0; i < rg[u].size(); ++i)
        {
            int v = rg[u][i];
            if (indeg[v] == 0)
            {
                ans[v] = ans[u] + 1;
                dfs2(v);
            }
        }
    }
    vector<int> countVisitedNodes(vector<int> &edges)
    {
        int n = edges.size();
        g.resize(n), rg.resize(n);
        indeg.resize(n), ans.resize(n);
        for (int i = 0; i < n; ++i)
        {
            int u = i, v = edges[i];
            g[u].emplace_back(v);
            rg[v].emplace_back(u);
            indeg[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (indeg[i] == 0)
                q.push(i);
        }
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < g[u].size(); ++i)
            {
                int v = g[u][i];
                indeg[v]--;
                if (indeg[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (indeg[i] == 1) // 环上的点
            {
                vector<int> ring;
                dfs(i, ring);
                int size = ring.size();
                for (auto &u : ring)
                {
                    ans[u] = size;
                    dfs2(u);
                }
            }
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
    vector<int> c = {1, 2, 0, 0};
    solution.countVisitedNodes(c);
    return 0;
}