#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

map<string, int> mp;
char str[maxn];

struct Card
{
    int a[5];
} card[maxn];

void init()
{
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;

    mp["diamond"] = 1;
    mp["squiggle"] = 2;
    mp["oval"] = 3;

    mp["solid"] = 1;
    mp["striped"] = 2;
    mp["open"] = 3;

    mp["red"] = 1;
    mp["green"] = 2;
    mp["purple"] = 3;
}

bool check(int i, int j, int k)
{
    for (int p = 1; p <= 4; p++)
    {
        if (card[i].a[p] == -1 || card[j].a[p] == -1 || card[k].a[p] == -1)
            continue;
        if ((card[i].a[p] == card[j].a[p] && card[i].a[p] != card[k].a[p]) ||
            (card[i].a[p] == card[k].a[p] && card[i].a[p] != card[j].a[p]) ||
            (card[j].a[p] == card[k].a[p] && card[i].a[p] != card[j].a[p]))
        {
            return false;
        }
    }

    return true;
}

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
    init();
    scanf("%d", &t);
    for (int tcase = 1; tcase <= t; tcase++)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", str);
            int start = 1;
            for (int j = 1; j <= 4; j++)
            {
                string tmp = "";
                while (str[start] != ']')
                {
                    tmp += str[start];
                    start++;
                }
                start++;
                if (str[start] == '[')
                    start++;
                if (tmp == "*")
                {
                    card[i].a[j] = -1;
                }
                else
                {
                    card[i].a[j] = mp[tmp];
                }
            }
        }
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                for (int k = j + 1; k <= n; k++)
                {
                    if (check(i, j, k))
                    {
                        printf("Case #%d: %d %d %d\n", tcase, i, j, k);
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        if(!flag)
            printf("Case #%d: -1\n", tcase);
    }

    return 0;
}