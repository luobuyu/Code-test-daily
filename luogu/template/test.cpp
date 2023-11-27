// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
struct SegTree
{
    struct TreeNode
    {
        int l, r;
        ll lazy;
        int cnt, sum; // cnt 表示该段区间被覆盖了多少次。
    };
    vector<TreeNode> tree;
    SegTree(int n) : tree(n << 2) {}
    void build(int cur, int l, int r)
    {
        tree[cur].l = l, tree[cur].r = r;
        tree[cur].lazy = 0, tree[cur].sum = 0;
        tree[cur].cnt = 0;
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
            pushup(cur);
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (tree[cur].lazy)
            pushdown(cur);
        if (l <= mid)
            update(cur << 1, l, r, k);
        if (mid + 1 <= r)
            update(cur << 1 | 1, l, r, k);
        pushup(cur);
    }
    void pushup(int cur)
    {
        if (tree[cur].lazy > 0)
            tree[cur].sum = tree[cur].r + 1 - tree[cur].l;
        else
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
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        int sum = 0;
        if (l <= mid)
            sum += query(cur << 1, l, r);
        if (mid + 1 <= r)
            sum += query(cur << 1 | 1, l, r);
        return sum;
    }
    void pushdown(int cur)
    {
        tree[cur << 1].lazy += tree[cur].lazy;
        tree[cur << 1 | 1].lazy += tree[cur].lazy;
        tree[cur].lazy = 0;
    }
};

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // [1, 4]
    n = 4;
    SegTree segTree(n);
    segTree.build(1, 1, n);
    segTree.update(1, 1, 3, 1);
    segTree.update(1, 2, 4, 1);
    segTree.update(1, 1, 3, -1);
    cout << segTree.tree[1].sum << endl;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            cout << i << ", " << j << ": " << segTree.query(1, i, j) << endl;
        }
    }
    return 0;
}