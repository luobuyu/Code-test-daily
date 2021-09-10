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
const int maxn = 2e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
bool vis[maxn];
int ans[maxn];
int cnt;
// 直接dfs搜索，遇到搜过的返回
void dfs(int x)
{
    if (vis[x])
        return;
    vis[x] = 1;
    cnt++;        // 记录环的大小
    dfs(a[x]);    // 下一步
    ans[x] = cnt; // 待递归返回后得到了cnt，记录答案
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
            vis[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                cnt = 0, dfs(i);
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}