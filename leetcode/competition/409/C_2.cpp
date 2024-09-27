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
class SegTree
{
public:
    struct Node
    {
        int l, r;
        ll val, tagSum;
    };
    vector<Node> tree;
    SegTree(int n) : tree(n << 2) {}
    void build(int cur, int l, int r, vector<int> &a)
    {
        tree[cur].l = l, tree[cur].r = r;
        tree[cur].tagSum = 0;
        if (l == r)
        {
            tree[cur].val = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(cur << 1, l, mid, a);
        build(cur << 1 | 1, mid + 1, r, a);
        tree[cur].val = tree[cur << 1].val + tree[cur << 1 | 1].val;
    }
    void pushdown(int cur, ll c1, ll c2)
    {
        tree[cur << 1].val += c1 * tree[cur].tagSum;
        tree[cur << 1 | 1].val += c2 * tree[cur].tagSum;
        tree[cur << 1].tagSum += tree[cur].tagSum;
        tree[cur << 1 | 1].tagSum += tree[cur].tagSum;
        tree[cur].tagSum = 0;
    }
    void update(int cur, int l, int r)
    {
        if (tree[cur].val == 0)
            return;
        if (l <= tree[cur].l && r >= tree[cur].r)
        {
            tree[cur].val = 0;
            tree[cur].tagSum = 1;
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (l <= mid)
            update(cur << 1, l, r);
        if (mid < r)
            update(cur << 1 | 1, l, r);
        tree[cur].val = tree[cur << 1].val + tree[cur << 1 | 1].val;
    }
    ll query(int cur, int l, int r)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
            return tree[cur].val;
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        ll ans = 0;
        if (tree[cur].tagSum)
            pushdown(cur, mid - tree[cur].l + 1, tree[cur].r - mid);
        if (l <= mid)
            ans += query(cur << 1, l, r);
        if (mid < r)
            ans += query(cur << 1 | 1, l, r);
        return ans;
    }
};

class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        int m = queries.size();
        vector<int> ans(m);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            a[i] = 1;

        SegTree segTree(n);
        segTree.build(1, 1, n, a);

        for (int i = 0; i < m; ++i)
        {
            if (queries[i][0] + 1 != queries[i][1])
            {
                segTree.update(1, queries[i][0] + 1 + 1, queries[i][1] + 1 - 1);
            }
            ans[i] = segTree.query(1, 1, n) - 1;
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

    return 0;
}