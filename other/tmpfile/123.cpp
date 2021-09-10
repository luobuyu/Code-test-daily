#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define T int
using namespace std;
const int maxn = 5e5 + 10;
int n, m, k;
int a[maxn];
int tmp[maxn];
ll fun(int *a, int l, int r)
{
    if (l == r)
        return 0;
    int mid = (l + r) >> 1;
    ll ans = 0;
    ans += fun(a, l, mid);
    ans += fun(a, mid + 1, r);
    // merge
    int l1 = l, r1 = mid, l2 = mid + 1, r2 = r, k = l;

    while (l1 <= r1 && l2 <= r2)
    {
        if (a[l1] <= a[l2])
        {
            tmp[k++] = a[l1++];
        }
        else
        {
            tmp[k++] = a[l2++];
            ans += (ll)(mid - l1 + 1);
        }
    }

    while (l1 <= r1)
    {
        tmp[k++] = a[l1++];
    }
    while (l2 <= r2)
    {
        tmp[k++] = a[l2++];
    }
    for (int i = l; i <= r; i++)
    {
        a[i] = tmp[i];
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << fun(a, 0, n - 1) << endl;
    return 0;
}