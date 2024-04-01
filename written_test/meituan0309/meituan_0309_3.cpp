#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, q, k;
char a[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> k;
    cin >> a + 1;
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != 'M' && a[i] != 'T')
            cnt++;
    }
    cout << (n - cnt) + min(cnt, k) << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")