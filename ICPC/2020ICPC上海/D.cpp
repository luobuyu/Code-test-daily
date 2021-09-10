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
const double eps = 1e-7;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;

bool check(double tim, double n, double p1, double v1, double p2, double v2)
{
    double len1 = tim * v1;
    double len2 = tim * v2;
    // 各负责自己的一边，然后在中间相遇
    double leftbound, rightbound;
    if (len1 >= p1 && len2 >= n - p2)
    { // 可以直接走左侧，然后向右，也可以先向右走一段，再向左
        // 少考虑了这种 先向右走然后向左走到头的
        rightbound = max(len1 - p1, (len1 - p1) / 2 + p1);
        leftbound = min(n - (len2 - (n - p2)), p2 - (len2 - (n - p2)) / 2);

        if (leftbound <= rightbound)
        {
            return true;
        }
    }
    // 相对着走，走完
    if (len1 >= n - p1 && len2 >= p2)
        return true;
    // 一个人走完
    if (len1 >= min(p1, n - p1) + n)
        return true;
    // 一个人走完
    if (len2 >= min(p2, n - p2) + n)
        return true;
    return false;
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
        double n, p1, v1, p2, v2;
        double ans = INF_LL;
        scanf("%lf %lf %lf %lf %lf", &n, &p1, &v1, &p2, &v2);
        if (p1 > p2)
        {
            swap(p1, p2);
            swap(v1, v2);
        }
        double l = 0, r = 1e9;
        for (int i = 1; i <= 100; i++)
        {
            double mid = (l + r) / 2;
            if (check(mid, n, p1, v1, p2, v2))
            {
                ans = mid;
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        printf("%.10f\n", ans);
    }
    return 0;
}