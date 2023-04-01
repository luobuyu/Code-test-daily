#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e6 + 10;
int n, m, t;
int a[maxn];
bool vis[maxn];
int fa[maxn];
int getFa(int u)
{
    return u == fa[u] ? u : fa[u] = getFa(fa[u]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i < maxn; i++)
    {
        fa[i] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        a[i] = getFa(a[i]);
        fa[a[i]] = getFa(a[i] + 1);
    }
    for(int i = 1;  i<= n; i++)
    {
        cout << a[i] << " ";
    }
}