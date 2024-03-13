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
    vector<int> dis;
    vector<int> cnt;
    vector<vector<pair<int, int>>> g;
    vector<bool> vis;
    int countPaths(int n, vector<vector<int>> &roads)
    {
        g.resize(n);
        vis.resize(n);

        cnt.resize(n);
        dis.resize(n, INF);
        for (auto &edge : roads)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        priority_queue<pair<int, int>> q; // -dis, node
        q.push({0, 0});
        dis[0] = 0;
        cnt[0] = 1;
        while (q.size())
        {
            auto out = q.top();
            q.pop();
            int u = out.second;
            if (vis[u])
                continue;
            vis[u] = true;
            if (u == n - 1)
                break;
            for (int i = 0; i < g[u].size(); ++i)
            {
                int v = g[u][i].first, w = g[u][i].second;
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u];
                    q.push({-dis[v], v});
                }
                else if (dis[v] == dis[u] + w)
                {
                    cnt[v] = (cnt[v] + cnt[u]) % mod;
                }
            }
        }
        cout << dis[n - 1] << ", " << cnt[n - 1] << endl;
        return cnt[n - 1];
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
    vector<vector<int>> a = {{0, 2, 2}, {0, 1, 1}, {1, 2, 1}};
    solution.countPaths(3, a);
    return 0;
}