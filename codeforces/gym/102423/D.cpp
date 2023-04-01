#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template<class T> inline void read(T&x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template<class T, class ..._T> inline void read(T&x, _T &...y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
string s[maxn];
map<string, int> mp;
int g[maxn][maxn];
bool vis[maxn];
int type[maxn];
int my[maxn];
bool visy[maxn];
void dfs(int u)
{
    vis[u] = true;
    for(int i = 1; i <= n; i++)
    {
        if(g[u][i] && !vis[i])
        {
            type[i] = !type[u];
            vis[i] = true;
        }
    }
}
struct Edge
{
    int v, next;
}edge[maxm << 1];
int head[maxn], cnt;
inline void addEdge(int u, int v)
{
    ++cnt;
    edge[cnt] = {v, head[u]};
    head[u] = cnt;
}


bool match(int u)
{
    for(int i = head[u]; i ; i = edge[i].next)
    {
        int v = edge[i].v;
        if(!visy[v])
        {
            visy[v] = true;
            if(!my[v] || match(my[v]))
            {
                my[v] = u;
                return true;
            }
        }
    }

    return false;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        mp[s[i]] = i;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < s[i].length(); j++)
        {
            for(int k = j + 1; k <s[i].length(); k++)
            {
                string tmp = s[i];
                swap(tmp[j], tmp[k]);
                if(mp[tmp])
                {
                    g[i][mp[tmp]] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(g[i][j] && type[i] == 0)
            {
                addEdge(i, j);
                //cout << i << "        " << j << endl;
            }
        }
    }

    int ans = 0;
    memset(my, 0, sizeof(my));
    for(int i = 1; i <= n; i++)
    {
        memset(visy, false, sizeof(visy));
        if(match(i)) ans++;
    }
    cout << n - ans << endl;
    return 0;
}