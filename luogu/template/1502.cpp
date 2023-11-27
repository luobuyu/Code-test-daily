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
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int w, h;
// [xi, yi, xi + w - 1, yi + h - 1]
struct Line
{
    int x, y1, y2, l;
    bool operator<(const Line &p) const
    {
        return x == p.x ? l > p.l : x < p.x;
    }
} line[maxn << 1];
int yy[maxn << 1];
struct SegTree
{
    struct TreeNode
    {
        int l, r;
        ll lazy, sum;
        void init(int _l, int _r)
        {
            l = _l, r = _r;
            lazy = sum = 0;
        }
        int len()
        {
            return r - l + 1;
        }
        int mid()
        {
            return (r + l) >> 1;
        }
    };
    vector<TreeNode> tree;
    SegTree(int n) : tree(n << 2) {}
    void build(int cur, int l, int r)
    {
        tree[cur].init(l, r);
        if (l == r)
            return;
        int mid = tree[cur].mid();
        build(cur << 1, l, mid);
        build(cur << 1 | 1, mid + 1, r);
        tree[cur].sum = max(tree[cur << 1].sum, tree[cur << 1 | 1].sum);
    }
    void pushdown(int cur)
    {
        tree[cur << 1].lazy += tree[cur].lazy;
        tree[cur << 1].sum += tree[cur].lazy;
        tree[cur << 1 | 1].lazy += tree[cur].lazy;
        tree[cur << 1 | 1].sum += tree[cur].lazy;
        tree[cur].lazy = 0;
    }
    void update(int cur, int l, int r, int k)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
        {
            tree[cur].sum += k;
            tree[cur].lazy += k;
            return;
        }
        if (tree[cur].lazy)
            pushdown(cur);
        int mid = tree[cur].mid();
        if (l <= mid)
            update(cur << 1, l, r, k);
        if (mid + 1 <= r)
            update(cur << 1 | 1, l, r, k);
        tree[cur].sum = max(tree[cur << 1].sum, tree[cur << 1 | 1].sum);
    }
    ll query(int cur, int l, int r)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
        {
            return tree[cur].sum;
        }
        if (tree[cur].lazy)
            pushdown(cur);
        int mid = tree[cur].mid();
        ll maxx = 0;
        if (l <= mid)
            maxx = max(maxx, query(cur << 1, l, r));
        if (mid + 1 <= r)
            maxx = max(maxx, query(cur << 1 | 1, l, r));
        return maxx;
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
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n, w, h);
        int x1, y1, x2, y2, l;
        for (int i = 1; i <= n; ++i)
        {
            read(x1, y1, l);
            x2 = x1 + w - 1, y2 = y1 + h - 1;
            line[i * 2 - 1] = {x1, y1, y2, l};
            line[i * 2] = {x2, y1, y2, -l};
            yy[i * 2 - 1] = y1;
            yy[i * 2] = y2;
        }
        n <<= 1;
        sort(line + 1, line + 1 + n);
        sort(yy + 1, yy + 1 + n);
        int tot = unique(yy + 1, yy + 1 + n) - yy - 1;
        SegTree segTree(tot);
        segTree.build(1, 1, tot);
        ll maxx = 0;
        for (int i = 1; i <= n; ++i)
        {
            int y1 = lower_bound(yy + 1, yy + 1 + tot, line[i].y1) - yy;
            int y2 = lower_bound(yy + 1, yy + 1 + tot, line[i].y2) - yy;
            segTree.update(1, y1, y2, line[i].l);
            maxx = max(maxx, segTree.query(1, 1, tot));
        }
        cout << maxx << endl;
    }
    return 0;
}