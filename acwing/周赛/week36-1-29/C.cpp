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
const int maxn = 2e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
// 看成 右 上
PII a[maxn];
string s;
int ex, ey;
bool check(int mid)
{
    if (mid > n)
        return false;
    int sx, sy, need;
    // 长度是 len
    for (int i = 1; i <= n - mid + 1; i++)
    {
        // start = i, end = i + mid - 1
        sx = a[i - 1].first + a[n].first - a[i + mid - 1].first;
        sy = a[i - 1].second + a[n].second - a[i + mid - 1].second;
        need = abs(sx - ex) + abs(sy - ey);
        if (need <= mid && (mid - need) % 2 == 0)
        {
            return true;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> s;
    cin >> ex >> ey;
    for (int i = 1; i <= s.length(); i++)
    {
        a[i].first = a[i].second = 0;
        if (s[i - 1] == 'R')
        {
            a[i].first = 1;
        }
        else if (s[i - 1] == 'L')
        {
            a[i].first = -1;
        }
        else if (s[i - 1] == 'U')
        {
            a[i].second = 1;
        }
        else
        {
            a[i].second = -1;
        }
    }
    // 求个前缀和
    for (int i = 1; i <= n; i++)
    {
        a[i].first += a[i - 1].first;
        a[i].second += a[i - 1].second;
    }
    int l = 0, r = n;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}