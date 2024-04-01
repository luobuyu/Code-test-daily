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
    const long long mod = 1e9 + 7;
    // solve <= num, digit <= max_sum
    // step 遍历到第几位，sum数位和，isLimit当前位是否受到上界限制，isLead是否存在前导零
    string low, high;
    int n;
    long long dp[23][220];
    int minx, maxx;
    int len;
    long long dfs(int step, int val, bool isLower, bool isUpper, bool isLead)
    {
        if (step == len)
            return val >= minx && val <= maxx;
        if (!isLower && !isUpper && !isLead && dp[step][val] != -1)
            return dp[step][val];
        long long ans = 0;
        if (isLead && low[step] == '0')
            ans = (ans + dfs(step + 1, val, true, false, true)) % mod;
        int lo = isLower ? low[step] - '0' : 0;
        int hi = isUpper ? high[step] - '0' : 9;
        for (int i = max((int)isLead, lo); i <= hi; ++i)
        {
            if (val + i > maxx)
                continue;
            ans = (ans + dfs(step + 1, val + i, isLower && i == lo, isUpper && i == hi, false)) % mod;
        }
        if (!isLower && !isUpper && !isLead)
            dp[step][val] = ans;
        return ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        minx = min_sum;
        maxx = max_sum;
        high = num2;
        len = high.length();
        low = string(num2.length() - num1.length(), '0') + num1;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, true, true, true);
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
    cout << solution.count("1", "12", 1, 8) << endl;
    return 0;
}