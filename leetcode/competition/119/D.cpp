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

class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> oldg;
    vector<vector<int>> g;
    void close(int id, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            if (!((id >> i) & 1))
            {
                for (int j = 0; j < n; ++j)
                {
                    g[i][j] = INF;
                    g[j][i] = INF;
                }
            }
        }
    }
    bool check(int id, int maxDistance, int n)
    {
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (!((id >> i) & 1))
                continue;
            for (int j = 0; j < n; ++j)
            {
                if (!((id >> j) & 1))
                    continue;
                if (g[i][j] > maxDistance)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads)
    {
        g.resize(n, vector<int>(n, INF));
        oldg.resize(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i)
        {
            oldg[i][i] = 0;
        }
        for (auto &road : roads)
        {
            int u = road[0], v = road[1], w = road[2];
            oldg[u][v] = oldg[v][u] = min(oldg[u][v], w);
        }
        int upper = (1 << n) - 1;
        int ans = 0;
        for (int i = upper; i >= 0; --i)
        {
            g = oldg;
            close(i, n);
            bool ret = check(i, maxDistance, n);
            ans += ret;
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
    vector<vector<int>> a = {{2, 0, 6}, {1, 2, 28}, {0, 1, 18}, {0, 3, 10}};
    cout << solution.numberOfSets(4, 17, a) << endl;
    return 0;
}