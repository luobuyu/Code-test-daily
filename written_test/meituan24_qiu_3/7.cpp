// #pragma GCC optimize(2)
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

struct Node
{
    int a, b, c, d;
};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    bool flag = true;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!isdigit(s[i]) && s[i] != '.')
        {
            flag = false;
            break;
        }
        if (s[i] == '.')
            cnt++;
    }
    if (s[0] == '.' || s[n - 1] == '.' || cnt != 3)
        flag = false;
    if (!flag)
    {
        cout << "invalid" << endl;
        return 0;
    }
    int start = 0;
    int end;
    int index = 0;
    vector<int> address(4);
    while (end = s.find_first_of('.', start))
    {
        string tmp = s.substr(start, end - start);
        if (tmp == "")
        {
            flag = false;
            break;
        }
        int b = stoi(tmp);
        if (b != 0 && tmp[0] == '0' || b < 0 || b > 255)
        {
            flag = false;
            break;
        }
        address[index] = b;
        if (end == s.npos)
            break;
        start = end + 1;
        index++;
    }
    if (!flag)
    {
        cout << "invalid" << endl;
        return 0;
    }
    string ans;
    if (address[0] >= 1 && address[0] <= 125 || address[0] == 126 && address[1] + address[2] + address[3] == 0)
    {
        ans = "A_address";
    }
    else if (address[0] >= 128 && address[0] <= 191)
    {
        ans = "B_address";
    }
    else if (address[0] >= 192 && address[0] <= 223)
    {
        ans = "C_address";
    }
    else
    {
        ans = "other";
    }
    cout << ans << endl;
    return 0;
}