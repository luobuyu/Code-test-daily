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
int a[maxn][3];
int minx, maxx;
vector<int> ans;
bool check(int len)
{
    vector<int> dp(len + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = len; j >= 0; j--)
        {
            for (int k = 0; k <= 1; k++)
            {
                if (j >= a[i][k])
                    dp[j] = max(dp[j], dp[j - a[i][k]] + a[i][k]);
            }
        }
    }
    return dp[len] == len;
}

int testTWO()
{
    int f[maxn][maxn];
    for (int i = 0; i <= n; i++)
    {
        f[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= maxx; j++)
        {
            f[i][j] |= f[i - 1][j];
            if (j - a[i][0] >= 0)
                f[i][j] |= f[i - 1][j - a[i][0]];
            if (j - a[i][1] >= 0)
                f[i][j] |= f[i - 1][j - a[i][1]];
        }
    }
    int ppp = 0;
    for (int i = minx; i <= maxx; ++i)
    {
        if (f[n][i] == 1)
            ppp++;
    }
    cout << ppp << endl;
}

void testONE()
{
    cout << "--------one-----------" << endl;
    int f[maxn] = {0};
    for (int i = 1; i <= maxx; i++)
        f[i] = 0;
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = maxx; j >= 1; j--)
        {
            if (j - a[i][0] >= 0)
                f[j] |= f[j - a[i][0]];
            if (j - a[i][1] >= 0)
                f[j] |= f[j - a[i][1]];
        }
    }
    int ppp = 0;
    for (int i = minx; i <= maxx; ++i)
    {
        if (f[i] == 1)
            ppp++;
    }
    cout << ppp << endl;
}

vector<int> tmp;
set<int> s;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("out.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    minx = 0, maxx = 0;
    int area = 0;
    double mind = INF;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        int l = min(a[i][0], a[i][1]);
        int r = max(a[i][0], a[i][1]);
        minx = max(minx, l);
        area += a[i][0] * a[i][1];
        maxx += r;
    }
    cout << "area = " << area << endl;
    maxx = 1.05 * sqrt(area);
    // maxx = 100;
    clock_t startTime, endTime;
    startTime = clock();
    for (int i = minx; i <= maxx; i++)
    {
        if (check(i))
        {
            ans.push_back(i);
        }
    }
    endTime = clock();
    cout << (endTime - startTime) * 1.0 / CLOCKS_PER_SEC << endl;

    startTime = clock();

    s.insert(0);
    for (int j = 1; j <= n; j++)
    {
        for (int i = maxx; i >= 1; i--)
        {
            int x = i - a[j][0], y = i - a[j][1];
            if (s.count(x) || s.count(y))
            {
                s.insert(i);
            }
        }
    }

    int cnt = 0;
    for (auto x : s)
    {
        if (x >= minx && x <= maxx)
        {
            cnt++;
        }
    }
    endTime = clock();
    cout << (endTime - startTime) * 1.0 / CLOCKS_PER_SEC << endl;
    cout << cnt << endl;
    cout << "-----------------" << endl;
    cout << ans.size() << "  " << maxx - minx + 1 << endl;
    cout << minx << "   " << maxx << endl;
    testTWO();
    testONE();
    return 0;
}