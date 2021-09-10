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
const double eps = 1e-5;
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
ll n, k;
struct Node
{
    ll num;
    char s[20];
    int len;
    void toStr()
    {
        len = 0;
        ll tmp = num;
        while (tmp)
        {
            s[len] = tmp % 10 + '0';
            len++;
            tmp /= 10;
        }
    }

    void toll()
    {
        ll tmp = 1;
        num = 0;
        for (int i = 0; i < len; i++)
        {
            num *= tmp;
            num += s[i] - '0';
            tmp *= 10;
        }
    }

    void toNine()
    {
        ll tmp = 1;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '6')
            {
                s[i] = '9';
                num += 3ll * tmp;
            }
            tmp *= 10;
        }
    }
} a[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(a[i].num);
        a[i].toStr();
    }
    Node pre;
    pre.num = 0;
    pre.toStr();
    bool flag;
    for (int i = 1; i <= n; i++)
    {
        flag = true;
        a[i].toNine();
        ll tmp = pow(10, a[i].len - 1);
        for (int j = a[i].len - 1; j >= 0; j--)
        {
            if (a[i].num >= pre.num)
            {
                if (a[i].s[j] == '9')
                {
                    if (a[i].num - 3ll * tmp >= pre.num)
                    {
                        a[i].s[j] = '6';
                        a[i].num -= 3ll * tmp;
                    }
                }
            }
            else
            {
                flag = false;
                break;
            }
            tmp /= 10;
        }
        pre = a[i];
        if (!flag)
            break;
    }

    if (flag)
    {
        printf("possible\n");
        for (int i = 1; i <= n; i++)
        {
            printf("%lld\n", a[i].num);
        }
    }
    else
    {
        printf("impossible\n");
    }
    return 0;
}