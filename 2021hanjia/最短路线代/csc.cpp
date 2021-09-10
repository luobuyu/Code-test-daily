#include <bits/stdc++.h>
#define cmp 1e-5
using namespace std;
struct node
{
    double a[510];
    int w;
    bool operator<(const node x) const
    {
        return w < x.w;
    }
};
node q[510];
int p[510], n, m, ans, cnt;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%lfd", &q[i].a[j]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &q[i].w);
    sort(q + 1, q + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (q[i].a[j] <= cmp && q[i].a[j] >= -cmp)
                continue;
            if (!p[j])
            {
                p[j] = i;
                cnt++;
                ans += q[i].w;
                break;
            }
            else
            {
                double alpha = q[i].a[j] / q[p[j]].a[j];
                for (int k = j; k <= m; k++)
                {
                    q[i].a[k] -= alpha * q[p[j]].a[k];
                }
            }
        }
    }
    printf("%d %d", cnt, ans);
}