// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
char s1[maxn], s2[maxn];
int Next[maxn];
void getNext(char *s)
{
    int len = strlen(s + 1);
    int t = 0;
    int i = 1;
    Next[1] = 0;
    while (i <= len)
    {
        if (t == 0 || s[i] == s[t])
        {
            ++i;
            ++t;
            Next[i] = t;
        }
        else
            t = Next[t];
    }
}
int kmp(char *s, char *t)
{
    int i = 1, j = 1;
    int len1 = strlen(s + 1), len2 = strlen(t + 1);
    while (i <= len1 && j <= len2)
    {
        if (j == 0 || s[i] == t[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = Next[j];
        }
    }
    if (j == len2 + 1)
    {
        return j - len2 + 1;
    }
    return -1;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s1 + 1 >> s2 + 1;
    getNext(s2);
    cout << s2 << endl;
    int len2 = strlen(s2 + 1);
    for (int i = 1; i <= len2 + 1; ++i)
    {
        cout << Next[i] << " ";
    }
    cout << endl;
    cout << kmp(s1, s2) << endl;
    return 0;
}