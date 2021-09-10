#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e6 + 10;
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
int f[maxn];
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
    n = read(), m = read();
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    int l = 0, r = 0;
    int ansl = 1, ansr = n, ans = n;
    int cnt = 0;
    while (r <= n)
    {
        while(cnt < m && r < n) 
        {
            r++;
            if (f[a[r]]++ == 0)
            {
                cnt++;
            }
        }
        if(cnt < m)
            break;
        while (cnt == m)
        {
            l++;
            f[a[l]]--;
            if (f[a[l]] == 0)
                cnt--;
        }
        if(r - l + 1 < ans) 
        {
            ans = r - l;
            ansl = l;
            ansr = r;
        }
    }

    printf("%d %d\n", ansl, ansr);
    return 0;
}