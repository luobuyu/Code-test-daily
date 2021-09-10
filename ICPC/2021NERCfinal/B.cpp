#include <bits/stdc++.h>
#define ll long long
#define lll long long
using namespace std;
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

    void FIO()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }

} // namespace FAST_IO
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int d;
int a[maxn];
int match[maxn];
bool vis[maxn];
vector<int> g[maxn];
vector<int> v;
bool cmp(int x, int y)
{
    return __builtin_popcount(x) > __builtin_popcount(y);
}

bool find(int x)
{
    for (int i = 0; i < g[x].size(); i++)
    {
        int v = g[x][i];
        if (!vis[v])
        {
            vis[v] = 1;
            if (!match[v] || find(match[v]))
            {
                match[v] = x;
                return true;
            }
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
    FIO();
    cin >> d >> n;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = d - 1; j >= 0; j--)
        {
            a[i] = a[i] * 2 + (s[j] - '0');
        }
    }

    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if ((a[i] & a[j]) == a[i])
                g[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        find(i);
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int x, y;
            vis[i] = 1;
            v.push_back(-1);
            int pre = a[i], pos = match[i];
            while (pos)
            {
                vis[pos] = 1;
                int cur = a[pos];
                for (int j = 0; j < d; ++j)
                {
                    if (((pre ^ cur) >> j) & 1)
                        v.push_back(j);
                }
                pre = cur;
                pos = match[pos];
            }
            for (int j = 0; j < d; ++j)
            {
                if ((pre >> j) & 1)
                    v.push_back(j);
            }
        }
    }

    cout << v.size() - 1 << endl;
    while (v.size() > 1)
    {
        int x = v.back();
        v.pop_back();
        if (x == -1)
            cout << "R ";
        else
            cout << x << " ";
    }
    cout << endl;
    return 0;
}
