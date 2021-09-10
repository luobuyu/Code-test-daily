#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
int n, m, t;
int ans[maxn];
vector<int> order[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m >> t;
    int ts, id;
    for(int i = 1; i <= m; i++)
    {
        cin >> ts >> id;
        order[id].push_back(ts);
    }
    for(int i = 1; i <= n; i++)
    {
        sort(order[i].begin(), order[i].end());
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int tmp = 0;
        bool flag = false;
        int pre = 0;
        for(int j = 0; j < order[i].size(); j++)
        {
            tmp -= max(order[i][j]- pre - 1, 0);
            tmp = max(tmp, 0);
            if(flag == true && tmp <= 3) flag = false;
            tmp += 2;
            if(tmp > 5 && flag == false) flag = true;
            //if(i==2)cout << tmp << endl;
            pre = order[i][j];
        }
        tmp -= (t - pre);
        if(tmp <= 3 && flag == true) flag = false;
        if(flag) ans++;
    }
    cout << ans << endl;
}