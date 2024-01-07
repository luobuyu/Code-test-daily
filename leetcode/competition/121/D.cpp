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
    // state针对不同的问题设置状态，可能有多个状态
    // is_limit 表示是否收到上界的限制
    // is_lead 表示是否存在前导零

    string s;
    int n;
    long long dp[20];
    int limit;

    long long dfs(int step, bool is_limit, bool is_lead)
    {
        if (step == n)
            return !is_lead;
        // 只能记忆化非限制的，无限制，无前导零
        if (!is_limit && !is_lead && dp[step] != -1)
            return dp[step];
        long long ans = 0;
        // 存在前导零的情况下可以跳过该位
        if (is_lead)
            ans = dfs(step + 1, false, true);
        int up = is_limit ? min(limit, s[step] - '0') : limit;
        // 存在前导零，从1开始，不存在，从0开始。下一个一定不存在前导零。
        for (int i = is_lead; i <= up; ++i)
        {
            ans += dfs(step + 1, is_limit && i == s[step] - '0', false);
            // ans += dfs(step + 1, is_limit && i == up, false);
        }
        if (!is_limit && !is_lead)
            dp[step] = ans;
        return ans;
    }

    long long solve(long long finish, int limit, string suf)
    {
        memset(dp, -1, sizeof(dp));
        this->limit = limit;
        long long intsuf = atol(suf.c_str());
        if (intsuf > finish)
            return 0;
        s = to_string(finish - intsuf);
        // for (auto &ch : s)
        // {
        //     ch = min(ch - '0', limit) + '0';
        // }
        if (s.length() <= suf.length())
            return 1;
        s = s.substr(0, s.length() - suf.length());
        n = s.length();
        long long cnt = dfs(0, true, true) + 1;
        return cnt;
        // return atol(s.c_str()) + 1;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string suf)
    {
        for (auto &ch : suf)
        {
            if (ch - '0' > limit)
                return 0;
        }
        long long intsuf = atol(suf.c_str());
        s = to_string(finish);
        n = s.length() - suf.length();
        s = string(n, limit + '0');
        long long cnt1 = solve(finish, limit, suf);

        long long cnt2 = solve(start - 1, limit, suf);
        // cout << cnt1 << endl;
        // cout << cnt2 << endl;
        return cnt1 - cnt2;

        // return 0;
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
    cout << solution.numberOfPowerfulInt(20, 1159, 5, "20") << endl;
    return 0;
}