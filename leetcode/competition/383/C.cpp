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
    const static int maxn = 5e2 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    vector<vector<vector<int>>> values;
    int check(vector<vector<int>> &image, int x, int y, int threshold)
    {
        int cnt = 0;
        for (int i = x; i <= x + 2; ++i)
        {
            for (int j = y; j < y + 2; ++j)
            {
                if (abs(image[i][j + 1] - image[i][j]) > threshold)
                    return -1;
            }
        }
        for (int j = y; j <= y + 2; ++j)
        {
            for (int i = x; i < x + 2; ++i)
            {
                if (abs(image[i + 1][j] - image[i][j]) > threshold)
                    return -1;
            }
        }
        for (int i = x; i <= x + 2; ++i)
        {
            for (int j = y; j <= y + 2; ++j)
            {
                cnt += image[i][j];
            }
        }
        for (int i = x; i <= x + 2; ++i)
        {
            for (int j = y; j <= y + 2; ++j)
            {
                values[i][j].emplace_back(cnt);
            }
        }
        return cnt;
    }
    vector<vector<int>> resultGrid(vector<vector<int>> &image, int threshold)
    {
        int n = image.size(), m = image[0].size();
        values.resize(n, vector<vector<int>>(m));
        for (int i = 0; i <= n - 3; ++i)
        {
            for (int j = 0; j <= m - 3; ++j)
            {
                check(image, i, j, threshold);
            }
        }

        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                long long sum = 0;
                int size = values[i][j].size();
                if (size == 0)
                {
                    ans[i][j] = image[i][j];
                    continue;
                }
                for (auto &x : values[i][j])
                {
                    sum += x;
                }
                ans[i][j] = ((int)(sum / 9) / size);
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
    vector<vector<int>> a = {{1, 14, 9, 2}, {10, 16, 13, 8}, {7, 11, 12, 4}};
    solution.resultGrid(a, 13);
    return 0;
}