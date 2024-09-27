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
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (x > y)
        swap(x, y);
    long long ans = INT_MAX;
    long long cnt1 = 0;
    for (int i = x; i < y; ++i)
    {
        cnt1 += a[i];
    }
    long long cnt2 = 0;
    for (int i = y; i != x; i = (i + 1) % n)
    {
        cnt2 += a[i];
    }
    cout << min(cnt1, cnt2) << endl;
    return 0;
}