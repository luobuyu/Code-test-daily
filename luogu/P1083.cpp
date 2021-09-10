#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e6 + 10;
const int maxm = 1e5 + 10;
int read()
{
    int x = 0, flag = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    }
    if (flag)
        return -x;
    return x;
}
int t, n, m, k;
int a[maxn];
class SegTree
{
public:
    struct Tree
    {
        int l, r;
        ll val, tag;
    } tree[maxn << 2];

    void build(int cur, int l, int r)
    {
        tree[cur] = {l, r, 0, 0};
        if (l == r)
        {
            tree[cur].val = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(cur << 1, l, mid);
        build(cur << 1 | 1, mid + 1, r);
        tree[cur].val = min(tree[cur << 1].val, tree[cur << 1 | 1].val);
    }

    void pushdown(int cur)
    {
        tree[cur << 1].val += tree[cur].tag;
        tree[cur << 1 | 1].val += tree[cur].tag;
        tree[cur << 1].tag += tree[cur].tag;
        tree[cur << 1 | 1].tag += tree[cur].tag;
        tree[cur].tag = 0;
    }

    void update(int cur, int l, int r, ll k)
    {
        if(l <= tree[cur].l && tree[cur].r <= r)
        {
            tree[cur].val += k;
            tree[cur].tag += k;
            pushdown(cur);
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if(tree[cur].tag)
            pushdown(cur);
        if(l <= mid) update(cur<<1, l, r, k);
        if(mid < r) update(cur << 1 | 1, l, r, k);
        tree[cur].val = min(tree[cur << 1].val, tree[cur << 1 | 1].val);
    }

    int query(int cur, int l, int r)
    {
        if(l <= tree[cur].l && tree[cur].r <= r) return tree[cur].val;
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if(tree[cur].tag)
            pushdown(cur);
        int ans = 0x7f7f7f7f;
        if (l <= mid)
            ans = min(ans, query(cur << 1, l, r));
        if(mid < r)
            ans = min(ans, query(cur << 1 | 1, l, r));
        return ans;
    }
} segTree;

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    n = read(), m = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    segTree.build(1, 1, n);
    int d, s, t;
    int ans = -1;
    for (int i = 1; i <= m; i++)
    {
        d = read(), s = read(), t = read();
        segTree.update(1, s, t, -d);
        if(segTree.query(1, 1, n) < 0)
        {
            ans = i;
            break;
        }
    }

    if(ans == -1)
        printf("0\n");
    else
    {
        printf("-1\n%d\n", ans);
    }

    return 0;
}