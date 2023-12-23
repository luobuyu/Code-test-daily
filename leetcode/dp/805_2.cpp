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
    bool splitArraySameAverage(vector<int> &nums)
    {
        int sum = 0;
        int n = nums.size();
        if (n == 1)
            return false;
        for (auto &x : nums)
            sum += x;
        // sumA / k = (sum - sumA) / (n - k);
        // sumA = sum * k / n
        // 找一个子数组，和是 sumA
        // 每个数均减去平均值，也就是 sumA = 0
        // sumA = sum * n * k / n = sum * k
        // 每个数减去sum，就是 sumA = 0
        for (auto &x : nums)
            x = x * n - sum;
        int m = n >> 1;
        unordered_set<int> s;
        for (int i = 1; i < (1 << m); ++i)
        {
            // [1, (1 << m) - 1]
            int tmp = 0;
            for (int j = 0; j < m; ++j)
            {
                if ((i >> j) & 1)
                    tmp += nums[j];
            }
            if (tmp == 0)
                return true;
            s.insert(tmp);
        }
        for (int i = 1; i < (1 << (n - m)); ++i)
        {
            int tmp = 0;
            for (int j = m; j < n; ++j)
            {
                if ((i >> (j - m)) & 1)
                    tmp += nums[j];
            }
            if (tmp == 0)
                return true;
            if (s.count(-tmp) && i != (1 << (n - m)) - 1)
                return true;
        }
        return false;
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
    vector<int> a = {17, 3, 7, 12, 1};
    cout << solution.splitArraySameAverage(a) << endl;

    return 0;
}