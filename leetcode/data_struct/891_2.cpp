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
    int sumSubseqWidths(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (nums.size() == 1)
            return 0;
        vector<int> left(n, -1), right(n, n), st(n); // 找每个数左右两侧更小的。当前数可以作为最小值
        vector<int> pow2i(n);
        int top = -1;
        long long ans = 0;
        pow2i[0] = 1;
        for (int i = 1; i < n; ++i)
            pow2i[i] = pow2i[i - 1] * 2 % mod;
        for (int i = 0; i < n; ++i)
        {
            while (top >= 0 && nums[st[top]] >= nums[i])
            {
                right[st[top]] = i;
                --top;
            }
            st[++top] = i;
        }
        top = -1;
        for (int i = n - 1; i >= 0; --i)
        {
            while (top >= 0 && nums[st[top]] >= nums[i])
            {
                left[st[top]] = i;
                --top;
            }
            st[++top] = i;
        }
        for (int i = 0; i < n; ++i)
        {
            // 有多少个子序列以 nums[i] 作为最小值
            // i - left[i], right[i] - i
            int cnt = i - left[i] - 1 + right[i] - i - 1;
            ans = (ans - pow2i[cnt] * nums[i] % mod + mod) % mod;
        }
        fill(left.begin(), left.end(), -1);
        fill(right.begin(), right.end(), n);
        // 找两侧比自己大的，自己可以作为最大值
        top = -1;
        for (int i = 0; i < n; ++i)
        {
            while (top >= 0 && nums[st[top]] <= nums[i])
            {
                right[st[top]] = i;
                --top;
            }
            st[++top] = i;
        }
        top = -1;
        for (int i = n - 1; i >= 0; --i)
        {
            while (top >= 0 && nums[st[top]] <= nums[i])
            {
                left[st[top]] = i;
                --top;
            }
            st[++top] = i;
        }
        for (int i = 0; i < n; ++i)
        {
            int cnt = i - left[i] - 1 + right[i] - i - 1;
            ans = (ans + pow2i[cnt] * nums[i] % mod) % mod;
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
    vector<int> a = {2, 1, 3};
    solution.sumSubseqWidths(a);
    return 0;
}