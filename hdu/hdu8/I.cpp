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
const int maxn = 5e6 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
char s[maxn];

int prime[maxn], cnt;
bool notPrime[maxn];
void sieve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!notPrime[maxn])
            prime[++cnt] = i, notPrime[i] = true;

        for (int j = 1; prime[j] * i <= n && j <= cnt; j++)
        {
            notPrime[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int tot[30];

int nex[maxn];
void getNext(char *s, int l)
{
    nex[0] = -1;
    for (int t = -1, i = 0; i < l; nex[++i] = ++t)
        for (; ~t && s[i] != s[t]; t = nex[t])
            ;
}
int kmp(char *str, int l1, char *substr, int l2)
{
    int i = 0, j = 0;
    while (i < l1 && j < l2)
    {
        if (j == -1 || str[i] == substr[j])
            i++, j++;
        else
            j = nex[j];
    }
    if (j == l2)
        return i - j;
    return -1;
}
char str[maxn]; // 主串
bool check(int k)
{
    if (n % k)
        return false;
    int l = n / k;
    getNext(s + 1, l);
    for (int t = 1; t <= k - 1; t++)
    {
        for (int i = 1; i <= l; i++)
        {
            str[i] = str[i + l] = s[t * l + i];
        }
        if (kmp(str + 1, 2 * l - 1, s + 1, l) == -1)
        {
            return false;
        }
    }
    return true;
}

void init()
{
    memset(tot, 0, sizeof(tot));
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第八场/发放/data/1009.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif

    int tcase;
    read(tcase);
    sieve(maxn - 5);
    while (tcase--)
    {
        read(n);
        scanf("%s", s + 1);
        if (n == 1)
        {
            printf("No\n");
            continue;
        }

        init();
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (tot[s[i] - 'a' + 1]++ == 0)
            {
                tot[0]++;
            }
        }

        if (!notPrime[n]) // 素数
        {
            printf("%s\n", tot[0] == 1 ? "Yes" : "No");
        }
        else
        {
            if (tot[0] == 1)
            {
                printf("Yes\n");
                continue;
            }
            int m = -1;
            for (int i = 1; i <= 26; i++)
            {
                if (tot[i])
                {
                    if (m == -1)
                    {
                        m = tot[i];
                        continue;
                    }
                    m = __gcd(m, tot[i]);
                }
            }
            if (m == 1)
            {
                printf("No\n");
                continue;
            }
            if (m == n || check(m))
            {
                printf("Yes\n");
                continue;
            }

            for (int i = 2; i * i <= m; i++)
            {
                if (m % i == 0)
                {
                    if (check(i) || check(m / i))
                    {
                        printf("Yes\n");
                        flag = true;
                        break;
                    }
                }
            }
            if (!flag)
                printf("No\n");
        }
    }
    return 0;
}