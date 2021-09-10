/**
md,写完还没测呢，code app直接崩了，代码忘保存，直接没了
**/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int maxn = 1e6 + 10;
const int N = maxn - 10;
ll n, m, k;
ll g[maxn] = {0, 1, 2};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%lld", &n);
    int cnt = 2;
    for(int i = 2; i <= N; i++)
    {
        for(int j = 1; j <= g[i] && cnt <= N; j++)
        {
            g[cnt++] = i;         
        }
    }
    ll last_cnt = 0, last_p = 0, ans = 0;
    for(int i = 1; i <= N; i++)
    {
        last_cnt += (ll) i * g[i];
        last_p += g[i];
        if(last_cnt == n)
        {
            ans = last_p;
            break;
        }
        else if(last_cnt > n)
        {
            last_cnt -= (ll) i * g[i];
            last_p -= g[i];
            ans = last_p + (n - last_cnt - 1) / i + 1;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}