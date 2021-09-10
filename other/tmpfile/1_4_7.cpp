#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5 + 10;
#define ll long long

struct Node
{
    int s, t, d;
}node[maxn];


int n, m;
int a[maxn];
int tmp[maxn];
bool check(int x)
{
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= x; i++)
    {
        tmp[node[i].s] += node[i].d;
        tmp[node[i].t + 1] -= node[i].d;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += tmp[i];
        if(sum > a[i])
            return false;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> node[i].d >> node[i].s >> node[i].t;
    }
    int l = 1, r = m, ans = 0;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    if(ans)
        cout << "-1" << ans << endl;
    else
        cout << "0" << endl;
    return 0;
}
