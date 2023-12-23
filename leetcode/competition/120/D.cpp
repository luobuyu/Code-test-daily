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
struct Node
{
    int size;
    vector<int> maxx;
    vector<int> minx;
    Node()
    {
        size = 0;
        maxx.resize(3, 0);
        minx.resize(3, 0);
    }
    long long getMul()
    {
        long long ans1 = 1;
        int cnt = 0;
        for (int i = 0; i < 3; ++i)
        {
            if (maxx[i] == 0)
                break;
            ans1 *= maxx[i];
            cnt++;
        }
        for (int i = 0; i < 3 - cnt; ++i)
        {
            ans1 *= minx[i];
        }
        long long ans2 = 1;
        ans2 = minx[0] * minx[1] * maxx[0];
        return max(ans1, ans2);
    }
};
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;

    vector<vector<int>> g;
    vector<long long> ans;
    vector<Node> tree;
    void check(Node &a, Node &b)
    {
        vector<int> tmp1;
        for (auto &x : a.maxx)
            tmp1.emplace_back(x);
        for (auto &x : b.maxx)
            tmp1.emplace_back(x);
        sort(tmp1.begin(), tmp1.end(), [](const int &x, const int &y)
             { return x > y; });
        for (int i = 0; i < 3; ++i)
        {
            a.maxx[i] = tmp1[i];
        }
        vector<int> tmp2;
        for (auto &x : a.minx)
            tmp2.emplace_back(x);
        for (auto &x : b.minx)
            tmp2.emplace_back(x);
        sort(tmp2.begin(), tmp2.end());
        for (int i = 0; i < 3; ++i)
        {
            a.minx[i] = tmp2[i];
        }
    }
    void dfs(int u, int fa, vector<int> &cost)
    {
        vector<int> maxx;
        vector<int> minx;
        for (int i = 0; i < 3; ++i)
        {
            maxx.emplace_back(tree[u].maxx[i]);
            minx.emplace_back(tree[u].minx[i]);
        }
        tree[u].size = 1;
        if (cost[u] > 0)
            tree[u].maxx[0] = cost[u];
        else
            tree[u].minx[0] = cost[u];
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (v == fa)
                continue;
            dfs(v, u, cost);
            tree[u].size += tree[v].size;
            // check(tree[u], tree[v]);
            for (auto &x : tree[v].maxx)
                maxx.emplace_back(x);
            for (auto &x : tree[v].minx)
                minx.emplace_back(x);
        }
        if (tree[u].size < 3)
            ans[u] = 1;
        else
        {
            // long long tmp = tree[u].getMul();
            // if (tmp < 0)
            //     ans[u] = 0;
            // else
            //     ans[u] = tmp;

            sort(maxx.begin(), maxx.end(), [](const int &x, const int &y)
                 { return x > y; });
            sort(minx.begin(), minx.end());
            long long tmp1 = 1;
            long long maxmul;
            int cnt = 0;
            for (int i = 0; i < 3; ++i)
            {
                if (maxx[i] == 0)
                    break;
                tmp1 *= maxx[i];
                ++cnt;
            }
            for (int i = 0; i < 3 - cnt; ++i)
            {
                tmp1 *= minx[i];
            }
            maxmul = tmp1;
            if (minx[1] != 0)
            {
                maxmul = max(maxmul, 1ll * maxx[0] * minx[0] * minx[1]);
            }
            if (maxmul < 0)
                ans[u] = 0;
            else
                ans[u] = maxmul;
        }
        for (int i = 0; i < 3; ++i)
        {
            tree[u].maxx[i] = maxx[i];
            tree[u].minx[i] = minx[i];
        }
    }
    vector<long long> placedCoins(vector<vector<int>> &edges, vector<int> &cost)
    {
        int n = cost.size();
        g.resize(n);
        ans.resize(n);
        tree.resize(n);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(0, -1, cost);
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
    vector<vector<int>> edges = {{0, 1}, {0, 2}};
    vector<int> cost = {1, 2, -2};
    solution.placedCoins(edges, cost);
    return 0;
}