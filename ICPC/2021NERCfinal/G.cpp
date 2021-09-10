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
const int maxn = 1e2 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
vector<int> g[maxn];
vector<int> lon;
vector<int> ans;
bool flag[maxn];
int dep[maxn];
void init()
{
    ans.clear();
    lon.clear();
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        flag[i] = 0;
    }
}
void getDep(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (v == fa)
            continue;
        getDep(v, u);
    }
}

void getLongest(int u, int fa)
{
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (v == fa)
            continue;
        if (dep[v] == dep[u] - 1)
        {
            lon.push_back(v);
            flag[v] = true;
            getLongest(v, u);
        }
    }
}

void dfs(int u, int *cot, int fa)
{
    ans.push_back(u);
    if ((*cot) == 0)
        return;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (flag[v] || v == fa)
            continue;
        (*cot)--;
        dfs(v, cot, u);
        ans.push_back(u);
        if ((*cot) == 0)
            break;
    }
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    while (tcase--)
    {
        cin >> n >> k;
        init();
        for (int i = 1, x; i < n; i++)
        {
            read(x);
            g[x].push_back(i + 1);
            g[i + 1].push_back(x);
        }
        dep[0] = -1;
        getDep(1, 0);
        int maxdep = -1, index = -1;
        for (int i = 1; i <= n; i++)
        {
            if (dep[i] > maxdep)
            {
                maxdep = dep[i];
                index = i;
            }
        }
        lon.push_back(index);
        flag[index] = true;
        getLongest(index, 0);
        reverse(lon.begin(), lon.end());
        if (maxdep + 1 >= k)
        {
            // cout << k - 1 << endl;
            printf("%d\n", k - 1);

            for (int i = 0; i < k; i++)
            {
                printf("%d%c", lon[i], " \n"[i == k - 1]);
            }
        }
        else
        {
            int extra = k - maxdep - 1;
            int fa = -1;
            for (int i = 0; i < lon.size(); i++)
            {
                if (extra != 0)
                {
                    dfs(lon[i], &extra, fa);
                }
                else
                {
                    ans.push_back(lon[i]);
                }
            }
            int ansv = maxdep + (k - maxdep - 1) * 2;
            printf("%d\n", ansv);
            for (int i = 0; i < ans.size(); i++)
            {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }
    }

    // ans = dep + (k - dep - 1) * 2
    return 0;
}