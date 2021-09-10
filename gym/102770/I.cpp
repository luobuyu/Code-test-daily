#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0;
    char ch = getchar();
    bool f = 1;
    for (; ch > '9' || ch < '0'; ch = getchar())
        if (ch == '-')
            f = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? x : -x;
}
const int N = 1e5 + 2;
int n;
vector<pair<int, int>> sk;
unordered_map<int, int> mp;
vector<int> edge[N];
unordered_map<int, bool> vis;
int dfs(int u, int fa)
{
    vis[u] = 1;
    for (auto &v : edge[u])
    {
        if (!vis[v])
            return 1 + dfs(v, u);
    }
    return 1;
}
int main()
{
    for (int T = read(); T--;)
    {
        n = read();
        sk.clear();
        for (int i = 1; i <= n; ++i)
            sk.emplace_back(read(), read());
        sort(sk.begin(), sk.end());
        int cnt = 0;
        mp.clear();
        for (auto &i : sk)
        {
            if (!mp[i.first])
                mp[i.first] = ++cnt;
            if (!mp[i.second])
                mp[i.second] = ++cnt;
            i.first = mp[i.first];
            i.second = mp[i.second];
        }
        for (int i = 1; i <= n; ++i)
            edge[i].clear();
        for (auto &i : sk)
        {
            edge[i.first].emplace_back(i.second);
            edge[i.second].emplace_back(i.first);
        }
        int ans = 1;
        vis.clear();
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i])
                continue;
            ans = max(ans, dfs(i, 0));
        }
        printf("%d\n", ans);
    }
    return 0;
}