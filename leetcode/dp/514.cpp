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

    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        char ch = buf_line[_i++];
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = buf_line[_i++];
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = buf_line[_i++];
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

    int dp[100000][2] = {};
    int v, ans;
    string s;
    for (; getline();)
    {
        for (int i = 0; read(v); ++i)
        {
            if (i == 0)
            {
                dp[0][0] = v;
                dp[0][1] = 0;
                ans = v;
            }
            else
            {
                dp[i][0] = max(dp[i - 1][0] + v, v);
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + v);
                ans = max(ans, max(dp[i][0], dp[i][1]));
            }
        }
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
    const static int maxn = 1e2 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int dp[maxn][maxn] = {};
    vector<vector<int>> pos;
    int findRotateSteps(string ring, string key)
    {
        pos.resize(26);
        int n = key.size(), m = ring.size();
        for (int i = 0; i < m; ++i)
            pos[ring[i] - 'a'].emplace_back(i);
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < pos[key[0] - 'a'].size(); ++i)
        {
            int j = pos[key[0] - 'a'][i];
            dp[0][j] = min(j, m - j) + 1;
        }
        if (n == 1)
            return dp[0][pos[key[0] - 'a'][0]];
        int ans = INF;
        for (int i = 1; i < n; ++i)
        {
            for (auto &j : pos[key[i] - 'a'])
            {
                for (auto &k : pos[key[i - 1] - 'a'])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), m - abs(j - k)) + 1);
                }
                if (i == n - 1)
                    ans = min(ans, dp[i][j]);
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

    return 0;
}