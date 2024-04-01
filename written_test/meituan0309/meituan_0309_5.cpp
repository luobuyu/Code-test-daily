#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, k;
int a[maxn];
struct Node
{
    int cnt2, cnt5, cnt10;
    Node()
    {
        cnt2 = 0;
        cnt5 = 0;
        cnt10 = 0;
    }
    Node operator-(Node &p)
    {
        Node tmp = *this;
        tmp.cnt10 -= p.cnt10;
        tmp.cnt5 -= p.cnt5;
        tmp.cnt2 -= p.cnt2;
        return tmp;
    }
} b[maxn];

void countNum(int i)
{
    while (a[i] % 10 == 0)
    {
        b[i].cnt10++;
        a[i] /= 10;
    }
    while (a[i] % 5 == 0)
    {
        b[i].cnt5++;
        a[i] /= 5;
    }
    while (a[i] % 2 == 0)
    {
        b[i].cnt2++;
        a[i] /= 2;
    }
}
int getCnt(Node p)
{
    return p.cnt10 + min(p.cnt2, p.cnt5);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> k;
    Node sum;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        countNum(i);
        sum.cnt10 += b[i].cnt10;
        sum.cnt2 += b[i].cnt2;
        sum.cnt5 += b[i].cnt5;
    }
    Node tmp;
    int l = 1, r = 1;
    long long ans = 0;
    while (r <= n)
    {
        tmp.cnt10 += b[r].cnt10;
        tmp.cnt2 += b[r].cnt2;
        tmp.cnt5 += b[r].cnt5;
        while (getCnt(sum - tmp) < k && l <= r)
        {
            tmp.cnt10 -= b[l].cnt10;
            tmp.cnt2 -= b[l].cnt2;
            tmp.cnt5 -= b[l].cnt5;
            ++l;
        }
        ans += (r - l + 1);
        ++r;
    }
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")