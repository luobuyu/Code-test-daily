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
    int minimumOperationsToWriteY(vector<vector<int>> &grid)
    {
        unordered_map<int, int> allcnt, ycnt;
        // allcnt[0] = ycnt[0] = 0;
        // allcnt[1]
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                allcnt[grid[i][j]]++;
            }
        }
        int midx = n / 2;
        for (int i = 0; i < midx; ++i)
        {
            ycnt[grid[i][i]]++;
            ycnt[grid[i][n - i - 1]]++;
        }
        for (int i = midx; i < n; ++i)
        {
            ycnt[grid[i][midx]]++;
        }
        for (int i = 0; i < 3; ++i)
        {
            allcnt[i] -= ycnt[i];
        }
        int minx = INF;
        int ysize = n + n / 2;
        for (int i = 0; i < 3; ++i)
        {
            // 枚举y的数字
            int cnt1 = ycnt[(i - 1 + 3) % 3] - ycnt[(i + 1) % 3];
            int cnt2 = INF;
            for (int j = 0; j < 3; ++j)
            {
                if (j == i)
                    continue;
                cnt2 = min(cnt2, allcnt[(j - 1 + 3) % 3] - allcnt[(j + 1) % 3]);
            }
            minx = min(minx, cnt1 + cnt2);
        }
        return minx;
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
    vector<vector<int>> a = {{1, 2, 2}, {1, 1, 0}, {0, 1, 0}};
    solution.minimumOperationsToWriteY(a);
    return 0;
}