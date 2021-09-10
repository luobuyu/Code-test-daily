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
ll a[maxn];
ll b[maxn];
map<ll, int> mp;
bool cmp(ll a, ll b)
{
    return a > b;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n);
        mp.clear();
        bool flag = true;
        for (int i = 1; i <= n << 1; i++)
        {
            read(a[i]);
            mp[a[i]]++;
            if (a[i] & 1)
                flag = false;
        }
        for (auto x : mp)
        {
            if (x.second != 2)
            {
                flag = false;
                break;
            }
        }
        sort(a + 1, a + n + n, cmp);
        int sz = unique(a + 1, a + n + n) - a - 1;
        if (sz != n)
            flag = false;
        if (flag == false)
            printf("NO\n");
        else
        {

            for (int i = 1; i <= n; i++)
            {
                b[i] = (a[i] - 2 * b[i - 1]) / (2 * n - 2 * (i - 1));

                if (b[i] <= 0 || (a[i] - 2 * b[i - 1]) % (2 * n - 2 * (i - 1)) != 0)
                {
                    flag = false;
                }
                b[i] += b[i - 1];
            }
            if (flag)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}