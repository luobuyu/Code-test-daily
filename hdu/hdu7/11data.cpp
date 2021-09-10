#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int read()
{
    int x = 0, flag = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    }
    if (flag)
        return -x;
    return x;
}
int t, n, m, k;
map<string, vector<string> > mp;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("out.txt", "r", stdin);
    freopen("11data.txt", "w", stdout);
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    n = 720;
    string a, b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        mp[b].push_back(a);
    }

    for(auto x : mp)
    {
        cout <<"*" << x.first << endl;
        for(int i = 0; i < x.second.size(); i++)
        {
            cout << x.second[i] << endl;
        }
        cout << "--------------------------" << endl;
    }
    return 0;
}