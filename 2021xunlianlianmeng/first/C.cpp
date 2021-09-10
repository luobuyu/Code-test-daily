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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

int len1;
int len;

int num[maxn];
int a[maxn];
bool flag;
void dfs(int pos)
{
    if (flag)
        return;

    if (pos > len)
    {
        flag = 1;

        for (int i = 1; i <= len1; i++)
            cout << a[i];
        cout << endl;
        return;
    }
    for (int i = 0; i <= 9; i++)
    {
        int tmp = 0;
        a[pos] = i;
        if (pos > len1 && i > 0)
            return;
        for (int j = 1; j <= pos; j++)
        {
            tmp += ((a[j] * a[pos - j + 1]) % 10);
            tmp %= 10;
        }
        if (tmp == num[pos])
            dfs(pos + 1);
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    flag = 0;
    string s;
    cin >> s;
    len = s.size();
    len1 = (len + 1) >> 1;

    for (int i = 1; i <= len; ++i)

        num[i] = s[i - 1] - '0';

    dfs(1);
    if (!flag)
        cout << -1 << endl;

    return 0;
}