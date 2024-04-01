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
long long dp[maxn][maxn];
long long a[maxn][maxn];
int dx[] = {1, 1, 2, 2};
int dy[] = {-2, 2, -1, 1};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];

    long long ans = 0;
    for (int j = 2; j <= n; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            // 上一步向右2
            if (j - 2 >= 1)
            {
                if (i + 1 <= n && dp[i + 1][j - 2] != 0)
                    dp[i][j] = max(dp[i + 1][j - 2] + a[i][j], dp[i][j]);
                if (i - 1 >= 1 && dp[i - 1][j - 2] != 0)
                    dp[i][j] = max(dp[i - 1][j - 2] + a[i][j], dp[i][j]);
            }
            // 上一步右1
            if (j - 1 >= 1)
            {
                if (i + 2 <= n && dp[i + 2][j - 1] != 0)
                    dp[i][j] = max(dp[i + 2][j - 1] + a[i][j], dp[i][j]);
                if (i - 2 >= 1 && dp[i - 2][j - 1] != 0)
                    dp[i][j] = max(dp[i - 2][j - 1] + a[i][j], dp[i][j]);
            }
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}