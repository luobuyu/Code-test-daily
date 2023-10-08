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
    void dfs(int l, int r)
    {
    }
    int minOperations(string s1, string s2, int x)
    {
        int n = s1.size();
        int sum = 0;
        vector<int> a;
        vector<bool> vis(n);
        for (int i = 0; i < n; ++i)
        {
            if (s1[i] != s2[i])
            {
                a.emplace_back(i);
                sum++;
            }
        }
        if (sum & 1)
            return -1;
        if (sum == 0)
            return 0;
        int m = a.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = i + 1; j < m; ++j)
            {
                int sum = 0;
                for (int k = i; k <= j; k += 2)
                {
                    sum += min(a[k + 1] - a[k], x);
                }
                dp[i][j] = sum;
            }
        }
        for (int len = 2; len <= m; len += 2)
        {
            for (int i = 0; i + len - 1 <= m - 1; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + min(x, a[j] - a[i]));
                if (i + 2 <= j)
                    dp[i][j] = min(dp[i][j], dp[i + 2][j] + min(x, a[i + 1] - a[i]));
                if (i <= j - 2)
                    dp[i][j] = min(dp[i][j], dp[i][j - 2] + min(x, a[j] - a[j - 1]));
            }
        }
        return dp[0][m - 1];
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
    string s1 = "100010010100111100001110101111100001001101011010100111101011100100011111110001011001001";
    string s2 = "000001100010010011111101100101111011101110010001001010100101011100011110000111010011010";
    solution.minOperations(s1, s2, 6);
    return 0;
}