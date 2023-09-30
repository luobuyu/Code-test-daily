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
    const int INF = 0x3f3f3f3f;
    int n, k;
    int dp[maxn][21][maxn * 2 + 1];
    string s;
    int dfs(int step, int val, int diff, bool is_limit, bool is_num)
    {
        if (step == n)
            return is_num && val == 0 && diff == n;
        // 只能记忆化非限制的
        if (!is_limit && is_num && dp[step][val][diff] != -1)
            return dp[step][val][diff];
        int ans = 0;
        // is_num 表示前一位是否填了
        if (!is_num)
            ans = dfs(step + 1, val, diff, false, false);
        int up = is_limit ? s[step] - '0' : 9;
        // 前面填了，就从0开始，否则就从1开始
        for (int i = 1 - is_num; i <= up; ++i)
        {
            ans += dfs(step + 1, (val * 10 + i) % k, diff + (i & 1) * 2 - 1, is_limit && i == up, true);
        }
        if (!is_limit && is_num)
            dp[step][val][diff] = ans;
        return ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int _k)
    {
        s = to_string(high);
        n = s.length();
        k = _k;
        memset(dp, -1, sizeof(dp));
        int ans1 = dfs(0, 0, n, true, false);
        s = to_string(low);
        n = s.length();
        memset(dp, -1, sizeof(dp));
        int ans2 = dfs(0, 0, n, true, false);
        return ans1 - ans2;
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