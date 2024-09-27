#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int n, m, q, k;
char a[maxn][maxn];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool check(int x, int y)
{
    bool flag = true;
    unordered_set<char> s;
    for (int i = x; i < x + 3; ++i)
    {
        for (int j = y; j < y + 3; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                int newx = dx[k] + i;
                int newy = dy[k] + j;
                if(newx < x || newx >= x + 3 || newy < y || newy >= y + 3) continue;
                if(a[newx][newy] == a[i][j]) 
                {
                    flag = false;
                    return false;
                }
            }
            if(a[i][j] < 'A' || a[i][j] > 'C')
                return false;
            s.insert(a[i][j]);
         }
    }
    return s.size() == 3;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < m - 2; ++j)
        {
            ans += check(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}