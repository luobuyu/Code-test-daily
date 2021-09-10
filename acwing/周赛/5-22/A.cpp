#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
const int maxn = 1e6 + 10;

int n, m, k;

int getSum(int x)
{
    int ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = n;; i++)
    {
        if (getSum(i) % 4 == 0)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}