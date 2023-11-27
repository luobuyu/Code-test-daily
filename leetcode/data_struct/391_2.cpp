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
struct Line
{
    int x, y1, y2, flag;
    bool operator<(const Line &p) const
    {
        return x != p.x ? x < p.x : y1 < p.y1;
    }
};
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    vector<Line> line;
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        int n = rectangles.size();
        line.resize(n * 2);
        long long area = 0;
        int minx1 = INF, miny1 = INF, maxx2 = -INF, maxy2 = -INF;
        for (int i = 0; i < n; ++i)
        {
            auto &rect = rectangles[i];
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            line[i * 2] = {x1, y1, y2, 1};
            line[i * 2 + 1] = {x2, y1, y2, -1};
            area += (x2 - x1) * 1ll * (y2 - y1);
            minx1 = min(minx1, x1);
            miny1 = min(miny1, y1);
            maxx2 = max(maxx2, x2);
            maxy2 = max(maxy2, y2);
        }
        int l = 0;
        n <<= 1;
        sort(line.begin(), line.end());
        while (l < n)
        {
            int r = l;
            while (r + 1 < n && line[r + 1].x == line[l].x)
                ++r;
            vector<pair<int, int>> left, right;
            for (int i = l; i <= r; ++i)
            {
                auto &v = (line[i].flag == 1 ? left : right);
                if (!v.size())
                {
                    v.emplace_back(line[i].y1, line[i].y2);
                }
                else
                {
                    int &pre = v.back().second;
                    if (pre > line[i].y1)
                        return false;
                    else
                        pre = line[i].y2;
                }
            }
            if (l > 0 && r <= n - 2)
            {
                // 不是起始和结束边
                if (left.size() != right.size())
                    return false;

                if (left.front() != right.front())
                    return false;
            }
            else
            {
                if (left.size() + right.size() != 1)
                    return false;
            }
            l = r + 1;
        }
        return true;
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
    vector<vector<int>> a = {{1, 1, 3, 3}, {3, 1, 4, 2}, {3, 2, 4, 4}, {1, 3, 2, 4}, {2, 3, 3, 4}};
    solution.isRectangleCover(a);
    // cout << solution.isRectangleCover(a) << endl;
    return 0;
}