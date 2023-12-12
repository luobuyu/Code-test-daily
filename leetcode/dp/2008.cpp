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
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        int m = rides.size();
        sort(rides.begin(), rides.end(), [](const vector<int> &x, const vector<int> &y)
             { return x[1] == y[1] ? x[0] < y[0] : x[1] < y[1]; });
        vector<long long> dp(m + 1);
        for (int i = 1; i <= m; ++i)
        {
            // 查找结束位置小于等于 rides[i][0] 的。
            int index = upper_bound(rides.begin(), rides.begin() + i - 1, rides[i - 1][0], [](int val, const vector<int> &x)
                                    { return val <= x[1]; }) -
                        rides.begin();
            dp[i] = max(dp[i - 1], dp[index] + rides[i - 1][1] - rides[i - 1][0] + rides[i - 1][2]);
        }
        return dp[m];
    }
};

int t,
    n,
    m,
    k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    // vector<vector<int>> a = {{1, 6, 1},
    //                          {3, 10, 2},
    //                          {10, 12, 3},
    //                          {11, 12, 2},
    //                          {12, 15, 2},
    //                          {13, 18, 1}};
    // solution.maxTaxiEarnings(20, a);
    vector<int> a = {1, 2, 3, 3, 3, 4, 4, 5};
    int index = lower_bound(a.begin(), a.end(), 3) - a.begin();
    cout << index << endl;
    index = lower_bound(a.begin(), a.end(), 3, [](const int &x, const int &y)
                        { return x <= y; }) -
            a.begin();
    cout << index << endl;
    return 0;
}