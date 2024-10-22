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
struct Node
{
    ll x, times;
    void getTimes()
    {
        int xx = x;
        while ((xx & 1) == 0)
        {
            xx >>= 1;
            times++;
        }
    }
    Node() {}
    Node(ll _x) : x(_x), times(0) {}
};
vector<Node> a;
vector<Node> b;
int solve()
{
    cin >> n;
    a.clear();
    b.clear();
    for (ll i = 1, x; i <= n; ++i)
    {
        cin >> x;
        if (x & 1)
        {
            a.emplace_back(x);
        }
        else
        {
            b.emplace_back(x);
            b.back().getTimes();
        }
    }
    // sort(b.begin(), b.end(), [&](const Node &x, const Node &y)
    //      { return x.times > y.times; });
    ll minx = INF_LL;
    for (auto &x : b)
    {
        minx = min(minx, x.times);
    }
    // 小的留着，大的和奇数加
    ll ans = 0;
    if (a.size())
    {
        ans = b.size();
    }
    else
    {
        ans += minx;
        ans += n - 1;
    }
    return ans;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tcase;
    cin >> tcase;
    while (tcase--)
    {
        cout << solve() << endl;
    }
    return 0;
}