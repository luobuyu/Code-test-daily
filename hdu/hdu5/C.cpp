#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e6 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

vector<int> node[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    scanf("%d", &t);
    while (t--)
    {
        int n, k, len;
        scanf("%d%d", &n, &k);
        len = 2 * n * pow(2, k);
        for (int i = 1; i <= len; i++)
            node[i].clear();
        for (int i = 1; i <= len; i++)
        {
            int a;
            scanf("%d", &a);
            node[i].push_back(a);
        }
        int mid = 1;
        while (k--)
        {
            mid = (mid + len) / 2;
            for (int j = mid + 1; j <= len; j++) //j标记下半段
            {
                int pos = mid - (j - (mid + 1));             //pos标记上半段
                reverse(node[pos].begin(), node[pos].end()); //将上半段的数据反向之后复制到对应下半段的开头。
                node[j].insert(node[j].begin(), node[pos].begin(), node[pos].end());
                node[pos].clear(); //将上半段的清空
            }
        }
        for (int i = len - 2 * n + 1; i <= len; i++)
        {
            for (int j = 0; j < node[i].size(); j++)
            {
                if (j == node[i].size() - 1 && i == len)
                    printf("%d", node[i][j]);
                else
                    printf("%d ", node[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}