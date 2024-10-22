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
vector<vector<int>> g;

int getLen(vector<int> &v, int n)
{
    int size = v.size();
    int cnt = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < size; ++r)
    {
        if (r - 1 >= l)
        {
            cnt += v[r] - v[r - 1] - 1;
        }
        while (l <= r && cnt > k)
        {
            if (l + 1 <= r)
            {
                cnt -= v[l + 1] - v[l] - 1;
            }
            ++l;
        }
        int tmp = v[r] - v[l] + 1;
        ans = max(ans, tmp + min(n - tmp, k - cnt));
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
    cin >> n >> m >> k;
    g.resize(m + 1);
    for (int i = 0, x; i < n; ++i)
    {
        cin >> x;
        g[x].emplace_back(i);
    }
    int ans = 0;
    for (auto &v : g)
    {
        if (v.size() == 0)
            continue;
        ans = max(ans, getLen(v, n));
    }
    cout << ans << endl;
    return 0;
}