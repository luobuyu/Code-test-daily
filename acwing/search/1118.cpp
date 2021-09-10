#include <bits/stdc++.h>
#define ll long long
#define lll __int128
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
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
vector<int> g[maxn];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
bool vis[maxn];
int ans = INF;
void dfs(int step, int cnt)
{
    if (step == n + 1)
    {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 0; i < cnt; i++)
    {

        bool flag = true;
        for (int j = 0; j < g[i].size(); j++)
        {
            int gc = gcd(a[step], g[i][j]);
            if (gc != 1)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            g[i].push_back(a[step]);
            dfs(step + 1, cnt);
            g[i].pop_back();
        }
    }
    g[cnt].push_back(a[step]);
    dfs(step + 1, cnt + 1);
    g[cnt].pop_back();
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}