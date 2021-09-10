#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int n, m, k, a[100], b[100], S[100];
int Next[100];

struct LinearBase
{
    int v[35];
    void init()
    {
        memset(v, 0, sizeof v);
    }
    void insert(int x)
    {
        for (int i = 30; i >= 0; i--)
            if (x >> i & 1)
            {
                if (v[i])
                    x ^= v[i];
                else
                {
                    v[i] = x;
                    break;
                }
            }
    }
    int solve(int x)
    {
        for (int i = 30; i >= 0; i--)
            if (x >> i & 1)
                x ^= v[i];
        return x;
    }
} bs;

void getNext()
{
    Next[1] = 0;
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j > 0 && b[j + 1] != b[i])
            j = Next[j];
        if (b[j + 1] == b[i])
            j++;
        Next[i] = j;
    }
}

void KMP()
{
    int n2 = 1, ans = 0;
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j > 0 && b[j + 1] != a[i])
            j = Next[j];
        if (b[j + 1] == a[i])
            j++;
        if (j == m)
        {
            ans = (ans + n2) % mod;
            j = Next[j];
        }
        if (i >= m)
            n2 = (2LL * n2) % mod;
    }
    printf("%d\n", ans);
}

void solve()
{
    scanf("%d%d%d", &n, &m, &k);
    bs.init();
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &S[i]);
        bs.insert(S[i]);
    }
    for (int i = 1; i <= n; i++)
        a[i] = bs.solve(a[i]);
    for (int i = 1; i <= m; i++)
        b[i] = bs.solve(b[i]);
    getNext();
    KMP();
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}