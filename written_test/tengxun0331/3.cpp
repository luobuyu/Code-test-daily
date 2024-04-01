#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
int n, m, q, k;
vector<int> g[maxn];
bool vis[maxn];

void dfs(int u, int fa, int& cnt)
{
    vis[u] = true;
    ++cnt;
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if(v == fa || vis[v]) continue;
        dfs(v, u, cnt);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int cnt = 0;
    vector<int> tmp;
    for (int i = 1; i <= n; ++i)
    {
        int size = 0;
        if(!vis[i])
        {
            dfs(i, 0, size);
            tmp.emplace_back(size);
        }
    }
    if(tmp.size() != 2) {
        cout << 0 << endl;
    }
    else{
        cout << 1ll * tmp[0] * tmp[1] << endl;
    }

    return 0;
}