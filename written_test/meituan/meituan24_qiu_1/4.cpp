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
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int x, y;
    cin >> x >> y;
    for (int i = 1; i < n; ++i)
    {
        if(a[i] == x && a[i + 1] == y || a[i] == y && a[i + 1] == x)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}