#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int n, m, q, k;
char a[maxn];

struct UF
{
    unordered_map<int, int> fa;
    bool isConnect(int u, int v)
    {
        check(u);
        check(v);
        return find(u) == find(v);
    }
    void unite(int u, int v)
    {
        check(u);
        check(v);
        int up = find(u);
        int vp = find(v);
        if (u == v)
            return;
        fa[up] = vp;
    }
    int find(int u)
    {
        check(u);
        return fa[u] == u ? u : (fa[u] = find(fa[u]));
    }
    void check(int u)
    {
        if (!fa.count(u))
            fa[u] = u;
    }
};

struct Edge
{
    int u, v;
    int op;
} edge1[maxm], edge2[maxm];
long long hashLL(long long u, long long v)
{
    return u << 32 | v;
}
unordered_set<long long> s;
unordered_set<long long> s2;
int ans[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m >> q;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        edge1[i] = {u, v};
        s2.insert(hashLL(u, v));
    }
    int op;
    for (int i = 1; i <= q; ++i)
    {
        cin >> op >> u >> v;
        if (u > v)
            swap(u, v);
        edge2[i] = {u, v, op};
        if (op == 1)
        {
            s.insert(hashLL(u, v));
        }
    }
    UF uf;
    for (int i = 1; i <= m; ++i)
    {
        if (!s.count(hashLL(edge1[i].u, edge1[i].v)))
        {
            uf.unite(edge1[i].u, edge1[i].v);
        }
    }
    for (int i = q; i >= 1; --i)
    {
        if (edge2[i].op == 1)
        {
            if (s2.count(hashLL(edge2[i].u, edge2[i].v)))
                uf.unite(edge2[i].u, edge2[i].v);
        }
        else
        {
            ans[i] = uf.isConnect(edge2[i].u, edge2[i].v);
        }
    }
    for (int i = 1; i <= q; ++i)
    {
        if (edge2[i].op == 2)
            cout << (ans[i] ? "Yes" : "No") << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")