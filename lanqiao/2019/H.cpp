#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e6 + 10;
int n, m, t;
int a[maxn];
int vis[maxn];
int fa[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        while (vis[a[i]])
        {
            int tmp = a[i];
            a[i] += vis[a[i]];
            vis[tmp]++;
        }
        vis[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}