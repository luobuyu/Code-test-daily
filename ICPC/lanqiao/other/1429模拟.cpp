#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 10;
int n, m;

int a[maxn][maxn];
int dx[5] = {-1, 0, 1, 0}, dy[5] = {0, 1, 0, -1};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int sx, sy, k;
    char x;
    cin >> sx >> sy >> x >> k;
    int newx = sx, newy = sy;

    while (k--)
    {
        if (x == 'U')
        {
            if (a[newx][newy])
            {
                x = 'R';
                a[newx][newy] ^= 1;
                newx += dx[1];
                newy += dy[1];
            }
            else
            {
                x = 'L';
                a[newx][newy] ^= 1;
                newx += dx[3];
                newy += dy[3];
            }
        }
        else if (x == 'R')
        {
            if (a[newx][newy])
            {
                x = 'D';
                a[newx][newy] ^= 1;
                newx += dx[2];
                newy += dy[2];
            }
            else
            {
                x = 'U';
                a[newx][newy] ^= 1;
                newx += dx[0];
                newy += dy[0];
            }
        }
        else if (x == 'D')
        {
            if (a[newx][newy])
            {
                x = 'L';
                a[newx][newy] ^= 1;
                newx += dx[3];
                newy += dy[3];
            }
            else
            {
                x = 'R';
                a[newx][newy] ^= 1;
                newx += dx[1];
                newy += dy[1];
            }
        }
        else if (x == 'L')
        {
            if (a[newx][newy])
            {
                x = 'U';
                a[newx][newy] ^= 1;
                newx += dx[0];
                newy += dy[0];
            }
            else
            {
                x = 'D';
                a[newx][newy] ^= 1;
                newx += dx[2];
                newy += dy[2];
            }
        }
    }
    cout << newx << ' ' << newy << endl;
    return 0;
}