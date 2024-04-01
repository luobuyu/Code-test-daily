// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
vector<int> g[maxn];
vector<pair<int, int>> ans;
// 假设全弄成偶数，如果一个节点 u，子树中存在奇数节点，那么u,v需要操作
void dfs(int u, int fa)
{
    for (int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        if (a[v] & 1)
        {
            a[u]++;
            a[v]++;
            ans.emplace_back(u, v);
        }
    }
}

void init()
{
    ans.clear();
    for (int i = 1; i <= n; ++i)
    {
        g[i].clear();
    }
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tcase;
    cin >> tcase;
    while (tcase--)
    {
        cin >> n;
        init();
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            cnt += (a[i] & 1);
        }
        for (int i = 1, u, v; i < n; ++i)
        {
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        if (cnt & 1)
        {
            cout << "No" << endl;
        }
        else
        {
            dfs(1, 0);
            cout << "Yes" << endl;
            cout << ans.size() << endl;
            for (auto &[u, v] : ans)
            {
                cout << u << " " << v << endl;
            }
        }
    }
    return 0;
}