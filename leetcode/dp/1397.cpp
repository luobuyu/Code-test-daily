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
    const int mod = 1e9 + 7;
    int dp[500];
    string s;
    int len;
    int dfs(int step, string cur, bool isLimit, bool isLead)
    {
        if (step == len)
            return !isLead;
        if (!isLimit && !isLead && dp[step] != -1)
            return dp[step];
        int up = isLimit ? s[step] : 'z';
        int ans = 0;
        if (isLead)
            ans = (ans + dfs(step + 1, cur, false, true)) % mod;
        for (int i = 'a'; i <= up; ++i)
        {
            if ()
                cur.push_back(i);
            ans = (ans + dfs(step + 1, cur, isLimit && i == up, false)) % mod;
            cur.pop_back();
        }
        ans %= mod;
        if (!isLimit && !isLead)
            dp[step] = ans;
        return ans;
    }
    int solve(string upper)
    {
        memset(dp, -1, sizeof(dp));
        s = upper;
        len = s.length();
        return dfs(0, "", true, true) - 1;
    }
    int findGoodStrings(int n, string s1, string s2, string evil)
    {
        int ret2 = solve(s2);
        int ret1 = solve(s1);
        bool flag = true;
        ret1 -= flag;
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
    cout << solution.findGoodStrings(2, "aa", "da", "b") << endl;
    return 0;
}