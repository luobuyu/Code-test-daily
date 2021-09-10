#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 30 + 10;

int t;
int a[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // debug
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        ll ans = 0;
        for (int i = 1; i <= 26; ++i)
        {
            cin >> a[i];
            ans += a[i] / 2 * 2;
        }
        cout << ans << endl;
    }
    return 0;
}