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
    unordered_map<int, int> mp;
    unordered_map<int, int> mpy;
    vector<vector<int>> dp;
    int cntx = 1;
    int cnty = 1;
    int getIdx(int x)
    {
        if (!mp.count(x))
        {
            mp[x] = cntx++;
        }
        return mp[x];
    }
    int getIdy(int y)
    {
        if (!mpy.count(y))
        {
            mpy[y] = cnty++;
        }
        return mpy[y];
    }

    bool check(int p1, int p2, vector<vector<int>> &nums)
    {
        // p1 左上角
        if (nums[p1][0] > nums[p2][0] || nums[p1][1] < nums[p2][1])
            return false;
        int x1 = nums[p1][0], y1 = nums[p2][1];
        int x2 = nums[p2][0], y2 = nums[p1][1];
        int tot = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
        return tot == 2;
    }
    int numberOfPairs(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<int> x;
        vector<int> y;
        for (int i = 0; i < n; ++i)
        {
            x.emplace_back(points[i][0]);
            y.emplace_back(points[i][1]);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        for (auto &xx : x)
            xx = getIdx(xx);
        for (auto &yy : y)
            yy = getIdy(yy);
        for (int i = 0; i < n; ++i)
        {
            points[i][0] = getIdx(points[i][0]);
            points[i][1] = getIdy(points[i][1]);
        }
        dp.resize(cntx, vector<int>(cnty));
        for (int i = 0; i < n; ++i)
        {
            dp[points[i][0]][points[i][1]] = 1;
        }
        // 二维前缀和
        for (int i = 1; i < cntx; ++i)
        {
            for (int j = 1; j < cnty; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + dp[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    continue;
                if (check(i, j, points))
                {
                    ans++;
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
    vector<vector<int>> a = {{6, 2}, {4, 4}, {2, 6}};
    solution.numberOfPairs(a);
    return 0;
}