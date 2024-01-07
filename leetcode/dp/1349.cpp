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
    vector<int> s;
    vector<vector<int>> dp;
    int n, m;
    // 当前行下标，当前行状态
    int dfs(int index, int status)
    {
        if (index < 0)
            return 0;
        if (dp[index][status] != -1)
            return dp[index][status];
        int ans = 0;
        // 枚举当前行能坐哪些，所有的子集
        for (int i = 0; i < (1 << m); ++i) // 枚举所有状态
        {
            // 判断合法状态，如果做了障碍，或者相邻
            if ((i | status) != status || (i & (i << 1)) != 0)
                continue;
            int cnt = __builtin_popcount(i);
            if (index != 0)
            {
                // 下一行的状态
                int next = s[index - 1] & ~(i << 1 | i >> 1);
                ans = max(ans, cnt + dfs(index - 1, next));
            }
            else
                ans = max(ans, cnt);
        }
        dp[index][status] = ans;
        return dp[index][status];
    }
    int maxStudents(vector<vector<char>> &seats)
    {
        n = seats.size(), m = seats[0].size();
        s.resize(n);
        dp.resize(n, vector<int>(1 << m, -1));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (seats[i][j] == '.') // 1 可以选，0 不可以选
                    s[i] |= 1 << j;
            }
        }
        return dfs(n - 1, s[n - 1]);
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
    vector<vector<char>> a = {{'.', '.', '#', '#'},
                              {'.', '#', '.', '.'},
                              {'#', '.', '.', '#'},
                              {'#', '#', '#', '.'}};
    solution.maxStudents(a);
    return 0;
}