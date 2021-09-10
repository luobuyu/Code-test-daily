#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
int n, k;
int a[maxn];
int st[maxn], top;
int ans[maxn];
bool vis[maxn];
int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int x1, y1, gcd;
    gcd = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return gcd;
}

int getinv(int a, int b)
{
    int x, y;
    exgcd(a, b, x, y);
    x %= b;
    if (x < 0)
        x += b;
    return x;
}
void getCycle(int x)
{
    top = 0;
    do
    {
        vis[x] = true;
        st[++top] = x;
        x = a[x];
    } while (!vis[x]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            getCycle(i);
            int inv = getinv(k, top);
            int j;
            for (j = 1; j <= top; j++)
            {
                if (i == st[j])
                    break;
            }
            for (int k = 1; k <= inv; k++)
            {
                j++;
                if (j > top)
                    j = 1;
            }
            ans[i] = st[j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}