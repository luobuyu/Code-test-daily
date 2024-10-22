#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
int n, q;
int a[maxn];
int st[maxn];
int lef[maxn];
int righ[maxn];
int top = -1;

struct SegTree
{
    struct TreeNode{
        int l, r;
        pair<int, int> maxx; // maxx, index;
    };
    vector<TreeNode> tree;
    SegTree(int _n): tree(n << 2){}
    void build(int cur, int l, int r)
    {
        tree[cur].l = l;
        tree[cur].r = r;
        tree[cur].maxx = {0, -1};
        if(l == r) {
            tree[cur].maxx = {a[l], l};
            return;
        }
        int mid = (l + r) >> 1;
        build(cur << 1, l, mid);
        build(cur << 1 | 1, mid + 1, r);
        tree[cur].maxx = max(tree[cur << 1].maxx, tree[cur << 1 | 1].maxx);
    }
    pair<int, int> query(int cur, int l, int r)
    {
        if(l <= tree[cur].l && tree[cur].r <= r)
        {
            return tree[cur].maxx;
        }
        int mid = (tree[cur].l + tree[cur].r) >> 1;
        pair<int, int> ret{0, 0};
        if(l <= mid)
            ret = max(ret, query(cur << 1, l, r));
        if(mid + 1 <= r)
            ret = max(ret, query(cur << 1 | 1, l, r));
        return ret;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> q;
    int maxx = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    int l, r;
    SegTree segTree(n + 1);
    segTree.build(1, 1, n);

    top = -1;
    for(int i = 1; i <= n; ++i) {
        righ[i] = n + 1;
        lef[i] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        while(top != -1 && a[st[top]] <= a[i]) {
            righ[st[top]] = i;
            --top;
        }
        st[++top] = i;
    }
    top = -1;
    for(int i = n; i >= 1; --i) {
        while(top != -1 && a[st[top]] <= a[i]) {
            lef[st[top]] = i;
            --top;
        }
        st[++top] = i;
    }
    // for(int i = 1; i <= n; ++i) {
    //     cout << lef[i] << ", ";
    // }
    // cout << endl;
    // for(int i = 1; i<=n; ++i) {
    //     cout << righ[i] << ",";
    // }
    // cout << endl;

    while(q--)
    {
        cin >> l >> r;
        int len = r - l + 1;
        auto tmp = segTree.query(1, l, r);
        int index = tmp.second;
        int len1, len2;
        if(lef[index] != 0) {
            len1 = max(r - l + 1, r - lef[index] + 1);
        } else {
            len1 = INT_MAX;
        }
        if(righ[index] != n + 1) {
            len2 = max(r - l + 1, righ[index] - l + 1);
        } else {
            len2 = INT_MAX;
        }
        if(len1 == INT_MAX && len2 == INT_MAX) {
            cout << "lose" << endl;
            cout << max(len, 2) << endl;
        } else {
            cout << "win" << endl;
            cout << min(len1, len2) << endl;
        }
    }
    return 0;
}