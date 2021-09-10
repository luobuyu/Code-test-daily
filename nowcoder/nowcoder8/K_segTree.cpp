#include <bits/stdc++.h>
#define ll long long
#define ull long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m;

ll a[maxn];
int b[maxn]; // 数量
int minb[maxn];
struct Node
{
    __int128 sum;
    int id;
    bool operator<(const Node &x) const
    {
        return this->sum > x.sum;
    }
};

class SegTree
{
public:
    struct Node
    {
        int l, r;
        ll val, tag;
    } tree[maxn << 2];
    void build(int cur, int l, int r)
    {
        tree[cur].l = l, tree[cur].r = r, tree[cur].tag = 0;
        if (l == r)
        {
            tree[cur].val = b[l];
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
        if (l <= tree[cur].l && r >= tree[cur].r)
        {
            tree[cur].val += k;
            tree[cur].tag += k;
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (tree[cur].tag)
            pushdown(cur);
        if (l <= mid)
            update(cur << 1, l, r, k);
        if (mid < r)
            update(cur << 1 | 1, l, r, k);
        tree[cur].val = min(tree[cur << 1].val, tree[cur << 1 | 1].val);
    }
    ll query(int cur, int l, int r)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
            return tree[cur].val;
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        ll a = INF_LL, b = INF_LL;
        if (tree[cur].tag)
            pushdown(cur);
        if (l <= mid)
            a = query(cur << 1, l, r);
        if (mid < r)
            b = query(cur << 1 | 1, l, r);
        return min(a, b);
    }
} segTree;

inline void print128(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print128(x / 10);
    putchar(x % 10 + '0');
}

vector<Node> node;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &t);
    for (int tcase = 1; tcase <= t; tcase++)
    {
        scanf("%d", &n);
        node.clear();
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            a[i] += a[i - 1];
        }
        minb[0] = minb[1] = INF;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &b[i]);
        }

        __int128 ans = a[1] * b[1];
        int k = b[1];
        for (int i = 2; i <= n; i++)
        {
            ll p = a[i] - a[1];
            if (p > 0)
            {
                node.push_back({p, i});
            }
        }
        sort(node.begin(), node.end());
        int tot = 0;
        segTree.build(1, 1, n);
        for (int i = 0; i < node.size(); i++)
        {
            Node now = node[i];
            if (now.sum <= 0 || tot >= k)
                break;
            ll mintot = segTree.query(1, 2, now.id);
            if (mintot <= 0)
                continue;
            if (mintot + tot >= k)
            {
                ans += (k - tot) * now.sum;
                tot = k;
                break;
            }
            else
            {
                ans += mintot * now.sum;
                tot += mintot;
                segTree.update(1, 2, now.id, -1ll * mintot);
            }
        }
        printf("Case #%d: %d ", tcase, k);
        print128(ans);
        printf("\n");
    }
    return 0;
}
