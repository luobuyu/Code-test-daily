#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int t, n, l[maxn], r[maxn];
char a[maxn];
signed main()
{
    cin >> t;
    while (t--)
    {
        scanf("%d%s", &n, a + 1);
        int now = 0;
        //[0,n]个城市
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[i - 1])
                now = 1;
            else
                now++;
            if (a[i] == 'L')
                l[i] = now;
        }
        now = 0;
        for (int i = n; i >= 1; i--)
        {
            if (a[i] == a[i + 1])
                now = 1;
            else
                now++;
            if (a[i] == 'R')
                r[i - 1] = now;
        }
        for (int i = 0; i <= n; i++)
        {
            printf("%d%c", l[i] + r[i] + 1, " \n"[i == n]);
            l[i] = r[i] = 0;
        }
    }
}
