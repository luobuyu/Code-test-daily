#include <bits/stdc++.h>
#define ll long long
#define lll long long
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

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
char g[maxn][maxn];
bool vis[maxn][maxn];
int ans;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void dfs(int x, int y, int l, int r)
{
    if (l > 0 && l == r)
    {
        ans = max(ans, l + r);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx < 0 || newx >= n || newy < 0 || newy >= n || vis[newx][newy])
            continue;
        if (r != 0 && g[newx][newy] == '(')
            continue;
        vis[newx][newy] = true;
        if (g[newx][newy] == '(')
        {
            dfs(newx, newy, l + 1, r);
        }
        else
        {
            dfs(newx, newy, l, r + 1);
        }
        vis[newx][newy] = false;
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

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    if (g[0][0] == ')')
        puts("0");
    else
    {
        vis[0][0] = true;
        dfs(0, 0, 1, 0);
        cout << ans << endl;
    }
    return 0;
}