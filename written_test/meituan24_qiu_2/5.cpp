#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
int n, m, q, k, t;
int a[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> t;
    int u, v;
    while(t--)  
    {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            
        }
        for (int i = 1; i <= k; ++i)
        {
            cin >> u >> v;
            a[u]++;
            a[v]--;
        }
        bool flag = true;
        for (int i = 1; i < n; ++i)
        {
            if(a[i] > a[i + 1]) {
                cout << "No" << endl;
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "Yes" << endl;
    }
    return 0;
}