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
    const static int maxn = 1e2 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    string s;
    int len;
    long long dp[maxn][10];
    int dfs(int step, int pre, bool isLimit, bool isLead)
    {
        if (step == len)
            return !isLead;
        if (!isLimit && !isLead && dp[step][pre] != -1)
            return dp[step][pre];
        long long ans = 0;
        if (isLead)
            ans += dfs(step + 1, 0, false, true);
        int up = isLimit ? s[step] - '0' : 9;
        for (int i = isLead; i <= up; ++i)
        {
            if (!isLead && abs(i - pre) != 1)
                continue;
            ans = (ans + dfs(step + 1, i, isLimit && (i == up), false)) % mod;
        }
        if (!isLimit && !isLead)
        {
            dp[step][pre] = ans;
        }
        return ans;
    }
    int solve(string high)
    {
        memset(dp, -1, sizeof(dp));
        s = high;
        len = s.length();
        return dfs(0, 0, true, true);
    }
    int countSteppingNumbers(string low, string high)
    {
        int ret2 = solve(high);
        int ret1 = solve(low);
        bool flag = true;
        for (int i = 1; i < low.length(); ++i)
        {
            if (abs(low[i] - low[i - 1]) != 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ret1--;
        cout << ret2 << endl;
        cout << ret1 << endl;
        return (ret2 - ret1 + mod) % mod;
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
    solution.countSteppingNumbers("1", "11");
    return 0;
}