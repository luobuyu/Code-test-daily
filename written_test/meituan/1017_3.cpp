#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;

int n, q, x, y;
vector<int> g[maxn];
int a[maxn];
ll dp[maxn];

int indeg[maxn];
int vis[maxn]; // 0, 1, 2
int st[maxn];
int top = -1;
int circle_cnt = 1;
int circle_id[maxn];

ll dfs(int u)
{
    vis[u] = 1;
    st[++top] = u;
    ll dis = 0;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if(a[v] > a[u])
            dis += x;
        else
            dis += y;
        if(vis[v] == 0) {
            dis = max(dis, dis + dfs(v));
        } else if(vis[v] == 1) {
            while(top != -1) {
                circle_id[st[top]] = circle_cnt;
                --top;
            }
            circle_cnt++;
        }
    }
    vis[u] = 2;
    --top;
    dp[u] = dis;
    return dis;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> q >> x >> y;
    for (int i = 1, v; i <= n; ++i) {
        cin >> v;
        indeg[v]++;
        g[i].emplace_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if(vis[i] == 0)
            dfs(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << i << "< " << dp[i] << endl;
    }

    return 0;
}