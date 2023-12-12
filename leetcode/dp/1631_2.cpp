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
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size(), m = heights[0].size();
        int l = INF, r = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (j + 1 < m)
                {
                    r = max(r, abs(heights[i][j + 1] - heights[i][j]));
                    l = min(l, abs(heights[i][j + 1] - heights[i][j]));
                }
                if (i + 1 < n)
                {
                    r = max(r, abs(heights[i + 1][j] - heights[i][j]));
                    l = min(l, abs(heights[i + 1][j] - heights[i][j]));
                }
            }
        }
        function<bool(int)> check = [&](int mid)
        {
            queue<int> q;
            vector<int> vis(n * m);
            q.push(0);
            vis[0] = true;
            vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
            while (q.size())
            {
                auto out = q.front();
                q.pop();
                if (out == (n * m - 1))
                    return true;
                for (int i = 0; i < 4; ++i)
                {
                    int newx = dx[i] + out / m;
                    int newy = dy[i] + out % m;
                    if (newx < 0 || newx >= n || newy < 0 || newy >= m || vis[newx * m + newy])
                        continue;
                    if (abs(heights[newx][newy] - heights[out / m][out % m]) > mid)
                        continue;
                    q.push({newx * m + newy});
                    vis[newx * m + newy] = true;
                }
            }
            return false;
        };
        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
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
    vector<vector<int>> a = {{1, 10, 6, 7, 9, 10, 4, 9}};
    solution.minimumEffortPath(a);
    return 0;
}