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
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    int n;
    int mod;
    vector<vector<pair<int, int>>> g;
    vector<int> ans;
    void dfs(int u, int fa, int dis, int &cnt)
    {
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i].first, w = g[u][i].second;
            if (v == fa)
                continue;
            int dis_v = dis + w;
            if (dis_v % mod == 0)
                cnt++;
            dfs(v, u, dis_v, cnt);
        }
    }

    void solve()
    {
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = 0; j < g[i].size(); ++j)
            {
                int v = g[i][j].first;
                int w = g[i][j].second;
                int cnt = w % mod == 0;
                dfs(v, i, w, cnt);
                ans[i] += cnt * sum;
                sum += cnt;
            }
        }
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
    {
        mod = signalSpeed;
        n = edges.size() + 1;
        g.resize(n);
        ans.resize(n);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        solve();
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
    vector<vector<int>> a = {{0, 1, 1}, {1, 2, 5}, {2, 3, 13}, {3, 4, 9}, {4, 5, 2}};
    solution.countPairsOfConnectableServers(a, 1);
    return 0;
}