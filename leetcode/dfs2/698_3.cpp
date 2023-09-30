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
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0;
        int maxx = 0;
        for (auto &x : nums)
        {
            sum += x;
            maxx = max(maxx, x);
        }
        int target = sum / k;
        if (sum % k || maxx > target)
            return false;
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](const int &x, const int &y)
             { return x > y; }); // 小剪枝
        unordered_map<int, bool> dp;
        int state = 0;
        // step 表示当前桶
        function<bool(int, int, int)> dfs = [&](int step, int index, int curSum)
        {
            if (step == 0)
                return true;
            if (curSum == target)
            {
                dp[state] = dfs(step - 1, 0, 0);
                return dp[state];
            }
            if (dp.count(state))
                return dp[state];
            for (int i = index; i < n; ++i)
            {
                if (((state >> i) & 1) || curSum + nums[i] > target)
                    continue;
                state |= 1 << i;
                if (dfs(step, i + 1, curSum + nums[i]))
                    return true;
                state ^= 1 << i;
                while (i + 1 < n && nums[i + 1] == nums[i])
                    ++i;
            }
            return false;
        };
        return dfs(k, 0, 0);
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
    vector<int> a = {4, 3, 2, 3, 5, 2, 1};
    solution.canPartitionKSubsets(a, 4);
    return 0;
}