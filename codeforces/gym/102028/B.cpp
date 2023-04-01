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
const int maxn = 3e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

ll pri[maxn];
struct node
{
    ll H, K;
} a, b;

void init()
{
    for (int i = 1; i <= 1e5; i++)
        pri[i] = pri[i - 1] + i;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    init();
    while (tcase--)
    {
        ll suma = 0, sumb = 0;
        string ansa, ansb;
        scanf("%lld %lld %lld %lld", &a.H, &b.H, &a.K, &b.K);
        //A先死-
        int u1 = lower_bound(pri + 1, pri + 100000, a.H) - pri;
        int u2 = lower_bound(pri + 1, pri + 100000, b.H + a.H) - pri;
        ll left = pri[u1] - a.H;
        suma = a.K * u1 + b.K * u2;
        if (pri[u2] - pri[u1] >= b.H)
        {
            for (int i = 1; i <= u1; i++)
                ansa += 'A';
            for (int i = u1 + 1; i <= u2; i++)
                ansa += 'B';
        }
        else
        {
            for (int i = 1; i <= u1; i++)
            {
                if (i == left)
                    ansa += 'B';
                else
                    ansa += 'A';
            }
            for (int i = u1 + 1; i <= u2; i++)
                ansa += 'B';
        }
        //B先死
        u1 = lower_bound(pri + 1, pri + 100000, b.H) - pri;
        u2 = lower_bound(pri + 1, pri + 100000, a.H + b.H) - pri;
        sumb = b.K * u1 + a.K * u2;
        left = pri[u1] - b.H;
        int pos = upper_bound(pri + 1, pri + 100000, left) - pri - 1;
        if (pri[pos] + pri[u2] - pri[u1] >= a.H)
        {
            for (int i = 1; i <= pos; i++)
                ansb += 'A';
            for (int i = pos + 1; i <= u1; i++)
                ansb += 'B';
            for (int i = u1 + 1; i <= u2; i++)
                ansb += 'A';
        }
        else
        {
            left = a.H - (pri[u2] - pri[u1]);
            for (int i = 1; i <= u1; i++)
            {
                if (left >= 2 * i + 1 || left == i)
                {
                    left -= i;
                    ansb += 'A';
                }
                else
                    ansb += 'B';
            }
            for (int i = u1 + 1; i <= u2; i++)
                ansb += 'A';
        }
        if (suma < sumb)
            cout << suma << " " << ansa << "\n";
        else if (sumb < suma)
            cout << sumb << " " << ansb << "\n";
        else
        {
            if (ansa < ansb)
                cout << suma << " " << ansa << "\n";
            else
                cout << sumb << " " << ansb << "\n";
        }
    }
    return 0;
}