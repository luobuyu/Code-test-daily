#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e2 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
char str[maxn], a[maxn];
char id[3] = "()";
bool check()
{
    stack<int> sta;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '(')
            sta.push(i);
        else
        {
            if (sta.empty())
                return false;
            else
                sta.pop();
        }
    }
    return sta.empty();
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    while (tcase--)
    {
        scanf("%s", str + 1);
        n = strlen(str + 1);
        bool flag = false;
        char typea = str[1];
        char typeb, typec;
        typeb = (typea - 'A' + 1) % 3 + 'A';
        typec = (typea - 'A' + 2) % 3 + 'A';

        for (int i = 0; i <= 1; i++)
        {
            for (int j = 0; j <= 1; j++)
            {
                for (int l = 1; l <= n; ++l)
                {
                    if (str[l] == typea)
                    {
                        a[l] = id[0];
                    }
                    else if (str[l] == typeb)
                    {
                        a[l] = id[i];
                    }
                    else
                    {
                        a[l] = id[j];
                    }
                }
                if (check())
                {
                    flag = 1;
                }
            }
        }
        if (flag)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}