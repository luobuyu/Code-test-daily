#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 10;
int n, q;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> q;
    long long sum1 = 0;
    long long sum2 = 0;
    int x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        sum1 += x;
        sum2 += (x == 0);
    }
    int l, r;
    for (int i = 1; i <= q; ++i)
    {
        cin >> l >> r;
        cout << sum1 + sum2 * l << " " << sum1 + sum2 * r << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")