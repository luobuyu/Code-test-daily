#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define fi first
#define se second
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << "\n"
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
const int N = 1e6 + 5;
vector<int> v;
vector<pii> p[10];
int a[N], vis[N];
void dfs(int now)
{
    v.pb(now);
    vis[now] = 1;
    if (!vis[a[now]])
    {
        dfs(a[now]);
    }
}
int main()
{
    // #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        v.clear();
        if (vis[i])
            continue;
        dfs(i);
        if (v.size() == 1)
        {
        }
        else if (v.size() == 2)
        {
            ans = max(ans, 1);
            p[1].pb(pii(v[0], v[1]));
        }
        else
        {
            ans = max(ans, 2);
            for (int i = 1, j = v.size() - 1; i < j; i++, j--)
            {
                p[1].pb(pii(v[i], v[j]));
            }
            p[2].pb(pii(v[0], v[1]));
            for (int i = 2, j = v.size() - 1; i < j; i++, j--)
            {
                p[2].pb(pii(v[i], v[j]));
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= ans; i++)
    {
        printf("%d", p[i].size());
        for (int j = 0; j < p[i].size(); j++)
        {
            printf(" %d %d", p[i][j].first, p[i][j].second);
        }
        printf("\n");
    }

    return 0;
}
