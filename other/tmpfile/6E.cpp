#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 500 + 10;

int n, k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &k);
    int sum = n * (n + 1) / 2;
    if(sum % n != k) 
    {
        printf("-1\n");
        return 0;
    }
    if(n & 1)
    {
        printf("%d", n);
        for (int i = 1; i <= n / 2; i++)
        {
            printf(" %d %d", i, n - i);
        }
    }
    else
    {
        printf("%d %d", n, k);
        for (int i = 1; i < k; i++)
        {
            printf(" %d %d", i, n - i);
        }
    }
    
    return 0;
}