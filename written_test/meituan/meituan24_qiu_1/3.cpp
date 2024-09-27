#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, q, k;
long long a[maxn];
bool flag[maxn];
vector<int> g[maxn];
void dfs(int u, int fa)
{
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v, u);
        if(!flag[u] && !flag[v])
        {
            long long tmp = sqrt(a[u] * a[v]);
            if(tmp * tmp == a[u] * a[v])
            {
                flag[u] = flag[v] = true;
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        flag[i] = false;
    }
    for (int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, -1);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += flag[i];
    }
    cout << ans << endl;
        return 0;
}