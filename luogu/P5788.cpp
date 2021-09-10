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
const int maxn = 3e6 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

int ans[maxn];
struct Node
{
    int x, id;
};
Node st[maxn];
int top = 0;
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

    read(n);
    int x;
    for (int i = 1; i <= n; i++)
    {
        read(x);
        while (top > 0 && st[top].x < x)
        {
            ans[st[top--].id] = i;
        }
        st[++top] = {x, i};
    }

    while(top>0)
    {
        ans[st[top--].id] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}