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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn], b[maxn];
ll sufSumA[maxn], sufSumB[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    unordered_map<int, int> mpa;
    unordered_map<int, int> mpb;
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        mpa[a[i]]++;
    }
    for (int i = 1; i <= m; ++i)
    {
        mpb[b[i]]++;
    }
    for (int i = n; i >= 1; --i)
    {
        if (a[i] == a[i + 1])
            sufSumA[i] = sufSumA[i + 1];
        else
            sufSumA[i] = sufSumA[i + 1] + mpa[a[i]];
    }
    for (int i = m; i >= 1; --i)
    {
        if (b[i] == b[i + 1])
            sufSumB[i] = sufSumB[i + 1];
        else
            sufSumB[i] = sufSumB[i + 1] + mpb[b[i]];
    }
    ll sumb = 0;
    for (int i = 1; i <= m; ++i)
    {
        sumb += sufSumB[i];
    }
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += sufSumA[i] * sumb;
    }
    cout << sum << endl;
    return 0;
}