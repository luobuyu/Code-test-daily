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

int init = []
{
    /*********** fast_read ***************/
    freopen("in.txt", "r", stdin);
    freopen("user.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*************************************/
    const static int maxn = 2e4 + 1;
    const static int maxm = 1e5 + 1;
    int deg[maxn] = {};
    int id[maxn];
    int cnts[maxm * 2] = {};
    unordered_map<int, int> mp;
    int n, m, k, u, v, max_deg;
    int queries[21];
    while (true)
    {
        if (!getline())
            break;
        read(n);
        getline();
        for (m = 0; !endofl(); ++m)
        {
            read(u, v);
            u--;
            v--;
            deg[u]++;
            deg[v]++;
            if (u > v)
                swap(u, v);
            mp[u * n + v]++;
            endofl();
        }
        getline();
        for (k = 0; !endofl(); ++k)
        {
            read(queries[k]);
        }
        max_deg = 0;
        unordered_map<int, int> freq_deg;
        for (int i = 0; i < n; ++i)
        {
            freq_deg[deg[i]]++;
            max_deg = max(max_deg, deg[i]);
        }
        // 计算cnts[deg[u] + deg[v]]次数
        int cnts_size = max_deg * 2 + 1;
        for (auto &kv1 : freq_deg)
        {
            for (auto &kv2 : freq_deg)
            {
                if (kv1.first > kv2.first)
                    continue;
                if (kv1.first == kv2.first)
                {
                    cnts[kv1.first * 2] += kv1.second * (kv1.second - 1) / 2;
                }
                else
                {
                    cnts[kv1.first + kv2.first] += kv1.second * kv2.second;
                }
            }
        }
        // 去掉重边
        for (auto &kv : mp)
        {
            int u = kv.first / n;
            int v = kv.first % n;
            int tot = deg[u] + deg[v];
            cnts[tot]--;
            cnts[tot - kv.second]++;
        }
        // cnts 后缀和
        for (int i = cnts_size - 1; i >= 0; --i)
        {
            cnts[i] += cnts[i + 1];
        }
        cout << "[";
        for (int i = 0; i < k; ++i)
        {
            int &q = queries[i];
            if (q + 1 < cnts_size)
            {
                q = cnts[q + 1];
            }
            else
                q = 0;
            if (i == 0)
                cout << q;
            else
                cout << "," << q;
        }
        cout << "]\n";
    }
    exit(0);
    return 0;
}();

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
    const static int maxn = 2e1 + 1;
    const static int maxm = 1e5 + 1;
    int deg[maxn] = {};
    int id[maxn];
    int cnts[maxm * 2] = {};
    unordered_map<int, int> mp;
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        int m = edges.size();
        int max_deg = 0;
        for (int i = 0, u, v; i < m; ++i)
        {
            u = edges[i][0] - 1;
            v = edges[i][1] - 1;
            deg[u]++;
            deg[v]++;
            if (u > v)
                swap(u, v);
            mp[u * n + v]++;
        }
        unordered_map<int, int> freq_deg;
        for (int i = 0; i < n; ++i)
        {
            freq_deg[deg[i]]++;
            max_deg = max(max_deg, deg[i]);
        }
        // 计算cnts[deg[u] + deg[v]]次数
        int cnts_size = max_deg * 2 + 1;
        for (auto &kv1 : freq_deg)
        {
            for (auto &kv2 : freq_deg)
            {
                if (kv1.first > kv2.first)
                    continue;
                if (kv1.first == kv2.first)
                {
                    cnts[kv1.first * 2] += kv1.second * (kv1.second - 1) / 2;
                }
                else
                {
                    cnts[kv1.first + kv2.first] += kv1.second * kv2.second;
                }
            }
        }
        // 去掉重边
        for (auto &kv : mp)
        {
            int u = kv.first / n;
            int v = kv.first % n;
            int tot = deg[u] + deg[v];
            cnts[tot]--;
            cnts[tot - kv.second]++;
        }
        // cnts 后缀和
        for (int i = cnts_size - 1; i >= 0; --i)
        {
            cnts[i] += cnts[i + 1];
        }
        for (auto &q : queries)
        {
            if (q + 1 < cnts_size)
            {
                q = cnts[q + 1];
            }
            else
                q = 0;
        }

        return queries;
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
    n = 4;
    vector<vector<int>> edges = {{1, 2}, {2, 4}, {1, 3}, {2, 3}, {2, 1}};
    vector<int> queries = {2, 3};
    solution.countPairs(n, edges, queries);
    return 0;
}