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
const int maxn = 5e1 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
int up[maxn], down[maxn];
int ans = INF;
void dfs(int l1, int l2, int index)
{
    if(l1 + l2 >= ans)
        return;
    if(index == n + 1)
        ans = min(ans, l1 + l2);
    // 尝试加入上升子序列中
    int pos = -1;
    for (int i = 1; i <= l1; i++)
    {
        if(up[i] < a[index])
        {
            pos = i;
            break;
        }
    }
    if(pos == -1)
    {
        pos = l1 + 1;
    }
    int tmp = up[pos];
    up[pos] = a[index];
    dfs(max(pos, l1), l2, index + 1);
    up[pos] = tmp;
    pos = -1;
    for (int i = 1; i <= l2; i++)
    {
        if(down[i] > a[index])
        {
            pos = i;
            break;
        }
    }
    if(pos == -1)
        pos = l2 + 1;
    tmp = down[pos];
    down[pos] = a[index];
    dfs(l1, max(pos, l2), index + 1);
    down[pos] = tmp;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    while(read(n), n)
    {
        ans = INF;
        for (int i = 1; i <= n; i++)
            read(a[i]);
        dfs(0, 0, 1);
        printf("%d\n", ans);
    }
    return 0;
}