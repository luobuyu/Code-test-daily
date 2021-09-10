#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 200 + 10;
int a[maxn][maxn], b[maxn][maxn];
int t, n, k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        int sum = 2 * n * (n + 1);
        if(n == 1 || sum % k != 0 || k == 1) 
        {
            printf("-1\n");
            continue;
        }
        int tmp = 0;
        for (int i = 1; i <= 2 * n + 1; i++)
        {
            if(i&1)
            {
                for (int j = 1; j <= n; j++)
                {
                    a[i / 2 + 1][j] = tmp % k + 1;
                    tmp++;
                }
            }
            else
            {
                for (int j = 1; j <= n + 1; j++)
                {
                    b[i / 2][j] = tmp % k + 1;
                    tmp++;
                }
            }
        }

        for (int i = 1; i <= n + 1; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
        for (int i = 1; i <= n + 1; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%d ", b[j][i]);
            }
            printf("\n");
        }
    }
    
        return 0;
}