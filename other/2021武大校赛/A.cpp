#include <bits/stdc++.h>
#define ll long long
#define lll long long
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[100000], *p1 = buf, *p2 = buf;
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
string p, a;
map<char, string> mp;
void init()
{
    mp['0'] = "0000";
    mp['1'] = "0001";
    mp['2'] = "0010";
    mp['3'] = "0011";
    mp['4'] = "0100";
    mp['5'] = "0101";
    mp['6'] = "0110";
    mp['7'] = "0111";
    mp['8'] = "1000";
    mp['9'] = "1001";
    mp['A'] = "1010";
    mp['B'] = "1011";
    mp['C'] = "1100";
    mp['D'] = "1101";
    mp['E'] = "1110";
    mp['F'] = "1111";
}
string hexbin(string a)
{
    string ret;
    string tmp;
    for (int i = 0; i < a.length(); i++)
    {
        tmp = mp[a[i]];
        if (i == 0)
        {
            int pos = 0;
            bool flag = true;
            string bb;
            for (int j = 0; j < tmp.length(); j++)
            {
                if (tmp[j] != '0')
                {
                    flag = false;
                }
                if (flag == false)
                {
                    bb.push_back(tmp[j]);
                }
            }
            tmp = bb;
        }
        ret += tmp;
    }
    return ret;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int tcase;
    cin >> tcase;
    while (tcase--)
    {
        a.clear(), p.clear();
        cin >> p >> a;
        k = p.length() - 1;
        a = hexbin(a);
        for (int i = 0; i < k; i++)
            a.push_back('0');
        int len = a.length();
        int cnt;
        for (int i = 0; i < len - k; i++)
        {
            cnt = 0;
            bool flag = true;
            for (int j = 0; j < k + 1; j++)
            {
                a[i + j] = ((a[i + j] - '0') ^ (p[j] - '0')) + '0';
                if (a[i + j] == '0' && flag)
                    cnt++;
                else
                    flag = false;
            }
            cnt--;
            i += cnt;
        }
        string ans = a.substr(len - k, k);
        cout << ans << endl;
    }
    return 0;
}