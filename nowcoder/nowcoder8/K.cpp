struct aa
{
    ll l, r, v;
    ll lazy;
} ans[maxn << 2];
void build(ll p, ll l, ll r)
{
    ll mid;
    ans[p].l = l;
    ans[p].r = r;
    ans[p].lazy = 0;
    if (l == r)
    {
        ans[p].v = b[l];
        return;
    }
    mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    ans[p].v = min(ans[p << 1].v, ans[p << 1 | 1].v);
    return;
}
void push_down(ll p)
{
    if (!ans[p].lazy)
        return;
    ans[p << 1].lazy += ans[p].lazy;
    ans[p << 1 | 1].lazy += ans[p].lazy;
    ans[p << 1].v += ans[p].lazy;
    ans[p << 1 | 1].v += ans[p].lazy;
    ans[p].lazy = 0;
    return;
}
void update(ll p, ll l, ll r, ll k)
{
    if (ans[p].r < l || ans[p].l > r)
        return;
    if (l <= ans[p].l && r >= ans[p].r)
    {
        ans[p].lazy += k;
        ans[p].v += k;
        return;
    }
    push_down(p);
    update(p << 1, l, r, k);
    update(p << 1 | 1, l, r, k);
    ans[p].v = min(ans[p << 1].v, ans[p << 1 | 1].v);
    return;
}
ll query(ll p, ll l, ll r)
{
    if (ans[p].r < l || ans[p].l > r)
    {
        return INF;
    }
    if (l <= ans[p].l && r >= ans[p].r)
        return ans[p].v;
    push_down(p);
    return min(query(p << 1, l, r), query(p << 1 | 1, l, r));
}































#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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

vector<Node> node;

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
            if (i > 1)
            {
                minb[i] = min(minb[i - 1], b[i]);
            }
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
        for (int i = 0; i < node.size(); i++)
        {
            Node now = node[i];
            if (now.sum <= 0 || tot >= k)
                break;
            int mintot = minb[now.id] - tot;
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
            }
        }

        printf("Case #%d: %d ", tcase, k);
        print128(ans);
        printf("\n");
    }
    return 0;
}