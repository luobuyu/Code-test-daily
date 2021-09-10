#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

int a[maxn];
class SegTree
{
public:
    struct Node
    {
        int l, r;
        ll val, add, mul;
    } tree[maxn << 2];
    void build(int cur, int l, int r)
    {
        tree[cur].l = l, tree[cur].r = r, tree[cur].add = 0, tree[cur].mul = 1;
        if (l == r)
        {
            tree[cur].val = a[l] % mod;
            return;
        }
        int mid = (l + r) >> 1;
        build(cur << 1, l, mid);
        build(cur << 1 | 1, mid + 1, r);
        tree[cur].val = tree[cur << 1].val + tree[cur << 1 | 1].val;
    }
    void pushdown(int cur, ll c1, ll c2)
    {
        tree[cur << 1].val = (tree[cur << 1].val * tree[cur].mul % mod + tree[cur].add * c1 % mod) % mod;
        tree[cur << 1 | 1].val = (tree[cur << 1 | 1].val * tree[cur].mul % mod + tree[cur].add * c2 % mod) % mod;

        tree[cur << 1].mul = tree[cur].mul * tree[cur << 1].mul % mod;
        tree[cur << 1 | 1].mul = tree[cur].mul * tree[cur << 1 | 1].mul % mod;

        tree[cur << 1].add = (tree[cur].mul * tree[cur << 1].add % mod + tree[cur].add) % mod;
        tree[cur << 1 | 1].add = (tree[cur].mul * tree[cur << 1 | 1].add % mod + tree[cur].add) % mod;

        tree[cur].add = 0, tree[cur].mul = 1;
    }

    void updateAdd(int cur, int l, int r, ll k)
    {
        if (l <= tree[cur].l && r >= tree[cur].r)
        {
            tree[cur].val = (ll)(tree[cur].val + (ll)(tree[cur].r - tree[cur].l + 1) * k) % mod;
            tree[cur].add = (tree[cur].add + k) % mod;
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (tree[cur].add || tree[cur].mul != 1)
            pushdown(cur, mid - tree[cur].l + 1, tree[cur].r - mid);
        if (l <= mid)
            updateAdd(cur << 1, l, r, k);
        if (mid < r)
            updateAdd(cur << 1 | 1, l, r, k);
        tree[cur].val = (tree[cur << 1].val + tree[cur << 1 | 1].val) % mod;
    }

    void updateMul(int cur, int l, int r, ll k)
    {
        if (l <= tree[cur].l && r >= tree[cur].r)
        {
            tree[cur].val = tree[cur].val * k % mod;
            tree[cur].mul = tree[cur].mul * k % mod;
            tree[cur].add = tree[cur].add * k % mod;
            return;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        if (tree[cur].add || tree[cur].mul != 1)
            pushdown(cur, mid - tree[cur].l + 1, tree[cur].r - mid);
        if (l <= mid)
            updateMul(cur << 1, l, r, k);
        if (mid < r)
            updateMul(cur << 1 | 1, l, r, k);
        tree[cur].val = (tree[cur << 1].val + tree[cur << 1 | 1].val) % mod;
    }
    ll query(int cur, int l, int r)
    {
        if (l <= tree[cur].l && tree[cur].r <= r)
            return tree[cur].val % mod;
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        ll ans = 0;
        if (tree[cur].add || tree[cur].mul != 1)
            pushdown(cur, mid - tree[cur].l + 1, tree[cur].r - mid);
        if (l <= mid)
            ans = (ans + query(cur << 1, l, r)) % mod;
        if (mid < r)
            ans = (ans + query(cur << 1 | 1, l, r)) % mod;
        return ans % mod;
    }
} segTree;

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(n, m, mod);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
    }
    segTree.build(1, 1, n);
    int op, x, y, k;
    while (m--)
    {
        read(op, x, y);
        if (op != 3)
        {
            read(k);
            if (op == 2)
                segTree.updateAdd(1, x, y, k);
            else
                segTree.updateMul(1, x, y, k);
        }
        else
        {
            printf("%lld\n", segTree.query(1, x, y));
        }
    }

    return 0;
}