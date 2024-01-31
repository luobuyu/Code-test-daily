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
    const static long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const static long long mod = 1e9 + 7;
    // dp[key][ring]
    int findRotateSteps(string ring, string key)
    {
        int n = ring.size(), m = key.size();
        vector<vector<int>> pos(26, vector<int>()); // 26个字符
        vector<vector<int>> dp(m, vector<int>(n, INF));
        for (int i = 0; i < n; ++i)
            pos[ring[i] - 'a'].emplace_back(i);
        int ans = INF;
        for (int j = 0; j < pos[key[0] - 'a'].size(); ++j)
        {
            int jj = pos[key[0] - 'a'][j];
            dp[0][jj] = min(jj, n - jj) + 1;
            if (m == 1)
                ans = min(ans, dp[0][jj]);
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 0; j < pos[key[i] - 'a'].size(); ++j)
            {
                for (int k = 0; k < pos[key[i - 1] - 'a'].size(); ++k)
                {
                    int jj = pos[key[i] - 'a'][j];
                    int kk = pos[key[i - 1] - 'a'][k];
                    dp[i][jj] = min(dp[i][jj], dp[i - 1][kk] + min(abs(jj - kk), n - abs(jj - kk)) + 1);
                    if (i == m - 1)
                        ans = min(ans, dp[m - 1][jj]);
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
    cout << solution.findRotateSteps("godding", "gd") << endl;
    return 0;
}