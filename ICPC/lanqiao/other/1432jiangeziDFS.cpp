#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
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
int dx[5] = {-1, 0, 1, 0}, dy[5] = {0, 1, 0, -1};
int a[maxn][maxn];
bool vis[maxn][maxn];
int ans = INF;
int sum = 0;
int tmp = 1;
void dfs(int x, int y, int now, int cnt)
{
    if(now == sum / 2)
    {
        ans = min(ans, cnt);
        return;
    }else if(now > sum / 2) return;
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(newx < 0 || newy < 0 || newx >= n || newy >= m || vis[newx][newy]) continue;
        vis[newx][newy] = 1;
        dfs(newx, newy, now + a[newx][newy], cnt+1);
        vis[newx][newy] = 0;
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(m, n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            read(a[i][j]);
            sum += a[i][j];
        }
    }
    dfs(0, 0, a[0][0], 1);
    if(sum & 1 || ans == INF) ans = 0;
    printf("%d\n", ans);
    return 0;
}