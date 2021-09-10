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
int a[maxn];

bool judge(int i)
{
    if (i == 1 || i == n)
        return false;
    return (a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i + 1] && a[i] < a[i - 1]);
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    while (tcase--)
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
        }
        int ans = 0;
        for (int i = 2; i <= n - 1; i++)
        {
            if (judge(i))
                ans++;
        }
        int dis = 0;
        for (int i = 2; i <= n - 1; i++)
        {
            int old = judge(i - 1) + judge(i) + judge(i + 1);
            int tmp = a[i];
            a[i] = a[i - 1];
            int ne = judge(i - 1) + judge(i) + judge(i + 1);
            dis = max(dis, old - ne);
            a[i] = a[i + 1];
            ne = judge(i - 1) + judge(i) + judge(i + 1);
            dis = max(dis, old - ne);
            a[i] = tmp;
        }
        cout << ans - dis << endl;
    }
    return 0;
}