// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
ll a[maxn][maxn];

int my[maxn];                                  // 右侧匹配的左侧点
ll lx[maxn], ly[maxn], slack[maxn], pre[maxn]; // lx,ly顶标
bool visx[maxn], visy[maxn];                   // 是否访问过

void bfs(ll u)
{
    ll x, y = 0, yy = 0, delta;
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++)
        slack[i] = INF;
    my[y] = u;
    while (true)
    {
        x = my[y];
        delta = INF;
        visy[y] = true;
        for (int i = 1; i <= n; ++i)
        {
            if (visy[i])
                continue;
            if (slack[i] > lx[x] + ly[i] - a[x][i])
            {
                slack[i] = lx[x] + ly[i] - a[x][i];
                pre[i] = y;
            }
            if (slack[i] < delta)
            {
                delta = slack[i];
                yy = i;
            }
        }

        for (int i = 0; i <= n; ++i)
        {
            if (visy[i])
            {
                lx[my[i]] -= delta;
                ly[i] += delta;
            }
            else
            {
                slack[i] -= delta;
            }
        }
        y = yy;
        if (my[y] == -1)
            break;
    }
    while (y)
    {
        my[y] = my[pre[y]];
        y = pre[y];
    }
}
ll km()
{
    memset(my, -1, sizeof(my));
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    for (int i = 1; i <= n; i++)
    {
        memset(visy, 0, sizeof(visy));
        bfs(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (my[i] != -1)
            ans += a[my[i]][i];
    }
    return ans;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    read(n, m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = -INF;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        read(u, v, w);
        a[u][v] = w;
    }
    cout << km() << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << my[i] << " ";
    }
    return 0;
}