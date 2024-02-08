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
class Median
{
private:
    const static int mod = 1e9 + 7;
    priority_queue<int> left;                             // 堆顶是最大值，小于中位数的
    priority_queue<int, vector<int>, greater<int>> right; // 堆顶是最小值，大于等于中位数的
public:
    int leftSum;
    int rightSum;
    Median() : leftSum(0), rightSum(0) {}
    vector<int> getNum(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            push(nums[i]);
            ans[i] = getMedian();
        }
        return ans;
    }
    void push(int x)
    {
        // 如果两个堆大小相等
        if (left.size() == right.size())
        {
            // 加入right
            if (left.empty() || x >= left.top())
            {
                right.push(x);
                rightSum = (rightSum + x) % mod;
            }
            else
            {
                // left弹出最大的到right，加入left
                right.push(left.top());
                leftSum = (leftSum + x - left.top()) % mod;
                rightSum = (rightSum + left.top()) % mod;
                left.pop();
                left.push(x);
            }
        }
        else // left.size() + 1 == right.size()
        {
            if (x <= right.top())
            {
                left.push(x);
                leftSum = (leftSum + x) % mod;
            }
            else
            {
                left.push(right.top());
                leftSum = (leftSum + right.top()) % mod;
                rightSum = (rightSum + x - right.top()) % mod;
                right.pop();
                right.push(x);
            }
        }
    }
    int getMedian()
    {
        return right.top();
    }
};
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    priority_queue<int> left;                             // 堆顶是最大值，小于中位数的
    priority_queue<int, vector<int>, greater<int>> right; // 堆顶是最小值，大于等于中位数的
    // 对顶堆求中位数，保持 right.size() <= left.size();
    vector<int> numsGame(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            nums[i] -= i;
        vector<int> ans(n);
        Median median;
        for (int i = 0; i < n; ++i)
        {
            median.push(nums[i]);
            ans[i] = ((median.rightSum - (i % 2 == 0) * median.getMedian() - median.leftSum) % mod + mod) % mod;
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
    vector<int> a = {3, 4, 5, 1, 6, 7};
    solution.numsGame(a);
    return 0;
}