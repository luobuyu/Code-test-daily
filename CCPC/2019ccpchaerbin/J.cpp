#include <bits/stdc++.h>
#define ll long long
const int maxn = 1e5 + 10;
int n, k;
ll a[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    scanf("%d", &tcase);
    while (tcase--)
    {
        scanf("%d %d", &n, &k);
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            sum += a[i];
        }

        for (int i = 1; i <= n; i++)
        {
            printf("%.8f%c", a[i] * 1.0 + a[i] * 1.0 / sum * k, " \n"[i == n]);
        }
    }
    return 0;
}