#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = nextChar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = nextChar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = nextChar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
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
int a[maxn];
deque<int> q;
int cnt[maxn];
bool inSt[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
#endif
    read(n, k);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[a[i]]--;
        if (!inSt[a[i]])
        {
            while (!q.empty() && q.back() > a[i] && cnt[q.back()])
                inSt[q.back()] = false, q.pop_back();
            q.push_back(a[i]);
            inSt[a[i]] = 1;
        }
    }
    for (auto x : q)
    {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}
