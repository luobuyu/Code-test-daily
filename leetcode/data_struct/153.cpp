// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
int t, n, m, k;
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
    // int findMin(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     if (nums[0] <= nums[n - 1])
    //         return nums[0];
    //     int l = 0, r = n - 1, mid, ans = -1;
    //     while (l <= r)
    //     {
    //         mid = l + r >> 1;
    //         if (nums[mid] >= nums[0])
    //         {
    //             l = mid + 1;
    //         }
    //         else
    //         {
    //             // nums[mid] < nums[0]
    //             ans = mid;
    //             r = mid - 1;
    //         }
    //     }
    //     return nums[ans];
    // }

    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (nums[0] <= nums[n - 1])
            return nums[0];
        int l = 0, r = n - 1, mid, ans = -1;
        while (l < r)
        {
            mid = l + r >> 1;
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                // nums[mid] <= nums[r]
                r = mid;
            }
        }
        return nums[l];
    }

    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (nums[0] <= nums[n - 1])
            return nums[0];
        int l = 0, r = n - 1, mid, ans = -1;
        while (l < r)
        {
            mid = l + r >> 1;
            if (nums[mid] < nums[l])
            {
                r = mid;
            }
            else
            {
                // nums[mid] >= nums[l]
                if (nums[mid] <= nums[r])
                    break;
                else
                {
                    // nums[l] <= nums[mid] > nums[r]
                    l = mid + 1;
                }
            }
        }
        return nums[l];
    }

    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (nums[0] <= nums[n - 1])
            return nums[0];
        int l = 0, r = n - 1, mid, ans = -1;
        while (l < r)
        {
            mid = l + r >> 1;
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else if (nums[mid] == nums[r])
            {
                r = mid - 1;
            }
            else if (nums[mid] < nums[r])
            {
                r = mid;
            }
        }
        return nums[l];
    }

    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (nums[0] <= nums[n - 1])
            return nums[0];
        int l = 0, r = n - 1, mid, ans = -1;
        while (l <= r)
        {
            mid = l + r >> 1;
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else if (nums[mid] == nums[r])
            {
                r = mid - 1;
            }
            else if (nums[mid] < nums[r])
            {
                ans = mid;
                r = mid;
            }
        }
        return nums[ans];
    }
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (nums[0] <= nums[n - 1])
            return nums[0];
        int l = 0, r = n - 1, mid, ans = -1;
        while (l <= r)
        {
            mid = l + r >> 1;
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else if (nums[mid] <= nums[r])
            {
                // 之前模板是直接
                // ans = mid
                // r = mid - 1;
                ans = mid;
                if (mid - 1 >= 0 && nums[mid - 1] < nums[mid])
                {
                    r = mid - 1;
                }
                else
                    break;
            }
        }
        return nums[ans];
    }
};

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<int> a = {1};
    cout << solution.findMin(a) << endl;
    return 0;
}