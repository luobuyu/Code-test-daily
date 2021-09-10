#include <bits/stdc++.h>
#define ll long long
#define lll long long
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn], b[maxn];
int cot[maxn][maxn];

bool check(int i, int j, int k)
{
    int tmp[4] = {0, i, j, k};
    for (int i = 1; i <= 3; i++)
    {
        for (int j = i + 1; j <= 3; j++)
        {
            if (!((a[tmp[i]] == a[tmp[j]] && b[i] == b[j]) || (a[tmp[i]] != a[tmp[j]] && b[i] != b[j])))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
    }
    for (int i = 1; i <= 4; i++)
    {
        read(b[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            cot[i][j] = cot[i + 1][j];
        }
        cot[i][a[i]]++;
    }
    ll ans = 0;
    int pp[4];
    unordered_map<int, int> mp;
    for (int i = 1; i <= n - 3; i++)
    {
        for (int j = i + 1; j <= n - 2; j++)
        {
            if ((a[i] == a[j] && b[1] == b[2]) || (a[i] != a[j] && b[1] != b[2]))
                for (int k = j + 1; k <= n - 1; k++)
                {
                    if (check(i, j, k))
                    {
                        int tmp = n - k;
                        pp[1] = i, pp[2] = j, pp[3] = k;
                        mp.clear();
                        for (int p = 1; p <= 3; p++)
                        {
                            if (b[p] == b[4])
                            {
                                tmp = cot[k + 1][a[pp[p]]];
                                break;
                            }
                            else
                            {
                                if (!mp.count(a[pp[p]]))
                                {
                                    tmp -= cot[k + 1][a[pp[p]]];
                                    mp[a[pp[p]]] = 1;
                                    if (tmp < 0)
                                        break;
                                }
                            }
                        }
                        ans += max(tmp, 0);
                    }
                }
        }
    }
    printf("%lld\n", ans);
    return 0;
}