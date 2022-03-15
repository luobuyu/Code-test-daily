#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int bitree[15];
int inde[15];

void func(int x, int y)
{
    int len = 0;
    while (x != y)
    {
        if (x > y)
            x /= 2;
        else
            y /= 2;
        len++;
    }
    cout << len << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t, n, m, x, y;
    while (cin >> t)
    {
        if (t <= 0)
            return 0;
        t--;
        cin >> n >> m;
        memset(bitree, 0, sizeof(bitree));
        bitree[1] = 1;
        inde[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            if (x > 0)
                inde[x] = inde[i] * 2;
            if (y > 0)
                inde[y] = 2 * inde[i] + 1;
            bitree[inde[x]] = x;
            bitree[inde[y]] = y;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            func(inde[x], inde[y]);
        }
    }
    return 0;
}
