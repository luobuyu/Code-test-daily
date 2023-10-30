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
    vector<vector<int>> div;
    vector<vector<int>> cost;
    vector<vector<int>> dp;
    int n;
    void init()
    {
        div.resize(n + 1);
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    int a = i / j;
                    int b = i / a;
                    div[i].emplace_back(b);
                    if (b != a && a < i)
                        div[i].emplace_back(a);
                }
            }
        }
    }

    void get_cost(string &s)
    {
        cost.resize(n + 1, vector<int>(n + 1, INF));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                int len = j - i + 1;
                for (auto &d : div[len])
                {
                    // 枚举余数
                    int tmp = 0;
                    for (int ii = 0; ii < d; ++ii)
                    {
                        for (int p = i + ii, q = j - d + ii + 1; p <= q; p += d, q -= d)
                        {
                            tmp += s[p - 1] != s[q - 1];
                        }
                    }
                    cost[i][j] = min(cost[i][j], tmp);
                }
            }
        }
    }

    int minimumChanges(string s, int k)
    {
        n = s.length();
        init();
        // 首先需要预处理出来，所有的 g[i][j] 需要修改的次数
        // 枚举所有的子串，然后枚举因子，可以先预处理所有数的因子
        get_cost(s);
        dp.resize(n + 1, vector<int>(k + 1, INF));
        // dp[i][j] = dp[p][k - 1] + cost[p + 1][j];
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                for (int p = 0; p < i; ++p)
                {
                    dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost[p + 1][i]);
                }
            }
        }
        return dp[n][k];
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
    cout << solution.minimumChanges("abcc", 1) << endl;
    return 0;
}