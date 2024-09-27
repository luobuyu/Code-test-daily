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
long long dp[2010][1010];
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;

    // long long ans = 0;
    long long len;
    vector<int> nums;
    vector<int> maxx;
    long long dfs(int step, int pre1, int pre2)
    {
        if (step >= len)
            return 1;
        if (dp[step][pre1] != -1)
            return dp[step][pre1];
        long long ans = 0;
        for (int num = max(pre1, nums[step] - pre2); num <= nums[step]; ++num)
        {
            ans = (ans + dfs(step + 1, num, nums[step] - num)) % mod;
        }
        if (dp[step][pre1] == -1)
            dp[step][pre1] = ans;
        return ans;
    }
    int countOfPairs(vector<int> &nums)
    {
        this->nums = nums;
        len = nums.size();
        maxx.resize(len);
        int n = len;
        maxx[n - 1] = nums[n - 1];
        memset(dp, -1, sizeof(dp));
        for (int i = n - 2; i >= 0; --i)
        {
            maxx[i] = max(maxx[i + 1], nums[i]);
        }
        return dfs(0, 0, INF);
    }
};
int t, n, m, k;
vector<int> a;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    a.resize(2000);
    for (int i = 0; i < 2000; ++i)
    {
        a[i] = 1000;
    }
    cout << solution.countOfPairs(a) << endl;
    return 0;
}