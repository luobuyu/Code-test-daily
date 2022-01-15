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
const int maxn = 1e2 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
int cnt;
bool vis[maxn];
bool cmp(int x, int y)
{
    return x > y;
}

bool dfs(int step, int curLen, int maxLen, int num)
{
    if (num >= cnt)
        return true;
    if (curLen == maxLen)
        return dfs(0, 0, maxLen, num + 1);
    int fail = 0;
    for (int i = step; i < n; i++)
    {
        if (!vis[i] && a[i] != fail && (curLen + a[i] <= maxLen))
        {
            vis[i] = true;
            if (dfs(i + 1, curLen + a[i], maxLen, num))
            {
                return true;
            }
            vis[i] = false;
            fail = a[i];
            if (curLen == 0 || curLen + a[i] == maxLen)
                return false;
        }
    }
    return false;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d", &n) && n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + n, cmp);
        for (int i = a[0]; i <= sum; i++)
        {
            if (sum % i)
                continue;
            cnt = sum / i;
            memset(vis, 0, sizeof(vis));
            if (dfs(0, 0, i, 0))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}