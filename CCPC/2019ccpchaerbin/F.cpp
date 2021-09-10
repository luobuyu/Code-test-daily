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

bool num[6][6];

int need[6] = {'h' - 'a', 0, 'r' - 'a', 1, 'i' - 'a', 'n' - 'a'};
queue<int> q;

bool solve(int step)
{
    if (step == 0)
        return true;
    for (int i = 0; i < step; ++i)
    {
        int tmp = q.front();
        q.pop();
        if (num[6 - step][tmp] && solve(step - 1))
            return true;
        q.push(tmp);
    }
    return false;
}

int main()
{
    // #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    for (int T = read(); T--;)
    {
        string s;
        int tmp[26] = {0};
        memset(num, 0, sizeof(num));
        for (int i = 0; i < 6; ++i)
        {
            cin >> s;
            for (auto &i : s)
            {
                tmp[i - 'a']++;
            }
            for (int j = 0; j < 6; ++j)
            {
                num[i][j] = tmp[need[j]] > 0;
            }
        }
        while (!q.empty())
            q.pop();
        for (int i = 0; i < 6; ++i)
            q.emplace(i);
        if (solve(6))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}