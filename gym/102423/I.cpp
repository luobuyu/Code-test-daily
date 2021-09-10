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
const int maxm = 1e3 + 10;
int t, n, m, k;
string s[maxn];
int nextx[10] = {0, 0, 1, 0, -1};
int nexty[10] = {0, 1, 0, -1, 0};

void dfs(int x, int y)
{
    s[x][y] = '9';
    for(int i = 1; i <= 4; i++)
    {
        int newx = x + nextx[i];
        int newy = y + nexty[i];
        if(newx >= 1 && newx <= n && newy >= 1 && newy <= m)
        {
            if(s[newx][newy] == '.')
            {
                s[newx][newy] = '9';
                dfs(newx, newy);
            }
        }
    }
    if(x-1 >= 1 && y + 1 <= m)
    if(!(s[x][y+1] == '\\' && s[x-1][y] == '\\') && s[x-1][y+1] == '.')
    {
        s[x-1][y+1] = '9';
        dfs(x-1, y + 1);
    }
    if(x+1 <= n && y + 1 <= m)
    if(!(s[x+1][y] == '/' && s[x][y+1] == '/') && s[x+1][y+1] == '.')
    {
        s[x+1][y+1] = '9';
        dfs(x + 1, y + 1);
    }

    if(x+1<=n && y-1>=1)
    if(!(s[x+1][y] == '\\' && s[x][y-1] == '\\') && s[x+1][y-1] == '.')
    {
        s[x+1][y-1] = '9';
        dfs(x+1, y-1);
    }
    if(x-1>=1 && y-1>=1)
    if(!(s[x-1][y] == '/' && s[x][y-1] == '/') && s[x-1][y-1] == '.')
    {
        s[x-1][y-1] = '9';
        dfs(x-1, y-1);
    }
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

    read(n, m);
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(s[i][j] == '/' && s[i][j+1] == '\\' && s[i+1][j] == '\\' && s[i+1][j+1]=='/')
            {
                ans++;
            }   
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == 1 || i == n || j == 1 || j == m)
            {
                if(s[i][j] == '.')
                {
                    dfs(i, j);
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i][j] == '.')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}