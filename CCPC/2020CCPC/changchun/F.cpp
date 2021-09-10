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
const int maxn = 1e5 + 5;
const int maxm = 1e6 + 5;
int t, n, m, k;

int a[maxn];
vector<int> v[maxn];
int siz[maxn], son[maxn], Son;
int cnt[maxn * 15][21][2];
int base[25];
ll sum;
void dfs(int x, int fa) //记录重儿子
{
    siz[x] = 1;
    for (auto to : v[x])
    {
        if (to == fa)
            continue;
        dfs(to, x);
        siz[x] += siz[to];
        if (siz[to] > siz[son[x]])
        {
            son[x] = to;
        }
    }
}
void update(int x, int fa, int num)
{

    int val = a[x] ^ num;
    for (int i = 0; i <= 20; ++i)
    {
        sum += 1ll * base[i] * cnt[val][i][!((x >> i) & 1)];
    }
    for (auto to : v[x])
    {
        if (to == fa || to == Son)
            continue;
        update(to, x, num);
    }
}
void add(int x, int fa, int val)
{
    for (int i = 0; i <= 20; i++)
    {
        cnt[a[x]][i][(x >> i) & 1] += val;
    }
    for (auto to : v[x])
    {
        if (to == fa || to == Son)
            continue;
        add(to, x, val);
    }
}
void dfs2(int x, int fa, int keep)
{
    for (auto to : v[x])
    {
        if (to == fa || to == son[x])
            continue;
        dfs2(to, x, 0);
    }
    if (son[x])
    {
        dfs2(son[x], x, 1);
        Son = son[x];
    }
    //暴力统计x及其所有轻儿子的贡献合并到刚算出的重儿子信息里
    for (auto to : v[x])
    {
        if (to == fa || to == son[x])
            continue;
        update(to, x, a[x]);
        add(to, x, 1);
    }
    for (int i = 0; i <= 20; ++i)
    {
        cnt[a[x]][i][(x >> i) & 1]++;
    }
    Son = 0;
    if (!keep)
    {
        add(x, fa, -1);
    }
}


int main()
{
    int abd = 129;
    
    return 0;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    base[0] = 1;
    for (int i = 1; i <= 20; ++i)
    {
        base[i] = base[i - 1] * 2;
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0); //记录重儿子
    dfs2(1, 0, 0);
    printf("%lld\n", sum);
    return 0;
}