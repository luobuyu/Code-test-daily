#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
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
int nex[10] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
int ney[10] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
ll x, y;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
queue<pair<ll, ll>> q;
map<ll, map<ll, int>> vis;
vector<int> ans;
bool bfs(int &fz, int & fm)
{
    while(!q.empty())
        q.pop();
    ans.clear();
    vis.clear();
    q.push({x, y});
    vis[x][y] = 1;
    while(!q.empty())
    {
        auto out = q.front();
        q.pop();
        ll nx, ny;
        int cnt = 1;
        for (int i = 1; i <= 8; i++)
        {
            nx = out.first + nex[i];
            ny = out.second + ney[i];
            if(gcd(nx, ny) > 1)
            {
                cnt++;
                if(vis[nx][ny] == 0)
                {
                    if(nx == ny)
                        return false;
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        ans.push_back(cnt);
    }
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        sum += ans[i];
    }
    fz = ans[0], fm = sum;
    int tmp;
    tmp = gcd(fz, fm);
    if(tmp != 1)
    {
        fz /= tmp;
        fm /= tmp;
    }

    return true;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
#ifdef COMP_DATA
    freopen("/mnt/f/文档/课件/ACM比赛/2020hdu多校/第四场/data/E.in", "r", stdin);
#else
    freopen("in.txt", "r", stdin);
#endif
#endif
    t = read();
    while(t--)
    {
        scanf("%lld %lld", &x, &y);
        if ((x == y) || gcd(x, y) == 1)
        {
            printf("0/1\n");
        }
        else
        {
            int fz, fm;
            if(bfs(fz, fm))
            {
                printf("%d/%d\n", fz, fm);
            }
            else
            {
                printf("0/1\n");
            }
        }
    }
    return 0;
}