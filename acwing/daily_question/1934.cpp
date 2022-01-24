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
int n, m;
vector<int> d;
vector<int> t;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    char ch;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> ch >> x;
        if (ch == 'T')
        {
            t.push_back(x);
        }
        else
        {
            d.push_back(x);
        }
    }
    d.push_back(1000);
    sort(t.begin(), t.end());
    sort(d.begin(), d.end());
    double ans = 0, already = 0;
    int l1 = 0, l2 = 0, v = 1;
    while (l2 < t.size() && l1 < d.size())
    {
        double tmp = (d[l1] - already) * v - (t[l2] - ans);
        if (tmp == 0)
        {
            ans = t[l2];
            already = d[l1];
            l1++, l2++;
            v++;
            v++;
        }
        else if (tmp > 0)
        {
            already += (t[l2] - ans) / v;
            ans = t[l2];
            l2++;
            v++;
        }
        else
        {
            ans += (d[l1] - already) * v;
            already = d[l1];
            l1++;
            v++;
        }
    }

    while (l1 < d.size())
    {
        ans += (d[l1] - already) * v;
        already = d[l1];
        l1++;
        v++;
    }
    printf("%.0f\n", ans);
    return 0;
}