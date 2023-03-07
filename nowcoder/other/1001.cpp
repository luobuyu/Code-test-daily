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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> n >> t;
    cin >> s;
    int index = -1;
    s = "0" + s;
    while (s[++index] != '.' && index < s.length())
        ;
    if (index >= s.length())
    {
        cout << s << endl;
        return 0;
    }
    for (int i = index + 1; i < s.length(); ++i)
    {
        if (t <= 0)
            break;
        if (s[i] - '0' >= 5)
        {
            int j = i - 1;
            s[i] = '0';
            t--;
            bool flag = true;
            bool add = true;
            while (j >= 0)
            {
                if (s[j] == '9')
                {
                    s[j] = '0';
                    j--;
                }
                else if (s[j] == '4' && t > 0 && flag)
                {
                    s[j] = '0';
                    j--;
                    t--;
                }
                else if (s[j] == '.')
                {
                    j--;
                    flag = false;
                }
                else
                {
                    s[j] = s[j] + 1;
                    break;
                }
            }
        }
    }
    int l = -1, r = -1;
    for (int i = 0; i < s.length(); ++i)
    {
        if (l == -1 && s[i] != '0')
        {
            l = i;
            if (s[i] == '.')
                l = i - 1;
            break;
        }
    }
    for (int i = s.length() - 1; i >= 0; --i)
    {
        if (r == -1 && s[i] != '0')
        {
            r = i;
            if (s[i] == '.')
            {
                r = i - 1;
            }
            break;
        }
    }
    if (index - l == 3)
    {
        cout << 100 << endl;
        return 0;
    }
    for (int i = l; i <= r; ++i)
    {
        cout << s[i];
    }
    return 0;
}