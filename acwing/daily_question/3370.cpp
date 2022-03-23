#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
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
unordered_map<string, int> dis;
unordered_map<string, int> order = {
    {"Ox", 0}, {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3}, {"Snake", 4}, {"Horse", 5}, {"Goat", 6}, {"Monkey", 7}, {"Rooster", 8}, {"Dog", 9}, {"Pig", 10}, {"Rat", 11}};
string s[maxn];
unordered_map<string, int> sx;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    sx["Bessie"] = 0;
    dis["Bessie"] = 0;
    while (n--)
    {
        for (int i = 1; i <= 8; i++)
        {
            cin >> s[i];
        }
        // s[4] s[5]
        sx[s[1]] = order[s[5]];
        int tmp = 0;
        if (sx[s[1]] == sx[s[8]])
        {
            if (s[4] == "previous")
            {
                dis[s[1]] = dis[s[8]] - 12;
            }
            else
            {
                dis[s[1]] = dis[s[8]] + 12;
            }
        }
        else
        {
            if (s[4] == "previous")
            {
                dis[s[1]] = dis[s[8]] - ((sx[s[8]] - sx[s[1]] + 12) % 12);
            }
            else
            {
                dis[s[1]] = dis[s[8]] + ((sx[s[1]] - sx[s[8]] + 12) % 12);
            }
        }
    }
    cout << abs(dis["Elsie"]) << endl;
    return 0;
}