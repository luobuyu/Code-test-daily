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
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int tmp = INF;
                if (i - 1 >= 0 && j - 1 >= 0)
                    tmp = min(tmp, matrix[i - 1][j - 1]);
                if (i - 1 >= 0)
                    tmp = min(tmp, matrix[i - 1][j]);
                if (i - 1 >= 0 && j + 1 < m)
                    tmp = min(tmp, matrix[i - 1][j + 1]);
                matrix[i][j] = min(tmp + matrix[i][j], matrix[i][j]);
            }
        }
        int ans = INF;
        for (int j = 0; j < m; ++j)
        {
            ans = min(ans, matrix[n - 1][j]);
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