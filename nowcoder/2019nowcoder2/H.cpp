#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
    {
        return read(x), read(y...);
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
int a[maxn][maxn];
int lef[maxn][maxn], righ[maxn][maxn], height[maxn][maxn];
int ans = -1, maxans = -1;
char ch[maxn];


void change(int tmp)
{
    if(tmp >= maxans)
    {
        ans = maxans;
        maxans = tmp;
    }
    else if(tmp > ans)
    {
        ans = tmp;
    }
}

struct node
{
    int lx, rx;
    node(int _lx, int _rx)
    {
        lx = _lx;
        rx = _rx;
    }
    bool operator<(const node &b) const
    {
        return lx < b.lx || (lx == b.lx && rx < b.rx);
    }
};
set<node> s;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    read(n, m);
    
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", ch + 1);
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = ch[j] - '0';
            if (a[i][j])
                height[i][j] = 1,
                lef[i][j] = righ[i][j] = j;
        }
    }

    // 对行进行递推	左
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (a[i][j] == a[i][j - 1] && a[i][j] == 1)
            {
                lef[i][j] = lef[i][j - 1];
            }
        }
    }
    // 对行进行递推	右
    for (int i = 1; i <= n; i++)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (a[i][j] == a[i][j + 1] && a[i][j] == 1)
                righ[i][j] = righ[i][j + 1];
        }
    }
    // 对列进行递推	列
    // 每次递推一行

    for (int i = 1; i <= n; i++)
    {
        s.clear();
        for (int j = 1; j <= m; j++)
        {
            if (i > 1 && a[i][j] == a[i - 1][j] && a[i][j] == 1)
            {
                height[i][j] = height[i - 1][j] + 1;
                lef[i][j] = max(lef[i][j], lef[i - 1][j]);
                righ[i][j] = min(righ[i][j], righ[i - 1][j]);
            }
            int x = righ[i][j] - lef[i][j] + 1;
            int y = height[i][j];
            int tmp = x * y;
            if(s.find({lef[i][j], righ[i][j]}) == s.end()) 
            {
                s.insert({lef[i][j], righ[i][j]});
                change(tmp);
                change(tmp - x);
                change(tmp - y);
            }
        }
    }
    if (ans == -1)
        printf("0\n");
    else
        printf("%d\n", ans);
    return 0;
}