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
struct Node
{
    int u, v;
    int w;
    bool operator<(const Node &p) const
    {
        return w < p.w;
    }
};

struct UF
{
    vector<int> fa;
    UF(int n) : fa(n)
    {
        for (int i = 0; i < n; ++i)
            fa[i] = i;
    }
    int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }
    void unite(int u, int v)
    {
        int up = find(u);
        int vp = find(v);
        if (up == vp)
            return;
        fa[up] = vp;
    }
    bool connect(int u, int v)
    {
        return find(u) == find(v);
    }
};
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        vector<Node> path;
        int n = heights.size(), m = heights[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (j + 1 < m)
                    path.push_back({i * m + j, i * m + (j + 1), abs(heights[i][j + 1] - heights[i][j])});
                if (i + 1 < n)
                    path.push_back({i * m + j, (i + 1) * m + j, abs(heights[i][j] - heights[i + 1][j])});
            }
        }

        sort(path.begin(), path.end());
        UF uf(m * n);
        for (auto &node : path)
        {
            uf.unite(node.u, node.v);
            if (uf.connect(0, n * m - 1))
            {
                return node.w;
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
    vector<vector<int>> a = {{1, 10, 6, 7, 9, 10, 4, 9}};
    solution.minimumEffortPath(a);
    return 0;
}