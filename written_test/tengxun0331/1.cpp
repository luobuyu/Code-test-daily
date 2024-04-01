#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
int n, m, q, k;
vector<pair<int, int>> g[maxn];
bool flag[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    int u, v;
    char ch;
    
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> ch;
        if(ch == 'W')
        {
            flag[u] = 1;
            flag[v] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if(!flag[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;   
}