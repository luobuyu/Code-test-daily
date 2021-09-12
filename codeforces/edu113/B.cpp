#include <bits/stdc++.h>
#define ll long long
#define lll long long
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
string s;
char ans[maxn][maxn];
vector<int> b;
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
        read(n);
        cin >> s;
        b.clear();
        memset(ans, 0, sizeof(ans));
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '2')
            {
                cnt++;
                b.push_back(i);
            }
        }
        if (cnt == 1 || cnt == 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            if (cnt > 2)
            {
                for (int i = 0; i < cnt - 1; i++)
                {
                    ans[b[i]][b[i + 1]] = '+';
                    ans[b[i + 1]][b[i]] = '-';
                }
                ans[b[cnt - 1]][b[0]] = '+';
                ans[b[0]][b[cnt - 1]] = '-';
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j)
                    {
                        printf("X");
                    }
                    else if (ans[i][j] == 0)
                    {
                        printf("=");
                    }
                    else
                    {
                        printf("%c", ans[i][j]);
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}