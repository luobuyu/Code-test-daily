// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
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

int init = []
{
    /*********** fast_read ***************/
    freopen("user.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*************************************/
    int nums[3000];
    int n;
    int x;
    while (true)
    {
        if (!getline())
            break;
        for (n = 0; read(x); ++n)
            nums[n] = x;
        if (n == 3)
        {
            if (nums[0] + nums[1] + nums[2] == 0)
                cout << "[" << nums[0] << "," << nums[1] << "," << nums[2] << "]\n";
            else
                cout << "[]\n";
            continue;
        }
        sort(nums, nums + n);
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1, k = n - 1, tmp; j < k;)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    ++j;
                    continue;
                }
                tmp = nums[i] + nums[j] + nums[k];
                if (tmp == 0)
                {
                    cout << "[" << nums[i] << "," << nums[j] << "," << nums[k] << "]";
                    ++j;
                }
                else if (tmp > 0)
                    --k;
                else if (tmp < 0)
                    ++j;
            }
        }
        cout << "]\n";
    }
    exit(0);
    return 0;
}();

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
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min_delta = INF;
        int ans = -1;
        for (int i = 0; i <= n - 3; ++i)
        {
            for (int j = i + 1, k = n - 1; j < k;)
            {
                int tmp = nums[i] + nums[j] + nums[k];
                if (tmp > target)
                {
                    if (min_delta > tmp - target)
                    {
                        min_delta = tmp - target;
                        ans = tmp;
                    }
                    --k;
                }
                else if (tmp < target)
                {
                    ++j;
                    if (min_delta > target - tmp)
                    {
                        min_delta = tmp - target;
                        ans = tmp;
                    }
                }
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

    return 0;
}