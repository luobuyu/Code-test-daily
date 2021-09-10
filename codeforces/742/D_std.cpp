#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int MAX = 1e9;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);
#endif
    int T, s, n, i, j, a[110];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &s, &n);
        for (i = 1; i <= n; i++)
            a[i] = 1;
        s -= n;
        for (i = MAX; i >= 1; i /= 10)
        {
            for (j = 1; s >= i - 1 && j <= n; j++)
            {
                if (a[j] > 1)
                    continue;
                a[j] += i - 1;
                s -= i - 1;
            }
        }
        a[1] += s;
        for (i = 1; i <= n; i++)
            printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
}
