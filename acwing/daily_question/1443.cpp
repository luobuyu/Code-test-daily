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
const int maxn = 2e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m;
bool st[maxn];
int a[maxn];
int b[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    for (int k = 1; k < a[1]; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            st[i] = false;
        }
        b[1] = a[1] - k;
        st[b[1]] = true;
        bool flag = true;
        for (int i = 2; i <= n; i++)
        {
            b[i] = a[i - 1] - b[i - 1];
            if (b[i] >= 1 && b[i] <= n)
            {
                if (st[b[i]] == true)
                {
                    flag = false;
                    break;
                }
                else
                {
                    st[b[i]] = true;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << b[i] << " ";
            }
            cout << endl;
            break;
        }
    }
    return 0;
}