#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
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
const int maxn = 2e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
char str[maxn];
int a[maxn];
int p[2][maxn], s[2][maxn];
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
        read(n, m);
        scanf("%s", str + 1);
        p[0][0] = p[1][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (str[i] == '-')
                a[i] = a[i - 1] - 1;
            else
                a[i] = a[i - 1] + 1;
            p[0][i] = min(a[i], p[0][i - 1]);
            p[1][i] = max(a[i], p[1][i - 1]);
        }
        s[0][n + 1] = INF;
        s[1][n + 1] = -INF;
        for (int i = n; i >= 1; i--)
        {
            s[0][i] = min(a[i], s[0][i + 1]);
            s[1][i] = max(a[i], s[1][i + 1]);
        }
        int l, r;
        int ans = 0;
        while (m--)
        {
            read(l, r);
            int l1 = p[0][l - 1];
            int r1 = p[1][l - 1];
            int l2 = s[0][r + 1];
            int r2 = s[1][r + 1];

            if (r2 == -INF)
            {
                ans = r1 - l1 + 1;
            }
            else
            {
                int up = r2 - a[r];
                int down = a[r] - l2;
                int lans = min(l1, a[l - 1] - down);
                int rans = max(r1, a[l - 1] + up);
                ans = rans - lans + 1;
            }
            cout << ans << endl;
        }
    }
    return 0;
}