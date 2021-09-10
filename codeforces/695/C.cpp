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
ll a[3][maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    int x, y, z;
    read(x, y, z);
    for (int i = 1; i <= x; i++)
        read(a[0][i]), a[0][0] += a[0][i];
    for (int i = 1; i <= y; i++)
        read(a[1][i]), a[1][0] += a[1][i];
    for (int i = 1; i <= z; i++)
        read(a[2][i]), a[2][0] += a[2][i];
    ll minx = min(a[0][0], min(a[1][0], a[2][0]));
    sort(a[0] + 1, a[0] + 1 + x);
    sort(a[1] + 1, a[1] + 1 + y);
    sort(a[2] + 1, a[2] + 1 + z);
    ll maxx = max(a[0][1], max(a[1][1], a[2][1]));
    cout << a[0][0] + a[1][0] + a[2][0] - 2LL * min(minx, a[0][1] + a[1][1] + a[2][1] - maxx) << endl;
    return 0;
}