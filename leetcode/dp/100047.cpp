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
    const static int maxn = 1e1 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    vector<int> g[maxn];
    int dp[maxn][2];
    bool notPrime[maxn]; // true 不是素数，false是素数
    int prime[maxn];
    int cnt;
    long long ans;
    void sieve(int n)
    {
        cnt = 0;
        notPrime[1] = true;
        for (int i = 2; i <= n; ++i)
        {
            if (!notPrime[i])
                prime[++cnt] = i;
            for (int j = 1; j <= cnt && prime[j] * i <= n; ++j)
            {
                notPrime[prime[j] * i] = true;
                if (i % prime[j] == 0)
                    break;
            }
        }
    }
    void dfs(int u, int fa)
    {
        if (notPrime[u] == false) // 素数
        {
            dp[u][1] = 1;
            dp[u][0] = 0;
        }
        else
        {
            dp[u][0] = 1;
            dp[u][1] = 0;
        }
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (v == fa)
                continue;
            dfs(v, u);
            ans += dp[u][0] * dp[v][1];
            ans += dp[u][1] * dp[v][0];
            if (notPrime[u] == false) // 素数
            {
                dp[u][1] += dp[v][0];
            }
            else
            {
                dp[u][0] += dp[v][0];
                dp[u][1] += dp[v][1];
            }
        }
    }
    long long countPaths(int n, vector<vector<int>> &edges)
    {
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        memset(notPrime, false, sizeof(notPrime));
        sieve(n);
        dfs(1, 0);
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
    vector<vector<int>> a = {{1, 2}, {1, 3}, {2, 4}, {2, 5}};
    solution.countPaths(5, a);
    return 0;
}