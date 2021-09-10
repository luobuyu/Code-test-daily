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

char str[10][2][10] =
    {
        {"", ""},
        {"2", "13"},
        {"1", "62"},
        {"6", "51"},
        {"5", "46"},
        {"4", "35"},
        {"3", "24"}};

void edge(int index, int n)
{
    printf(str[index][0]);
    n -= 2;
    if(index == 6)
    {
        for(int i = 1; i <= n - 1; i++)
        {
            printf(str[index][1]);
        }
        printf("%c", str[index][1][0]);
        printf("1");
    }
    else
    {
        for(int i = 1; i <= n; i++)
        printf(str[index][1]);
    }
}
void solve(int n)
{
    if(n==2)
    {
        printf("216535");
        return;
    }
    if(n<2)
    {
        return;
    }
    for(int i = 1; i <= 6; i++)
        edge(i, n);
    solve(n - 2);
}

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

    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n);
        solve(n);
        printf("\n");
    }
    return 0;
}