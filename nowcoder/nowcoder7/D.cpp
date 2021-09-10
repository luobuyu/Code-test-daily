#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 500 + 10;
ll t, n;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        if (n == 1 || n == 24)
        {
            printf("Fake news!\n");
        }
        else
        {
            printf("Nobody knows it better than me!\n");
        }
    }
    return 0;
}