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
const int maxn = 1e6 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
ll remain[maxn];
struct Node
{
    int d, s, t;
};
Node a[maxn];
ll tmp[maxn];
bool check(int mid)
{
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < mid; ++i)
    {
        tmp[a[i].s] += a[i].d;
        tmp[a[i].t + 1] -= a[i].d;
    }
    for (int i = 1; i <= n; ++i)
    {
        tmp[i] += tmp[i - 1];
        if (tmp[i] > remain[i])
            return false;
    }
    return true;
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
    for (int i = 1; i <= n; ++i)
    {
        read(remain[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        read(a[i].d, a[i].s, a[i].t);
    }
    int l = 0, r = m - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    if (ans == -1)
        cout << 0 << endl;
    else
    {
        cout << -1 << endl;
        cout << ans << endl;
    }
    return 0;
}