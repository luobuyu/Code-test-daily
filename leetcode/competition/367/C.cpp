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

    vector<int> findIndices(vector<int> &nums, int indexDifference, int valueDifference)
    {
        int n = nums.size();
        vector<int> leftmax(n);
        vector<int> leftmin(n);
        vector<int> rightmax(n);
        vector<int> rightmin(n);
        leftmax[0] = leftmin[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] < nums[leftmax[i - 1]])
                leftmax[i] = leftmax[i - 1];
            else
                leftmax[i] = i;
            if (nums[i] > nums[leftmin[i - 1]])
                leftmin[i] = leftmin[i - 1];
            else
                leftmin[i] = i;
        }
        rightmax[n - 1] = rightmin[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] <= nums[rightmax[i + 1]])
                rightmax[i] = rightmax[i + 1];
            else
                rightmax[i] = i;
            if (nums[i] >= nums[rightmin[i + 1]])
                rightmin[i] = rightmin[i + 1];
            else
                rightmin[i] = i;
        }
        for (int l = 0, r = indexDifference; r < n; ++r, ++l)
        {
            if (abs(nums[leftmin[l]] - nums[rightmax[r]]) >= valueDifference)
            {
                return {leftmin[l], rightmax[r]};
            }
            if (abs(nums[leftmax[l]] - nums[rightmin[r]]) >= valueDifference)
            {
                return {leftmax[l], rightmin[r]};
            }
        }
        return {-1, -1};
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