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
        return x == p.x ? flag < p.flag : x < p.x;
    }
};

struct SegTree
{
    struct TreeNode
    {
        int l, r;
        int lazy, sum;
    };
    vector<TreeNode> tree;
    vector<int> &yy;
    SegTree(int n, vector<int> &_yy) : tree(n << 2), yy(_yy)
    {
    }
    void build(int cur, int l, int r)
    {
        tree[cur].l = l, tree[cur].r = r;
        tree[cur].lazy = 0, tree[cur].sum = 0;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(cur << 1, l, mid);
        build(cur << 1 | 1, mid + 1, r);
    }
    void update(int cur, int l, int r, int k)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
        {
            tree[cur].lazy += k;
            tree[cur].sum += k * (tree[cur].r + 1 - tree[cur].l);
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (tree[cur].lazy)
            pushdown(cur);
        if (l <= mid)
            update(cur << 1, l, r, k);
        if (mid + 1 <= r)
            update(cur << 1 | 1, l, r, k);
        tree[cur].sum = tree[cur << 1].sum + tree[cur << 1 | 1].sum;
    }
    int query(int cur, int l, int r)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
        {
            return tree[cur].sum;
        }
        if (tree[cur].lazy)
            pushdown(cur);
        int sum = 0;
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (l <= mid)
            sum += query(cur << 1, l, r);
        if (mid + 1 <= r)
            sum += query(cur << 1 | 1, l, r);
        return sum;
    }
    void pushdown(int cur)
    {
        tree[cur << 1].lazy += tree[cur].lazy;
        tree[cur << 1].sum += tree[cur].lazy * (tree[cur << 1].r + 1 - tree[cur << 1].l);
        tree[cur << 1 | 1].lazy += tree[cur].lazy;
        tree[cur << 1 | 1].sum += tree[cur].lazy * (tree[cur << 1 | 1].r + 1 - tree[cur << 1 | 1].l);
        tree[cur].lazy = 0;
    }
};

class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    vector<Line> line;
    vector<int> yy;
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        int n = rectangles.size();
        line.resize(n * 2);
        yy.resize(n * 2);
        long long area = 0;
        int minx1 = INF, miny1 = INF, maxx2 = -INF, maxy2 = -INF;
        for (int i = 0; i < n; ++i)
        {
            auto &rect = rectangles[i];
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];
            line[i * 2] = {x1, y1, y2, 1};
            line[i * 2 + 1] = {x2, y1, y2, -1};
            yy[i * 2] = y1;
            yy[i * 2 + 1] = y2;
            area += (x2 - x1) * 1ll * (y2 - y1);
            minx1 = min(minx1, x1);
            miny1 = min(miny1, y1);
            maxx2 = max(maxx2, x2);
            maxy2 = max(maxy2, y2);
        }
        long long area_rect = (maxx2 - minx1) * 1ll * (maxy2 - miny1);
        if (area != area_rect)
            return false;
        yy.emplace_back(-INF);
        sort(yy.begin(), yy.end());
        int tot = unique(yy.begin(), yy.end()) - yy.begin() - 1;
        sort(line.begin(), line.end());
        SegTree segTree(tot, yy);
        segTree.build(1, 1, tot - 1);
        long long area_union = 0;
        for (int i = 0; i < n * 2 - 1; ++i)
        {
            int y1 = lower_bound(yy.begin() + 1, yy.begin() + tot + 1, line[i].y1) - yy.begin();
            int y2 = lower_bound(yy.begin() + 1, yy.begin() + tot + 1, line[i].y2) - yy.begin();
            if (line[i].flag == 1)
            {
                if (segTree.query(1, y1, y2 - 1) != 0)
                    return false;
            }
            segTree.update(1, y1, y2 - 1, line[i].flag);
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
    vector<vector<int>> a = {{1, 1, 3, 3},
                             {3, 1, 4, 2},
                             {3, 2, 4, 4},
                             {1, 3, 2, 4},
                             {2, 3, 3, 4}};
    cout << solution.isRectangleCover(a) << endl;
    return 0;
}