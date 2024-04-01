#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m, q, k;
int a[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    int l = 1, r = n;
    for (int i = 1; i <= n; ++i)
    {
        if(i & 1)
            cout << l++ << " ";
        else
            cout << r-- << " ";
    }
        return 0;
}