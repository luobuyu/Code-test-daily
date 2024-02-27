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

vector<bool> notPrime;
vector<int> prime;
auto seive = [](int maxx)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    notPrime.resize(maxx + 1);
    notPrime[0] = notPrime[1] = true;
    for (int i = 2; i <= maxx; ++i)
    {
        if (!notPrime[i])
            prime.emplace_back(i);
        for (int j = 0; j < prime.size() && prime[j] * i <= maxx; ++j)
        {
            notPrime[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    return 0;
}(1e5);
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    vector<vector<int>> g;
    vector<vector<int>> dp; // dp[u][0]表示以u为终点不包含素数的路径条数，dp[u][1]表示以u为终点包含素数的路径条数。
    long long ans = 0;
    void dfs(int u, int fa)
    {
        if (!notPrime[u])
            dp[u][1] = 1;
        else
            dp[u][0] = 1;
        for (int i = 0; i < g[u].size(); ++i)
        {
            int v = g[u][i];
            if (v == fa)
                continue;
            dfs(v, u);
            ans += dp[u][0] * dp[v][1];
            ans += dp[u][1] * dp[v][0];
            if (!notPrime[u])
            {
                dp[u][1] += dp[v][0];
            }
            else
            {
                // u 不是素数
                dp[u][0] += dp[v][0];
                dp[u][1] += dp[v][1];
            }
        }
    }
    long long countPaths(int n, vector<vector<int>> &edges)
    {
        g.resize(n + 1);
        dp.resize(n + 1, vector<int>(2));
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
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
    for (int i = 0; i < 10; ++i)
    {
        cout << prime[i] << endl;
    }
    return 0;
}