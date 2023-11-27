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
struct Line
{
    int x, y1, y2, flag;
    bool operator<(const Line &line) const
    {
        return x == line.x ? flag > line.flag : x < line.x;
    }
} line[maxn << 1];
int yy[maxn << 1];
struct SegTree
{
    struct TreeNode
    {
        int l, r;
        ll lazy, sum;
    };
    vector<TreeNode> tree;
    SegTree(int n) : tree(n << 2) {}
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
            pushup(cur);
            return;
        }
        // if (tree[cur].lazy)
        //     pushdown(cur);
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (l <= mid)
            update(cur << 1, l, r, k);
        if (mid + 1 <= r)
            update(cur << 1 | 1, l, r, k);
        pushup(cur);
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

    void pushup(int cur)
    {
        if (tree[cur].lazy)
            tree[cur].sum = yy[tree[cur].r + 1] - yy[tree[cur].l];
        else if (tree[cur].l == tree[cur].r)
            tree[cur].sum = 0;
        else
            tree[cur].sum = tree[cur << 1].sum + tree[cur << 1 | 1].sum;
    }
    void pushdown(int cur)
    {
        tree[cur << 1].lazy += tree[cur].lazy;
        pushup(cur << 1);
        tree[cur << 1 | 1].lazy += tree[cur].lazy;
        pushup(cur << 1 | 1);
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
    read(n);
    int x1, y1, x2, y2;
    for (int i = 1; i <= n; ++i)
    {
        read(x1, y1, x2, y2);
        line[i * 2 - 1] = {x1, y1, y2, 1};
        line[i * 2] = {x2, y1, y2, -1};
        yy[i * 2 - 1] = y1;
        yy[i * 2] = y2;
    }
    sort(line + 1, line + 1 + n * 2);
    sort(yy + 1, yy + 1 + n * 2);
    int tot = unique(yy + 1, yy + 1 + n * 2) - yy - 1;
    SegTree segTree(tot);
    segTree.build(1, 1, tot - 1); // [1,tot - 1] 代表区间 [1, tot];
    ll sum = 0;
    // 最后一条线不用管
    for (int i = 1; i < n * 2; ++i)
    {
        y1 = lower_bound(yy + 1, yy + 1 + tot, line[i].y1) - yy; // 找到新的下标
        y2 = lower_bound(yy + 1, yy + 1 + tot, line[i].y2) - yy; // 找到新的下标
        segTree.update(1, y1, y2 - 1, line[i].flag);
        sum += segTree.tree[1].sum * 1ll * (line[i + 1].x - line[i].x);
        // sum += segTree.query(1, 1, tot - 1) * 1ll * (line[i + 1].x - line[i].x);
    }
    cout << sum << endl;
    return 0;
}