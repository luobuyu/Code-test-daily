#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 100 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

char s[maxn];
vector<int> num[4];
int maxx;
char op;
void getNum()
{
    for(int i = 1; i <= 3; i++)
    {
        num[i].clear();
    }
    int len = strlen(s + 1);
    int now = 1;
    for (int i = 1; i <= len; i++)
    {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F'))
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num[now].push_back(s[i] - '0');
                maxx = max(maxx, s[i] - '0' + 1);
            }
            else
            {
                num[now].push_back(s[i] - 'A' + 10);
                maxx = max(maxx, s[i] - 'A' + 11);
            }
        }
        else
        {
            now++;
            if(s[i] != '=')
            {
                op = s[i];
            }
        }
    }
}

ll getMaxxNum(int x, int maxx)
{
    ll ret = 0;
    for(int i = 0; i < num[x].size(); i++)
    {
        ret = ret * maxx + (ll)num[x][i];
    }
    return ret;
}

int getAns()
{
    for(int i = maxx; i <= 16; i++)
    {
        ll a = getMaxxNum(1, i);
        ll b = getMaxxNum(2, i);
        ll c = getMaxxNum(3, i);
        ll tmp = 0;
        if(op == '+') tmp = a+ b;
        else if(op == '-') tmp = a - b;
        else if(op == '*') tmp = a * b;
        else
        {
            if(b == 0 || a % b)
                continue;
            tmp = a / b;
        }
        if(tmp == c)
            return i;
    }
    return -1;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第六场/1002/data.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    while(scanf("%s", s + 1) != EOF)
    {
        maxx = 2;
        getNum();
        printf("%d\n", getAns());
    }
    return 0;
}