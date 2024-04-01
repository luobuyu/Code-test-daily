#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;

int n, m, q, k, t;
int a[maxn];
int b[maxn];
int tmp[maxn];
long long ans = 0;
unordered_map<int, long long> mp1;
unordered_map<int, long long> mp2;
void mix(int l, int mid, int r)
{
    int i = l, j = mid + 1;
    int k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] > a[j])
        {
            ans += mid - i + 1;
            // mp1[a[i]] += j - mid;
            mp2[a[j]] += mid - i + 1;  // 前面比自己大的
            tmp[k++] = a[j++];
        }
        else
        {
            // a[i] < a[j]
            mp1[a[i]] += j - mid - 1;
            tmp[k++] = a[i++];
        }
    }
    while (i <= mid)
    {
        mp1[a[i]] += j - mid - 1;       // 后面比自己小的
        tmp[k++] = a[i++];
    }
    while (j <= r)
        tmp[k++] = a[j++];
    for (int i = l; i <= r; ++i)
    {
        a[i] = tmp[i];
    }
}
void mergeSort(int l, int r)
{
    if (l == r)
        return;
    int mid = l + ((r - l) >> 1);
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    mix(l, mid, r);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    mergeSort(1, n);
    // cout << ans << endl;
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << mp1[b[i]] << " " << mp2[b[i]] << endl;
    // }
    // cout << endl;
    for (int i = 1; i <= n; ++i)
    {
        // cout <<  << " ";
        printf("%lld ", ans - mp1[b[i]] - mp2[b[i]] + i - 1);
    }
    return 0;
}