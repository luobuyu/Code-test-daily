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
    vector<vector<int>> dp; // dp[i][j] 到达元素j，i个子数组
    vector<int> preSum;
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        dp.resize(4, vector<int>(n + 1));
        preSum.resize(n + 1);

        int sum = 0;
        vector<vector<pair<int, int>>> pre(4, vector<pair<int, int>>(n + 1));
        for (int i = 1; i <= n; ++i)
        {
            sum += nums[i - 1];
            preSum[i] = sum;
        }
        for (int i = 1; i <= 3; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = dp[i][j - 1];
                pre[i][j] = {i, j - 1};
                if (j - k >= 0)
                {
                    int tmp = dp[i - 1][j - k] + preSum[j] - preSum[j - k];
                    if (tmp > dp[i][j])
                    {
                        pre[i][j] = {i - 1, j - k};
                        dp[i][j] = tmp;
                    }
                }
            }
        }
        cout << dp[3][n] << endl;
        int i = 3, j = n;
        vector<int> ans;
        while (i > 0 && j > 0)
        {
            if (pre[i][j].first == i - 1 && pre[i][j].second == j - k)
            {
                ans.emplace_back(j - k);
            }
            int tmpi = pre[i][j].first;
            int tmpj = pre[i][j].second;
            i = tmpi, j = tmpj;
        }
        reverse(ans.begin(), ans.end());
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
    vector<int> a = {4, 3, 2, 1};
    solution.maxSumOfThreeSubarrays(a, 1);
    return 0;
}