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
    int countSubMultisets(vector<int> &nums, int l, int r)
    {
        vector<pair<int, int>> a;
        unordered_map<int, int> mp;
        for (auto &x : nums)
        {
            mp[x]++;
        }
        int cnt0 = 0;
        for (auto &[key, value] : mp)
        {
            if (key == 0)
                cnt0 = value;
            else
                a.emplace_back(key, value);
        }
        int n = a.size();
        long long ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(r + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= r; ++j)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if (j - a[i - 1].first >= 0)
                    dp[i][j] = (dp[i][j] + dp[i][j - a[i - 1].first]) % mod;
                if (j - (a[i - 1].second + 1) * a[i - 1].first >= 0)
                {
                    dp[i][j] = (dp[i][j] - dp[i - 1][j - (a[i - 1].second + 1) * a[i - 1].first] + mod) % mod;
                }
            }
        }
        for (int i = l; i <= r; ++i)
        {
            ans = (ans + dp[n][i]) % mod;
        }
        ans = (cnt0 + 1) * ans % mod;
        return ans;
    }
};

// class Solution
// {
// public:
//     int countSubMultisets(vector<int> &nums, int l, int r)
//     {
//         const int MOD = 1e9 + 7;
//         int total = 0;
//         unordered_map<int, int> cnt;
//         for (int x : nums)
//         {
//             total += x;
//             cnt[x]++;
//         }
//         if (l > total)
//         {
//             return 0;
//         }

//         r = min(r, total);
//         vector<int> f(r + 1);
//         f[0] = cnt[0] + 1;
//         cnt.erase(0);

//         int sum = 0;
//         for (auto [x, c] : cnt)
//         {
//             auto new_f = f;
//             sum = min(sum + x * c, r); // 到目前为止，能选的元素和至多为 sum
//             for (int j = x; j <= sum; j++)
//             { // 把循环上界从 r 改成 sum 可以快不少
//                 new_f[j] = (new_f[j] + new_f[j - x]) % MOD;
//                 if (j >= (c + 1) * x)
//                 {
//                     new_f[j] = (new_f[j] - f[j - (c + 1) * x] + MOD) % MOD; // 避免减法产生负数
//                 }
//             }
//             f = move(new_f);
//         }

//         int ans = 0;
//         for (int i = l; i <= r; i++)
//         {
//             ans = (ans + f[i]) % MOD;
//         }
//         return ans;
//     }
// };

int t,
    n,
    m,
    k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<int> a = {1, 2, 2, 3};
    int l = 6, r = 6;
    solution.countSubMultisets(a, l, r);
    return 0;
}