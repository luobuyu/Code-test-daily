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
vector<PII> a;
vector<PII> b;
string s;
int g[maxn][maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tcase;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        a.clear();
        b.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                if (s[j] == 'm')
                {
                    a.push_back({i, j});
                }
                else if (s[j] == 'H')
                {
                    b.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < a.size(); ++i)
        {
            for (int j = 0; j < a.size(); j++)
            {
                g[i][j] = -INF;
            }
        }

        for (int i = 0; i < a.size(); ++i)
        {
            for (int j = 0; j < b.size(); ++j)
            {
                g[i][j] = -abs(a[i].first - b[j].first) - abs(a[i].second - b[j].second);
            }
        }
        int ans = 0;
        for (int i = 0; i < a.size(); ++i)
        {
            int maxx = -INF;
            int maxi, maxj;
            for (int j = 0; j < a.size(); ++j)
            {
                for (int k = 0; k < a.size(); ++k)
                {
                    if (g[j][k] > maxx)
                    {
                        maxx = g[j][k];
                        maxi = j;
                        maxj = k;
                    }
                }
            }
            ans += maxx;
            for (int j = 0; j < a.size(); j++)
            {
                g[maxi][j] = -INF;
                g[j][maxj] = -INF;
            }
        }
        cout << -ans << endl;
    }

    return 0;
}