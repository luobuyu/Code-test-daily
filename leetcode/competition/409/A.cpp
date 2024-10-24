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
class neighborSum
{
public:
    unordered_map<int, pair<int, int>> mp;
    int n, m;
    vector<vector<int>> grid;
    neighborSum(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                mp[grid[i][j]] = {i, j};
            }
        }
        this->grid = grid;
    }

    int adjacentSum(int value)
    {
        auto &[x, y] = mp[value];
        int sum = 0;
        if (x - 1 >= 0)
            sum += grid[x - 1][y];
        if (y - 1 >= 0)
            sum += grid[x][y - 1];
        if (x + 1 < n)
            sum += grid[x + 1][y];
        if (y + 1 < m)
            sum += grid[x][y + 1];
        return sum;
    }

    int diagonalSum(int value)
    {
        int sum = 0;
        auto &[x, y] = mp[value];
        if (x - 1 >= 0 && y - 1 >= 0)
            sum += grid[x - 1][y - 1];
        if (x - 1 >= 0 && y + 1 < m)
            sum += grid[x - 1][y + 1];
        if (x + 1 < n && y - 1 >= 0)
            sum += grid[x + 1][y - 1];
        if (x + 1 < n && y + 1 < m)
            sum += grid[x + 1][y + 1];
        return sum;
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