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

class Solution
{
public:
    int minimumChanges(string s, int K)
    {
        int n = s.size();

        const int INF = 1e9;
        int g[n + 1][n + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                g[i][j] = INF;
        // 枚举每个子串，计算变成半回文串要修改几次
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
            {
                int len = j - i + 1;
                // 枚举因数 d
                for (int d = 1; d < len; d++)
                    if (len % d == 0)
                    {
                        int cnt = 0;
                        // 枚举每个字符，并检查它对应的字符
                        for (int k = 0; k < len; k++)
                        {
                            int kk = (len / d - 1 - k / d) * d + k % d;
                            if (k >= kk)
                                break;
                            if (s[i - 1 + k] != s[i - 1 + kk])
                                cnt++;
                        }
                        g[i][j] = min(g[i][j], cnt);
                    }
            }

        // 套 dp 方程
        int f[n + 1][K + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= K; j++)
                f[i][j] = INF;
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= K; j++)
                for (int ii = i - 1; ii >= 0; ii--)
                    f[i][j] = min(f[i][j], f[ii][j - 1] + g[ii + 1][i]);
        return f[n][K];
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
    cout << solution.minimumChanges("abcc", 1) << endl;
    return 0;
}