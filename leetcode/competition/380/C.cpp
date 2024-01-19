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
    long long dp[64];
    long long x;
    string s;
    int n;
    // 从高位到低位
    long long dfs(int step, int maxx, long long val, bool is_limit, bool is_lead)
    {
        if (step == maxx)
        {
            if (!is_limit)
                return val * pow(2ll, x - 1);
            else
                return val *
        }
        // 只能记忆化非限制的
        if (!is_limit && !is_lead && dp[step] != -1)
            return dp[step];
        long long ans = 0;
        // is_lead 表示前一位是否填了
        if (is_lead)
            ans = dfs(step + 1, maxx, val, false, true);
        int up = is_limit ? s[step] - '0' : 1;
        // 前面填了，就从0开始，否则就从1开始
        for (int i = is_lead; i <= up; ++i)
        {
            ans += dfs(step + 1, maxx, val + (i == 1), is_limit && i == s[step] - '0', false);
        }
        if (!is_limit && !is_lead)
            dp[step] = ans;
        return ans;
    }
    bool check(long long mid, long long k, int x)
    {
        s.clear();
        while (mid)
        {
            if (mid & 1)
                s.push_back('1');
            else
                s.push_back('0');
            mid >>= 1;
        }
        string tmp;
        while (x)
        {
            if (x & 1)
                tmp.push_back('1');
            else
                tmp.push_back('0');
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        if (s.length() < x)
        {
            return 0 <= k;
        }
        memset(dp, -1, sizeof(dp));
        n = s.length();
        long long ret = dfs(0, n - tmp.length() + 1, 0, true, true);
        cout << ret << endl;
        return ret <= k;
    }
    long long findMaximumNumber(long long k, int x)
    {
        long long l = 1, r = (1ll << 10) - 1;
        l = r = 9;
        int ans = 0;
        while (l <= r)
        {
            long long mid = l + ((r - l) >> 1);
            if (check(mid, k, x))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
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
    solution.findMaximumNumber(7, 2);
    return 0;
}