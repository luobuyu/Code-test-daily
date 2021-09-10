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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tcase;
    cin >> tcase;
    while (tcase--)
    {
        string a, b, d;
        cin >> n >> b;
        a += '1';
        d += b[0] + 1;
        for (int i = 1; i < n; i++)
        {
            if (d[i - 1] == '0')
                a += '1';
            else if (d[i - 1] == '1')
            {
                if (b[i] == '1')
                    a += '1';
                else
                    a += '0';
            }
            else if (d[i - 1] == '2')
            {
                if (b[i] == '1')
                    a += '0';
                else
                    a += '1';
            }
            d += b[i] + a[i] - '0';
        }
        cout << a << endl;
    }
    return 0;
}