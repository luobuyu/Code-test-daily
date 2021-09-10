#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second

const int mxk = 10, mxn = 1 << mxk;
int n, k;
int a[mxn], f[mxn], vis[mxn];
vector<int> v;
vector<int> g[mxn];

bool dfs(int c)
{
    vis[c] = 1;
    for (int i : g[c])
    {
        if (!f[i] || (!vis[f[i]] && dfs(f[i])))
        {
            f[i] = c;
            return 1;
        }
    }
    return 0;
}

int main()
{
    // #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
        {
            char c;
            cin >> c;
            a[i] |= (c & 1) << j;
        }

    sort(a, a + n, [&](int x, int y) {
        return __builtin_popcount(x) > __builtin_popcount(y);
    });

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            if ((a[i] & a[j]) == a[i])
                g[i].push_back(j);
        }

    for (int i = 0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        dfs(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << f[i] << " ";
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            int x, y;
            v.push_back(-1);
            for (x = f[i], y = a[i]; x; y = a[x], x = f[x])
            {
                vis[x] = 1;
                for (int j = 0; j < k; j++)
                {
                    if (((a[x] ^ y) >> j) & 1)
                        v.push_back(j);
                }
            }
            for (int j = 0; j < k; j++)
                if ((y >> j) & 1)
                    v.push_back(j);
        }

    reverse(v.begin(), v.end());

    cout << (v.size() - 1) << endl;
    cout << v[0];
    for (int i = 1; i < v.size() - 1; i++)
    {
        cout << " ";
        if (!~v[i])
            cout << "R";
        else
            cout << v[i];
    }
    cout << endl;

    return 0;
}