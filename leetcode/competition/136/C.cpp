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
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    int n, m;
    int cnt;
    int minFlips(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        for (int i1 = 0, i2 = n - 1; i1 < i2; ++i1, --i2)
        {
            for (int j1 = 0, j2 = m - 1; j1 < j2; ++j1, --j2)
            {
                int cnt = grid[i1][j1] + grid[i1][j2] + grid[i2][j1] + grid[i2][j2];
                ans += min(cnt, 4 - cnt);
            }
        }
        if (n % 2 == 0 && m % 2 == 0)
        {
            return ans;
        }
        if (n % 2 == 1 && m % 2 == 0)
        {
            int row = 0;
            int cntrow = 0;
            for (int j = 0; j < (m + 1) / 2; ++j)
            {
                if (grid[n / 2][j] != grid[n / 2][m - j - 1])
                {
                    row++;
                }
            }
            for (int j = 0; j < m; ++j)
            {
                if (grid[n / 2][j] == 1)
                {
                    cntrow++;
                }
            }
            if ((cntrow + row) / 4 != (cntrow - row) / 4)
            {
                return ans + row;
            }
            else
            {
                return ans + row + min(min((cntrow + row) % 4, 4 - (cntrow + row) % 4), min((cntrow - row) % 4, 4 - (cntrow - row) % 4));
            }
        }
        if (n % 2 == 0 && m % 2 != 0)
        {
            int col = 0;
            int cntcol = 0;
            for (int i = 0; i < (n + 1) / 2; ++i)
            {
                if (grid[i][m / 2] != grid[n - i - 1][m / 2])
                {
                    col++;
                }
            }
            for (int i = 0; i < n; ++i)
            {
                if (grid[i][m / 2] == 1)
                {
                    cntcol++;
                }
            }
            if ((cntcol + col) / 4 != (cntcol - col) / 4)
            {
                return ans + col;
            }
            else
            {
                return ans + col + min(min((cntcol + col) % 4, 4 - (cntcol + col) % 4), min((cntcol - col) % 4, 4 - (cntcol - col) % 4));
            }
        }
        if (n % 2 != 0 && m % 2 != 0)
        {
            ans += grid[n / 2][m / 2];
            grid[n / 2][m / 2] = 0;
            int cnt1 = 0;
            int anscnt = 0;
            for (int i = 0; i < (n + 1) / 2; ++i)
            {
                if (grid[i][m / 2] != grid[n - 1 - i][m / 2])
                {
                    anscnt++;
                }
            }
            for (int j = 0; j < (m + 1) / 2; ++j)
            {
                if (grid[n / 2][j] != grid[n / 2][m - 1 - j])
                {
                    anscnt++;
                }
            }
            for (int i = 0; i < n; ++i)
            {
                cnt1 += grid[i][m / 2];
            }
            for (int j = 0; j < m; ++j)
            {
                cnt1 += grid[n / 2][j];
            }

            if ((cnt1 + anscnt) / 4 != (cnt1 - anscnt) / 4)
            {
                return ans + anscnt;
            }
            else
            {
                return ans + anscnt + min(min((cnt1 + anscnt) % 4, 4 - (cnt1 + anscnt) % 4), min((cnt1 - anscnt) % 4, 4 - (cnt1 - anscnt) % 4));
            }
        }

        return 0;
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