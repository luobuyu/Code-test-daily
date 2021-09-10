#include <bits/stdc++.h>
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int T, n;
    int a[52][52], b[52][52], k[4][4];
    for(scanf("%d", &T); T--;) {
        int sum = 0, flag;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= 3; ++i)
            for(int j = 1; j <= 3; ++j) {
                scanf("%d", &k[i][j]);
                sum += k[i][j];
            }
        flag = k[1][1] == sum;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j < n; ++j)
                printf("%d ", flag * a[i][j]);
            printf("%d\n", flag * a[i][n]);
        }
    }
    return 0;
}