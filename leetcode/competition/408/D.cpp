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
struct UF
{
    vector<int> fa;
    int count;
    UF(int n) : fa(n), count(n)
    {
        for (int i = 0; i < n; ++i)
            fa[i] = i;
    }
    void init(int n)
    {
        fa.resize(n);
        count = n;
        for (int i = 0; i < n; ++i)
            fa[i] = i;
    }
    int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
    void unite(int u, int v)
    {
        int up = find(u), vp = find(v);
        if (up != vp)
        {
            fa[up] = vp;
            count--;
        }
    }
    bool connect(int u, int v) { return find(u) == find(v); }
    int getCount() { return count; }
};
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    // n up, n + 1 right, n + 2 down, n + 3 left
    void checkCircleRect(int index, int x, int y, int r, int X, int Y, UF &uf)
    {
        if (x - r <= 0)
            uf.unite(index, n + 3);
        if (y - r < 0)
            uf.unite(index, n + 2);
        if (x + r >= X)
            uf.unite(index, n + 1);
        if (y + r >= Y)
            uf.unite(index, n);
    }
    long long dis(long long x1, long long y1, long long x2, long long y2)
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    bool canReachCorner(int X, int Y, vector<vector<int>> &circles)
    {
        int n = circles.size();
        UF uf(n + 4);
        for (int i = 0; i < n; ++i)
        {
            checkCircleRect(i, circles[i][0], circles[i][1], circles[i][2], X, Y, uf);
            for (int j = 0; j < n; ++j)
            {
                if (dis(circles[i][0], circles[i][1], circles[j][0], circles[j][1]) <= 1ll * circles[i][2] + 1ll * circles[j][2])
                {
                    uf.unite(i, j);
                }
            }
        }
        // n up, n + 1 right, n + 2 down, n + 3 left
        if (uf.connect(n + 3, n + 2) || uf.connect(n + 3, n + 1) || uf.connect(n, n + 2) || uf.connect(n, n + 1))
        {
            return false;
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

    return 0;
}