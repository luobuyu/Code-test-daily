#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll read()
{
    ll x = 0;
    char ch = getchar();
    bool f = 1;
    for (; ch > '9' || ch < '0'; ch = getchar())
        if (ch == '-')
            f = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? x : -x;
}

const int N = 1002;
int p, d, v;
int dist[N][2];
int ans[2];

int main()
{
    p = read();
    d = read();
    for (int i = 1; i <= p; ++i)
    {
        int district = read();
        dist[district][0] += read();
        dist[district][1] += read();
    }

    for (int i = 1; i <= d; ++i)
    {
        int sum = dist[i][0] + dist[i][1];
        v += sum;
        if (dist[i][0] > dist[i][1])
        {
            int a = dist[i][0] - (sum / 2 + 1);
            int b = dist[i][1];
            ans[0] += a;
            ans[1] += b;
            printf("A %d %d\n", a, b);
        }
        else
        {
            int a = dist[i][0];
            int b = dist[i][1] - (sum / 2 + 1);
            ans[0] += a;
            ans[1] += b;
            printf("B %d %d\n", a, b);
        }
    }
    printf("%.10lf", (double)abs(ans[0] - ans[1]) / v);
    return 0;
}