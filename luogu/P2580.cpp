#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e4 + 10;
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
int t, n, m, k;
struct Trie
{
    static const int M = 30;          // 字符集大小
    int nex[maxn][M], cnt, val[maxn]; // cnt记录点号
    bool exist[maxn];
    int times[maxn];
    void ins(char *s)
    {
        int now = 0, len = strlen(s + 1); // 下标从1开始
        for (int i = 1; i <= len; i++)
        {
            int c = s[i] - 'a';
            if (!nex[now][c])
                nex[now][c] = ++cnt;
            ++val[now]; // 记录该前缀的数量
            now = nex[now][c];
        }
        exist[now] = 1;
    }

    bool find(char *s, int &x)
    {
        int now = 0, len = strlen(s + 1);
        for (int i = 1; i <= len; i++)
        {
            int c = s[i] - 'a';
            if (!nex[now][c])
                return false;
            now = nex[now][c];
        }
        times[now]++;
        x = times[now];
        return exist[now];
    }
} trie;

char name[60];
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
    n = read();
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", name + 1);
        trie.ins(name);
    }

    m = read();
    for (int i = 1; i <= m; i++)
    {
        int times = -1;
        scanf("%s", name + 1);
        if (trie.find(name, times))
            if (times == 1)
                printf("OK\n");
            else
                printf("REPEAT\n");
        else
            printf("WRONG\n");
    }
    return 0;
}