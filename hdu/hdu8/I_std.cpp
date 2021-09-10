#include <bits/stdc++.h>
#define fp(i, a, b) for (int i = a, i##end = (b) + 1; i < i##end; ++i)
#define fd(i, a, b) for (int i = a, i##end = (b)-1; i > i##end; --i)
#define file(s) freopen(s ".in", "r", stdin) //freopen(s ".out", "w", stdout)
namespace IO
{
    //In
    char ss[1 << 17], *_A = ss, *_B = ss;
#define gc() (_A == _B && (_B = (_A = ss) + fread(ss, 1, 1 << 17, stdin), _A == _B) ? -1 : *_A++)
    template <class T>
    inline void In(T &x)
    {
        char c;
        T y = 1;
        while (c = gc(), !isdigit(c) && c != -1)
            if (c == 45)
            {
                y = -1;
            }
        x = c - 48;
        while (c = gc(), isdigit(c))
        {
            x = x * 10 + c - 48;
        }
        x *= y;
    }
    template <class T, class... _T>
    inline void In(T &x, _T &... y) { return In(x), In(y...); }
    template <class T>
    inline void In(T *a, int Len) { fp(i, 0, Len - 1) In(*(a + i)); }
    inline void In(char *a, int Len) { fp(i, 0, Len - 1) * (a + i) = gc(); }
    //Out
    char sr[1 << 21], _z[20], *_C = sr, *_D = sr + (1 << 21) - 1;
    int _Z;
    inline void flush() { fwrite(sr, 1, _C - sr, stdout), _C = sr; }
    inline void pc(char c)
    {
        *_C++ = c;
        if (*_C == *_D)
            flush();
    }
    inline void ps(const char *c)
    {
        while (*c)
        {
            *_C++ = *c++;
            if (_C == _D)
                flush();
        }
    }
    template <class T>
    inline void Out(T x, char c = '\n')
    {
        if (x < 0)
            pc(45), x = -x;
        while (_z[++_Z] = x % 10 + 48, x /= 10)
            ;
        while (pc(_z[_Z]), --_Z)
        {
        };
        pc(c);
    }
    template <class T, class... _T>
    inline void Out(T x, _T... y) { return Out(x, ' '), Out(y...); }
    template <class T>
    inline void Out(T *a, int Len) { fp(i, 0, Len - 1) Out(*(a + i), " \n"[i == Len - 1]); }
    struct _Flush
    {
        ~_Flush() { flush(); }
    } flusher;
} // namespace IO
using namespace std;
using namespace IO;
const int N = 5000000 + 5, M = 26;
typedef int arr[N];
/*-----------------------------------------------------------------*/
int n, m, nx[N], cnt[M];
char s[N], q[N];
inline void KMP(char *s, int n)
{
    nx[1] = 0;
    for (int i = 2, j = 0; i <= n; ++i)
    {
        while (j && j < n && s[j + 1] != s[i])
            j = nx[j];
        if (j < n && s[j + 1] == s[i])
            ++j;
        nx[i] = j;
    }
}
inline bool check(int k)
{
    if (n % k)
        return 0;
    int L = n / k;
    KMP(s + 1, L);
    fp(t, 1, k - 1)
    {
        int ok = 0;
        fp(i, 1, L) q[i] = q[i + L] = s[t * L + i];
        for (int i = 1, j = 0; i <= 2 * L; ++i)
        {
            while (j && j < L && s[j + 1] != q[i])
                j = nx[j];
            if (j < L && s[j + 1] == q[i])
                ++j;
            if (j == L)
            {
                ok = 1;
                break;
            }
        }
        if (!ok)
            return 0;
    }
    return 1;
}
inline void Solve()
{
    In(s + 1, n);
    memset(cnt, 0, sizeof cnt);
    fp(i, 1, n)++ cnt[s[i] - 'a'];
    fp(i, 0, 25) if (cnt[i]) m = cnt[i];
    fp(i, 0, 25) if (cnt[i])
        m = __gcd(m, cnt[i]);
    if (m == 1)
        return ps("No\n");
    if (m == n || check(m))
        return ps("Yes\n");
    fp(i, 2, sqrt(m)) if (m % i == 0)
    {
        if (check(i) || check(m / i))
            return ps("Yes\n");
        // while (t % i == 0)
        //     t /= i;
    }
    ps("No\n");
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第八场/发放/data/1009.in", "r", stdin);
    freopen("1009.out", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    In(n);
    while (In(n), n != -49)
        Solve();
    return 0;
}