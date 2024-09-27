#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;

int n, m, q, k, t;
int a[maxn];
int preSum[maxn];
int tmp[maxn];
long long ans2 = 0;
void mix(int a[], int b[], int l, int mid, int r)
{
    int i = l, j = mid + 1, k = l;
    int l0 = l;
    int l1 = mid + 1;
    while(l0 <= mid)
    {
        while(l1 <= r && a[l1] - a[l0] <= 0) {
            l1++;
        }
        ans2 += r - l1 + 1;
        l0++;
    }
    while(i <= mid && j <= r)
    {
        if(a[i] > a[j])
            b[k++] = a[j++];
        else
            b[k++] = a[i++];
    }
    while(i <= mid)
        b[k++] = a[i++];
    while(j <= r)
        b[k++] = a[j++];
    for (int i = l; i <= r; ++i)
        a[i] = b[i];
}
void mergeSort(int a[], int l, int r)
{
    if(l == r)
        return;
    int mid = l + ((r - l) >> 1);
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    mix(a, tmp, l, mid, r);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if(a[i] == 1)
            sum1++;
        else
            sum2++;
        preSum[i] = sum2 - sum1;
    }
    mergeSort(preSum, 0, n);
    // for (int i = 0; i <= n; ++i)
    // {
    //     cout << preSum[i] << endl;
    // }
    // cout << ans2 << endl;
    long long ans = 1ll * n * (n + 1) / 2 + ans2;
    cout << ans << endl;
    return 0;
}

/*
3
2 1 2
*/