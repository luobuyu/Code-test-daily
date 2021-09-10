#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 100 + 10;
const int maxm = 1e4 + 10;
int t, n, m, k;

struct Edge
{
    int u, v, w;
} edge[maxm];

struct Matrix
{
    using type = ll;
    type f[maxn][maxn];
    int dimx;
    int dimy;

    Matrix operator+(const Matrix x) const
    {
        Matrix ret;
        for(int i = 1; i <= dimx; i++)
        {
            for(int j = 1; j <= dimy; j++)
            {
                ret.f[i][j] = f[i][j] + x.f[i][j];
            }
        }
        return ret;
    }

    Matrix operator-(const Matrix x) const
    {
        Matrix ret;
        for (int i = 1; i <= dimx; i++)
        {
            for (int j = 1; j <= dimy; j++)
            {
                ret.f[i][j] = f[i][j] - x.f[i][j];
            }
        }
        return ret;
    }

    void operator+=(const Matrix x)
    {
        for (int i = 1; i <= dimx; i++)
        {
            for (int j = 1; j <= dimy; j++)
            {
                f[i][j] += x.f[i][j];
            }
        }
    }

    void operator-=(const Matrix x)
    {
        for (int i = 1; i <= dimx; i++)
        {
            for (int j = 1; j <= dimy; j++)
            {
                f[i][j] -= x.f[i][j];
            }
        }
    }

    void addMatrixTree(int u, int v)
    {
        f[u][u]++, f[v][v]++;
        f[u][v]--, f[v][u]--;
    }
    void init()
    {
        memset(f, 0, sizeof(f));
    }
    type det(int l = 1, int r = n)
    {
        type ans = 1;
        for (int i = l; i <= r; i++)
        {
            for (int j = i + 1; j <= r; j++)
            {
                while (f[j][i])
                {
                    type t = f[i][i] / f[j][i];
                    for (int k = i; k <= r; k++)
                        f[i][k] = (f[i][k] - t * f[j][k] + mod) % mod;
                    swap(f[i], f[j]);
                    ans = -ans;
                }
            }
            ans = (ans * f[i][i]) % mod;
        }
        return (ans + mod) % mod;
    }
};

ll qpow(ll a, ll b, ll mod)
{
    ll ans = 1, tmp = a;
    while (b)
    {
        if (b & 1)
            ans = ans * tmp % mod;
        tmp = tmp * tmp % mod;
        b >>= 1;
    }
    return ans % mod;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第六场/1010/data/1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        memset(f, 0, sizeof(f));
        memset(edge, 0, sizeof(edge));
        int u, v, w;
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d %d %d", &u, &v, &w);
            edge[i] = {u, v, w};
            f[u][u]++, f[v][v]++;
            f[u][v]--, f[v][u]--;
        }
        ll sum = gauss(1, n - 1);
        ll ans = 0;
        for(int i = 0; i <= 30; i++)
        {
            memset(f, 0, sizeof(f));
            for(int j = 1; j <= m; j++)
            {
                if(edge[j].w & (1 << i))
                {
                    u = edge[j].u;
                    v = edge[j].v;
                    f[u][u]++, f[v][v]++;
                    f[u][v]--, f[v][u]--;
                }
            }
            ll tmp = gauss(1, n - 1);
            ans = (ans + 1LL * (1 << i) * tmp % mod) % mod;
        }

        printf("%lld\n", ans * qpow(sum, mod - 2, mod) % mod);
    }
    return 0;
}