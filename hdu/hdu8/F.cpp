#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int read()
{
    int x = 0, flag = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            flag = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    }
    if (flag)
        return -x;
    return x;
}
int t, n, m, k, p;

struct Node
{
    int l, r;
} node[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int tcase = read();
    while (tcase--)
    {
        n = read(), k = read();
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            node[i].l = read(), node[i].r = read();
        }
        for (int i = n - 1; i >= 1; i--)
        {
            node[i].r = min(node[i + 1].r + k, node[i].r);
            node[i].l = max(node[i + 1].l - k, node[i].l);
            if (node[i].l > node[i].r)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int i = 2; i <= n; i++)
            {
                node[i].r = min(node[i - 1].r + k, node[i].r);
                node[i].l = max(node[i - 1].l - k, node[i].l);
                if (node[i].l > node[i].r)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                printf("YES\n");
                for (int i = 1; i <= n; i++)
                {
                    printf("%d%c", node[i].l, " \n"[i == n]);
                }
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            printf("NO\n");
            continue;
        }
    }
    return 0;
}