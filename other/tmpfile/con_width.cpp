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

vector<int> tmp;
set<int> s;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int minx = 0, maxx = 0;
    int area = 0;
    double mind = INF;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
        int l = min(a[i][0], a[i][1]);
        int r = max(a[i][0], a[i][1]);
        minx = max(minx, r);
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
    s.insert(a[1][0]);
    s.insert(a[1][1]);
    for (int i = 2; i <= n; i++)
    {
        tmp.clear();
        for (int j = 1; j <= maxx; j++)
        {
            if (s.count(j))
                continue;
            int x = j - a[i][0], y = j - a[i][1];
            if (x >= 0 && s.count(x) || y >= 0 && s.count(y))
            {
                tmp.push_back(j);
            }
        }
        tmp.push_back(a[i][0]);
        tmp.push_back(a[i][1]);
        for (auto x : tmp)
        {
            if (!s.count(x))
            {
                s.insert(x);
            }
        }
    }
    // todo, 可能是先插入minx，后面遍历的时候又遇到了。

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

    return 0;
}