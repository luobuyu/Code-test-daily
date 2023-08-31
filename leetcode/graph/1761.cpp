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
    freopen("user.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*************************************/
    const static int maxn = 400;
    int deg[maxn];
    pair<int, int> edges[maxn * maxn << 1];
    bool s[maxn][maxn];
    int u, v, w, n, m;
    int id[maxn];
    while (true)
    {
        if (!getline())
            break;
        read(n);
        getline();
        memset(s, false, sizeof(s));
        memset(deg, 0, sizeof(deg));
        for (m = 0; !endofl(); ++m)
        {
            read(u, v);
            u--;
            v--;
            edges[m] = {u, v};
            ++deg[u];
            ++deg[v];
            s[u][v] = s[v][u] = true;
            endofl();
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
            id[i] = i;
        sort(id, id + n, [&](const int &u, const int &v)
             { return deg[u] < deg[v]; });
        for (int i = 0; i < n; ++i)
        {
            u = id[i];
            if (deg[u] * 3 >= ans)
                break;
            for (int j = i + 1; j < n; ++j)
            {
                v = id[j];
                if (deg[u] + deg[v] * 2 >= ans)
                    break;
                for (int k = j + 1; k < n; ++k)
                {
                    w = id[k];
                    if (deg[u] + deg[v] + deg[w] >= ans)
                        break;
                    if (s[u][v] && s[u][w] && s[v][w])
                    {
                        ans = min(ans, deg[u] + deg[v] + deg[w]);
                    }
                }
            }
        }
        if (ans == INT_MAX)
            ans = -1;
        else
            ans -= 6;
        cout << ans << endl;
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
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;

    int minTrioDegree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> s(n, vector<int>(n, false));
        vector<int> deg(n);
        int u, v, w;
        for (auto &edge : edges)
        {
            u = edge[0] - 1;
            v = edge[1] - 1;
            deg[u]++;
            deg[v]++;
            s[u][v] = true;
            s[v][u] = true;
        }
        int ans = INT_MAX;
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](const int &u, const int &v)
             { return deg[u] < deg[v]; });
        for (int i = 0; i < n; ++i)
        {
            u = id[i];
            if (deg[u] * 3 >= ans)
                break;
            for (int j = i + 1; j < n; ++j)
            {
                v = id[j];
                if (deg[u] + deg[v] * 2 >= ans)
                    break;
                for (int k = j + 1; k < n; ++k)
                {
                    w = id[k];
                    if (deg[u] + deg[v] + deg[w] >= ans)
                        break;
                    if (s[u][v] && s[u][w] && s[v][w])
                    {
                        ans = min(ans, deg[u] + deg[v] + deg[w]);
                    }
                }
            }
        }
        if (ans == INT_MAX)
            ans = -1;
        else
            ans -= 6;
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

    return 0;
}