// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
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
using ll = long long;
struct SegTree
{
    struct TreeNode
    {
        int l, r;
        ll sum;
        int minx;
        int tag;
    };
    vector<TreeNode> tree;
    SegTree(int n) : tree(n << 2) {}
    void build(int cur, int l, int r)
    {
        tree[cur].l = l, tree[cur].r = r, tree[cur].tag = 0;
        tree[cur].sum = 0, tree[cur].minx = 0;
        if (l == r)
            return;
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        build(cur << 1, l, mid);
        build(cur << 1 | 1, mid + 1, r);
        tree[cur].minx = min(tree[cur << 1].minx, tree[cur << 1 | 1].minx);
        tree[cur].sum = tree[cur << 1].sum + tree[cur << 1 | 1].sum;
    }
    void pushdown(int cur)
    {
        tree[cur << 1].sum += (tree[cur << 1].r - tree[cur << 1].l + 1ll) * tree[cur].tag;
        tree[cur << 1].minx += tree[cur].tag;
        tree[cur << 1].tag += tree[cur].tag;
        tree[cur << 1 | 1].sum += (tree[cur << 1 | 1].r - tree[cur << 1 | 1].l + 1ll) * tree[cur].tag;
        tree[cur << 1 | 1].minx += tree[cur].tag;
        tree[cur << 1 | 1].tag += tree[cur].tag;
        tree[cur].tag = 0;
    }
    void update(int cur, int l, int r, ll k)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
        {
            tree[cur].sum += (tree[cur].r - tree[cur].l + 1ll) * k;
            tree[cur].minx += k;
            // if (tree[cur].l != tree[cur].r)
            tree[cur].tag += k;
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (tree[cur].tag)
            pushdown(cur);
        if (l <= mid)
            update(cur << 1, l, r, k);
        if (mid + 1 <= r)
            update(cur << 1 | 1, l, r, k);
        tree[cur].minx = min(tree[cur << 1].minx, tree[cur << 1 | 1].minx);
        tree[cur].sum = tree[cur << 1].sum + tree[cur << 1 | 1].sum;
    }
    int queryIndex(int cur, int l, int r, int upper)
    {
        if (tree[cur].l == tree[cur].r && tree[cur].minx <= upper)
        {
            return tree[cur].l;
        }
        int minx = INT_MAX;
        if (tree[cur].tag)
            pushdown(cur);
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (l <= mid && tree[cur << 1].minx <= upper)
            minx = min(minx, queryIndex(cur << 1, l, r, upper));
        else if (mid + 1 <= r && tree[cur << 1 | 1].minx <= upper)
            minx = min(minx, queryIndex(cur << 1 | 1, l, r, upper));
        return minx;
    }
    ll querySum(int cur, int l, int r)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
        {
            return tree[cur].sum;
        }
        ll sum = 0;
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (tree[cur].tag)
            pushdown(cur);
        if (l <= mid)
            sum += querySum(cur << 1, l, r);
        if (mid + 1 <= r)
            sum += querySum(cur << 1 | 1, l, r);
        return sum;
    }
};
class BookMyShow
{
public:
    SegTree segtree;
    int m_n, m_m;
    BookMyShow(int n, int m) : segtree(n + 1), m_n(n), m_m(m)
    {
        segtree.build(1, 1, m_n);
    }

    vector<int> gather(int k, int maxRow)
    {
        maxRow++;
        int index = segtree.queryIndex(1, 1, m_n, m_m - k);
        if (index > maxRow)
            return {};
        int sum = segtree.querySum(1, index, index);
        segtree.update(1, index, index, k);
        return {index - 1, sum};
    }

    bool scatter(int k, int maxRow)
    {
        maxRow++;
        ll sum = segtree.querySum(1, 1, maxRow);
        if (1ll * maxRow * m_m - sum < k)
            return false;
        int index = segtree.queryIndex(1, 1, maxRow, m_m - 1);
        while (true)
        {
            ll sum = segtree.querySum(1, index, index);
            if (m_m - sum >= k)
            {
                segtree.update(1, index, index, k);
                break;
            }
            k -= m_m - sum;
            segtree.update(1, index, index, m_m - sum);
            index++;
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
    BookMyShow bookMyShow(5, 9);
    bookMyShow.scatter(2, 2);
    bookMyShow.gather(7, 2);
    bookMyShow.gather(4, 1);
    bookMyShow.gather(6, 2);
    bookMyShow.scatter(2, 1);
    return 0;
}