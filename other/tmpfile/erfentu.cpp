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
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int minz;
int lx[maxn], ly[maxn];      // 顶标
bool visx[maxn], visy[maxn]; // 标记
int mx[maxn], my[maxn];      // 匹配的点，找增广路用
int colorg[maxn][maxm];      // 存图

int sol[2][maxn];
inline bool dfs(int u)
{
    visx[u] = true;

    for (int i = 0; i < n; i++)
    {
        if (!visy[i] && colorg[u][i] != 0)
        {
            int t = lx[u] + ly[i] - colorg[u][i];
            if (t == 0)
            {
                visy[i] = true;
                if (my[i] == -1 || dfs(my[i]))
                {
                    mx[u] = i;
                    my[i] = u;
                    return true;
                }
            }
            else if (t > 0)
                minz = min(t, minz);
        }
    }
    return false;
}

int km(int p1, int p2)
{

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            colorg[i][j] = 0;
    for (int i = 0; i < m; ++i)
    {
        colorg[sol[p1][i]][sol[p2][i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        lx[i] = 0;
        ly[i] = 0;
        mx[i] = -1;
        my[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            lx[i] = max(lx[i], colorg[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            minz = INF;
            memset(visx, false, sizeof(visx));
            memset(visy, false, sizeof(visy));

            if (dfs(i))
                break;
            for (int j = 0; j < n; j++)
            {
                if (visx[j])
                    lx[j] -= minz;
                if (visy[j])
                    ly[j] += minz;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mx[i] != -1)
            ans += colorg[i][mx[i]];
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
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, x; j < m; j++)
        {
            cin >> x;
            sol[i][j] = x;
        }
    }
    n = k;
    int ans = km(0, 1);
    cout << ans << endl;
    cout << "---------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << mx[i] << " ";
    }
    cout << endl;
    return 0;
}