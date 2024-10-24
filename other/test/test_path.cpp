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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
vector<string> split(string &str, char delim)
{
    stringstream ss(str);
    vector<string> ret;
    string s;
    while (getline(ss, s, delim))
    {
        if (s.empty())
            continue;
        ret.emplace_back(s);
    }
    return ret;
}

string solve(string &s1, string &s2)
{
    string s;
    if (s2.size() && s2[0] == '/')
        s = s2;
    else
        s = s1 + "/" + s2;
    auto parser_path = split(s, '/');
    vector<string> ans;
    for (auto &item : parser_path)
    {
        if (item == ".")
            continue;
        else if (item == "..")
        {
            if (ans.size())
                ans.pop_back();
        }
        else
        {
            ans.push_back(item);
        }
    }
    string res = "";
    if (s.size() && s[0] == '/')
        res = "/";
    for (int i = 0; i < ans.size(); ++i)
    {
        if (i != 0)
            res.push_back('/');
        res += ans[i];
    }
    return res;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tcase;
    string s1, s2;
    cin >> tcase;
    while (tcase--)
    {
        cin >> s1 >> s2;
        cout << solve(s1, s2) << endl;
    }

    return 0;
}
/*
/home/zhangshan test./../testfile.txt
/home/zhangshan /usr/shared/lib/..//ld.so
*/