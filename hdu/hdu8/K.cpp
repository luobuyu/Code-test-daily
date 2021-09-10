#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 2e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

struct LinearBase
{
    const static int LEN = 35;
    int v[LEN];
    void init() { memset(v, 0, sizeof(v)); };
    void insert(int x)
    {
        for(int i = 31; i >= 0; i--)
        {
            if((x>>i) & 1)
            {
                if(v[i]) x ^= v[i];
                else
                {
                    v[i] = x;
                    break;
                }
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
}B;
int a[maxn], b[maxn], s[maxn];
int Next[maxn];
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

int kmp()
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
    return ans;
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

    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n, m, k);
        B.init();
        for(int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            read(b[i]);
        }
        for (int i = 1; i <= k; i++)
        {
            read(s[i]);
            B.insert(s[i]);
        }

        for(int i = 1; i <= n; i++)
        {
            a[i] = B.solve(a[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            b[i] = B.solve(b[i]);
        }
        getNext();
        printf("%d\n", kmp());
    }
    return 0;
}
