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
    // 1. dp 做法，分别求出来左右侧最高的，判断每个位置能存多高的水。
    int trap1(vector<int> &height)
    {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; --i)
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
    // 2. 单调栈做法
    // 找右侧第一个比他大的，单调减栈，左侧第一个比他大的可以通过左边的找到
    int trap2(vector<int> &height)
    {
        int n = height.size();
        vector<int> st(n);
        int top = -1;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            while (top >= 0 && height[st[top]] <= height[i])
            {
                int h1 = height[st[top]];
                --top;
                if (top < 0)
                    break;
                int left = st[top];
                ans += (i - left - 1) * (min(height[i], height[left]) - h1);
            }
            st[++top] = i;
        }
        return ans;
    }
    // 3. 双指针做法
    int trap3(vector<int> &height)
    {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int i = 0, j = n - 1;
        int ans = 0;
        while (i < j)
        {
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);
            if (leftMax < rightMax)
            {
                ans += leftMax - height[i];
                i++;
            }
            else
            {
                ans += rightMax - height[i];
                --j;
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