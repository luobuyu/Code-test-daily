#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
int n, m, q, k, t;
long long a[maxn];
long long qpow(long long a, long long b)
{
    long long ret = 1, tmp = a;
    while (b)
    {
        if (b & 1)
            ret = ret * tmp % mod;
        tmp = tmp * tmp % mod;
        b >>= 1;
    }
    return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> q;
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    int index;
    unordered_map<int, int> mp;
    for (int i = 1; i <= q; ++i)
    {
        cin >> index;
        mp[index]++;
    }
    sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        int cnt = q;
        if(mp.count(i))
            cnt -= mp[i];
        sum = (sum + a[i] * qpow(2, cnt) % mod) % mod;
    }
        cout << sum << endl;
    return 0;
}