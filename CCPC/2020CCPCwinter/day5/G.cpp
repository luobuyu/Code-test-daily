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
const double eqs = 1e-5;
const int maxn = 1e6 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
ll p;
ll inv[maxn];
vector<pair<int, ll>> ans;
unordered_map<ll, ll> mp;
void init(int n, ll mod)
{
    inv[0] = inv[1] = 1;
    ll minx = INF_LL;
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        minx = min(minx, inv[i]);
        if (minx == inv[i])
        {
            if (!mp.count(inv[i]))
            {
                ans.push_back({i, inv[i]});
                mp[i] = inv[i];
            }
            else
            {
                break;
            }
        }
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(p);
        mp.clear();
        ans.clear();
        if (p <= 2)
        {
            printf("0\n");
            continue;
        }
        init(1e5, p);
        int t = ans.size();
        for (int i = 0; i < t; i++)
        {
            if (ans[i].first == ans[i].second)
                continue;
            ans.push_back({ans[i].second, ans[i].first});
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for (auto x : ans)
        {
            printf("%d %lld\n", x.first, x.second);
        }
    }
    return 0;
}