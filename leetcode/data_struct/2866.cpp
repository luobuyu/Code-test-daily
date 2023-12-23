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
    long long maximumSumOfHeights(vector<int> &maxHeights)
    {
        int n = maxHeights.size();
        vector<int> st(n);
        int top = -1;
        vector<long long> left(n);
        vector<long long> right(n);
        long long sum = 0;
        int pre = -1;
        for (int i = 0; i < n; ++i)
        {
            while (top >= 0 && maxHeights[st[top]] > maxHeights[i])
            {
                if (top >= 1)
                    pre = st[top - 1];
                else
                    pre = -1;
                sum -= (st[top] - pre) * maxHeights[st[top]];
                --top;
            }
            if (top == -1)
                pre = -1;
            else
                pre = st[top];
            st[++top] = i;
            sum += (i - pre) * maxHeights[i];
            left[i] = sum;
        }
        top = -1;
        sum = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            while (top >= 0 && maxHeights[st[top]] > maxHeights[i])
            {
                if (top >= 1)
                    pre = st[top - 1];
                else
                    pre = n;
                sum -= (pre - st[top]) * maxHeights[st[top]];
                --top;
            }
            if (top == -1)
                pre = n;
            else
                pre = st[top];
            st[++top] = i;
            sum += (pre - i) * maxHeights[i];
            right[i] = sum;
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, left[i] + right[i] - maxHeights[i]);
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
    vector<int> a = {5, 3, 4, 1, 1};
    solution.maximumSumOfHeights(a);
    return 0;
}