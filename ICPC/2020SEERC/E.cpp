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
const int maxn = 5e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
ll dp[maxn][5][5];
ll a[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i][0][a[i] % 3]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)

        {
            for (int k = 0; k < 3; k++)

            {
                int ans = (j + (a[i] * k) % 3) % 3;
                int sum = (k + a[i]) % 3;
                dp[i][ans][sum] += dp[i - 1][j][k];
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            ans += dp[i][0][k];
        }
    }
    cout << ans << endl;
    return 0;
}