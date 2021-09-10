#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 100 + 10;
int a[maxn], n;

struct Edge
{
    int v, w;
};
vector<Edge> g[maxn];

// 循环非递归版
struct Trie
{
    static const int M = 2;          // 字符集大小
    static const int LEN = 31;
    int nex[maxn * 30][M], cnt = 0, val[maxn]; // cnt记录点号
    int xorv[maxn];

    void ins(ll x)
    {
        int now = 0;
        for (int i = LEN; i >= 0; i--)
        {
            int c = (x >> i) & 1;
            if(!nex[now][c])
            {
                nex[now][c] = ++cnt;
                nex[cnt][0] = nex[cnt][1] = 0;
            }
            now = nex[now][c];
        }
    }

    void init()
    {
        nex[0][0] = nex[0][1] = cnt = 0;
    }

    ll find(ll x) 
    {
        ll now = 0, ret = 0;
        for (int i = LEN; i >= 0; i--)
        {
            int c = (x >> i) & 1;
            if(nex[now][c])
                now = nex[now][c];
            else
            {
                now = nex[now][c ^ 1];
                ret |= (1 << i);
            }
        }
        return ret;
    }
}trie;

ll merge(int m, int l, int r)
{
    if (l == m || m == r)
        return 0;
    trie.init();
    ll ret = 0x3f3f3f3f3f3f3f3f;
    for (int i = m; i < r; i++)
        trie.ins(a[i]);
    for (int i = l; i < m; i++)
        ret = min(ret, trie.find(a[i]));
    return ret;
}

void dfs(int u, int fa)
{
    for (int i = 0; i < g[u].size(); i++)
    {
        auto e = g[u][i];
        if(e.v == fa)
            continue;
        a[e.v] = a[u] ^ e.w; // 边权转化为点权
        dfs(e.v, u);
    }
}

ll solve(int dep, int l, int r)
{
    if(dep == -1 || l == r)
        return 0;
    int mid = l;
    // 找到分叉点，从最高位开始
    while(mid < r && ((a[mid] >> dep) & 1) == 0)
        ++mid;
    // 找到了最高位为 1 的
    ll ret = solve(dep - 1, l, mid) + solve(dep - 1, mid, r);
    return ret + merge(mid, l, r);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    int u, v, w;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        u++, v++;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, -1);
    sort(a + 1, a + 1 + n);

    printf("%lld\n", solve(31, 1, n + 1));
    return 0;
}