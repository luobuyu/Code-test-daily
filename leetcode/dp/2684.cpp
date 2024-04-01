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
    int maxMoves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1000000000));
        vector<int> dx = {1, 0, -1}, dy = {-1, -1, -1};
        int ans = 0;
        for (int i = 0; i < n; ++i)
            dp[i][0] = 0;
        for (int j = 1; j < m; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int k = 0; k < 3; ++k)
                {
                    int prex = i + dx[k];
                    int prey = j + dy[k];
                    if (prex < 0 || prex >= n || prey < 0 || prey >= m || grid[prex][prey] >= grid[i][j])
                        continue;
                    // if(prey != 0 && (prex == 0 || prex == n - 1)) continue;
                    dp[i][j] = max(dp[i][j], dp[prex][prey] + 1);
                }
                ans = max(ans, dp[i][j]);
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
    vector<vector<int>> a = {{65, 200, 263, 220, 91, 183, 2, 187, 175, 61, 225, 120, 39}, {111, 242, 294, 31, 241, 90, 145, 25, 262, 214, 145, 71, 294}, {152, 25, 240, 69, 279, 238, 222, 9, 137, 277, 8, 143, 143}, {189, 31, 86, 250, 20, 63, 188, 209, 75, 22, 127, 272, 110}, {122, 94, 298, 25, 90, 169, 68, 3, 208, 274, 202, 135, 275}, {205, 20, 171, 90, 70, 272, 280, 138, 142, 151, 80, 122, 130}, {284, 272, 271, 269, 265, 134, 185, 243, 247, 50, 283, 20, 232}, {266, 236, 265, 234, 249, 62, 98, 130, 122, 226, 285, 168, 204}, {231, 24, 256, 101, 142, 28, 268, 82, 111, 63, 115, 13, 144}, {277, 277, 31, 144, 49, 132, 28, 138, 133, 29, 286, 45, 93}, {163, 96, 25, 9, 3, 159, 148, 59, 25, 81, 233, 127, 12}, {127, 38, 31, 209, 300, 256, 15, 43, 74, 64, 73, 141, 200}};
    cout << solution.maxMoves(a) << endl;
    return 0;
}