#include <iostream>
#include <cstdio>

#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
ll a[maxn];
ll sum[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int n;
    //cin >> n;
    //for(int i = 1; i <= n; i++) cin >> a[i];
    n = 100000;
    for(int i = 1; i <= n; i++)
    {
        a[i] = n;
    }
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    ll ans = 0;
    ll index = 0;

    for(ll i = 1; (1 << (i - 1)) - 1 <= n; i++)
    {
        ll l = (1 << (i - 1)) - 1;
        ll r = (1 << i) - 1;
        if(r > n) r = n;
        cout << l << ". " << r << endl;
        ll tmp = sum[r] - sum[l];
        if(tmp > ans)
        {
            ans = tmp;
            index = i;
        }
    }
    
    cout << index << endl;
    //cout << ans << endl;
    return 0;
}