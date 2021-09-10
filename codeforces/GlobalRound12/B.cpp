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

struct Node
{
    int x, y;
} node[maxn];

int fa[maxn];

int findFa(int u)
{
    if (u == fa[u])
        return u;
    return fa[u] = findFa(fa[u]);
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
}

vector<int>
    len;
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
        read(n, k);
        init(n);
        for (int i = 1; i <= n; i++)
        {
            read(node[i].x, node[i].y);
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int dis = abs(node[i].x - node[j].x) + abs(node[j].y - node[i].y);
                if (dis <= k)
                {
                    int up = findFa(i);
                    int vp = findFa(j);
                    if (up == vp)
                        continue;
                    fa[vp] = up;
                }
            }
        }

        int p = findFa(1);
        bool flag = true;
        for (int i = 2; i <= n; i++)
        {
            if (findFa(i) != p)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            printf("1\n");
        else
            printf("-1\n");
    }
    return 0;
}