#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int read()
{
    int x = 0, flag = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    }
    if (flag)
        return -x;
    return x;
}
int t, n, m, k;
int a[maxn];
int st[maxn], top = 0;
void solve()
{
    for(int i = 1; i <= n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    top = 0;
    for (int i = 1; i <= n; i++)
    {
        while(top>0 && a[i]<st[top])
        {
            top--;
        }
        st[++top] = a[i];
        printf("%d", top);
    }
    printf("\n");
    // printf("\n------------------------\n");
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
    freopen("out.txt", "w", stdout);
#endif
#endif
    t = read();
    n = 6;
    for(int i = 1; i <= n; i++)
        a[i] = i;
    do
    {
        solve();
    } while (next_permutation(a + 1, a + 1 + n));

    return 0;
}