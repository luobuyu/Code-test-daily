#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
    ll x = 0; char ch = getchar();
    bool f = 1;
    for(; ch > '9' || ch < '0'; ch = getchar()) if(ch == '-')
        f = 0;
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        x = (x << 1) + (x << 3) + (ch ^ 48);
    return f ? x : -x;
}
char charSet[4] = "gao";
bool vis[100] = {0};
int solve(char* s)
{
    int res = 0;
    for (int chance = 1; chance--;)
    {
        char last = 0;
        int cnt = 0, pos[4];
        for (int i = 0; i < 9; ++i)
        {
            if (s[i] == '0')
                continue;
            if (s[i] == last)
                pos[cnt += 1] = i;
            else
                last = s[i], pos[cnt = 1] = i;
            if (cnt == 3)
            {
                //vis[last] = 0;
                s[i] = s[pos[2]] = s[pos[1]] = '0';
                break;
            }
        }
        if (cnt == 3)
            res++, chance++;
    }
    int tmp = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (!vis[charSet[i]])
            continue;
        vis[charSet[i]] = 0;
        char ts[10] = {0};
        for (int j = 0; j < 9; ++j)
            ts[j] = s[j] == charSet[i] ? '0' : s[j];
        tmp = max(tmp, solve(ts));
        vis[charSet[i]] = 1;
    }
    return res + tmp;
}
int main()
{
    // char s[10];
    // for (int T = read(); T--;)
    // {
    //     scanf("%s", s);
    //     vis['g'] = 1; vis['a'] = 1;
    //     vis['o'] = 1;
    //     printf("%d\n", solve(s));
    // }
    return 0;
}