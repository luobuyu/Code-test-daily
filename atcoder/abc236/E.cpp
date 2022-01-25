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
const int maxn = 1e1 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
ll a[maxn];
ll b[maxn];
ll dp[2][maxn];
ll check()
{
    // dp[0] 取
    // dp[1] 不取
    dp[0][0] = dp[1][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]) + b[i];
        dp[1][i] = dp[0][i - 1];
    }
    return max(dp[0][n], dp[1][n]);
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
    ll r = -1;
    ll l = INF_LL;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
        l = min(l, a[i]);
    }
    ll r1 = r * 1000, l1 = l * 1000;
    ll ans1 = -1;
    while (l1 <= r1)
    {
        ll mid = (r1 + l1) >> 1;
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i] * 1000 - mid;
        }
        if (check() >= 0)
        {
            ans1 = mid;
            l1 = mid + 1;
        }
        else
        {
            r1 = mid - 1;
        }
    }
    int ans2 = -1;
    int l2 = l, r2 = r;
    while (l2 <= r2)
    {
        int mid = l2 + ((r2 - l2) >> 1);
        for (int i = 1; i <= n; i++)
        {
            b[i] = (a[i] >= mid ? 1 : -1);
        }
        if (check() > 0)
        {
            ans2 = mid;
            l2 = mid + 1;
        }
        else
        {
            r2 = mid - 1;
        }
    }
    printf("%.9f\n%d\n", ans1 * 1.0 / 1000, ans2);
    return 0;
}
