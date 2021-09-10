#include <bits/stdc++.h>
#define ll long long
#define lll __int128
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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
bool vis[maxn];
vector<pair<int, int>> ans[3];
vector<int> tmp;

void dfs(int i)
{
    vis[i] = 1;
    tmp.push_back(i);
    if (!vis[a[i]])
    {
        dfs(a[i]);
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    int maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp.clear();
        if (a[i] == i)
        {
            vis[i] = 1;
            continue;
        }
        if (vis[i])
            continue;
        dfs(i);
        if (tmp.size() == 2)
        {
            maxx = max(maxx, 1);
            ans[1].push_back({tmp[0], tmp[1]});
        }
        else
        {
            maxx = max(maxx, 2);
            for (int i = 1, j = tmp.size() - 1; i < j; i++, j--)
            {
                ans[1].push_back({tmp[i], tmp[j]});
                swap(tmp[i], tmp[j]);
            }
            for (int i = 0, j = tmp.size() - 1; i < j; i++, j--)
            {
                ans[2].push_back({tmp[i], tmp[j]});
            }
        }
    }

    printf("%d\n", maxx);
    for (int i = 1; i <= maxx; i++)
    {
        printf("%d ", ans[i].size());
        for (int j = 0; j < ans[i].size(); j++)
        {
            printf("%d %d%c", ans[i][j].first, ans[i][j].second, " \n"[j == (ans[i].size() - 1)]);
        }
    }
    return 0;
}