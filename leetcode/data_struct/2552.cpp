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
    long long countQuadruplets(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> great(n + 2, vector<int>(n + 2));
        vector<vector<int>> less(n + 2, vector<int>(n + 2));
        // 枚举 j, k
        // 统计 k 右侧比 nums[j] 大的元素个数 great[k][j]
        // 统计 j 左侧比 nums[k] 小的元素个数 less[j][k]
        // 即需要统计 great[i][x] 比 i 大，比 x 大的个数
        // 统计 less[i][x] 比 i 小，比 x 小的个数
        // 递推 great[i][x] = great[i + 1][x] + ?(nums[i] > x)
        // 递推 less[i][x] = less[i - 1][x] + ?(nums[i] < x)
        for (int i = n; i >= 1; --i)
        {
            for (int j = 1; j <= n; ++j)
            {
                great[i][j] = great[i + 1][j] + (nums[i - 1] > j);
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                less[i][j] = less[i - 1][j] + (nums[i - 1] < j);
            }
        }
        long long ans = 0;
        for (int j = 1; j < n - 2; ++j)
        {
            for (int k = j + 1; k < n - 1; ++k)
            {
                if (nums[j] > nums[k])
                    ans += 1ll * great[k + 1][nums[j]] * less[j + 1][nums[k]];
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
    vector<int> a = {1, 3, 2, 4, 5};
    solution.countQuadruplets(a);
    return 0;
}