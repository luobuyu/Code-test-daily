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
class Solution
{
public:
    set<string> word(string &s, int &index)
    {
        set<string> ret;
        if (s[index] == '{')
        {
            index++;
            ret = expre(s, index);
        }
        else
        {
            ret.insert(string(1, s[index]));
        }
        index++;
        return ret;
    }

    // 完整表达式，没有逗号隔开
    set<string> item(string &s, int &index)
    {
        set<string> ret;
        while (true)
        {
            if (index < s.length() && (s[index] == '{' || s[index] >= 'a' && s[index] <= 'z'))
            {
                set<string> tmp = word(s, index);
                set<string> ans;
                if (ret.size() == 0)
                    ret = tmp;
                else
                {
                    for (auto &u : ret)
                    {
                        for (auto &v : tmp)
                        {
                            ans.insert(u + v);
                        }
                    }
                    ret = ans;
                }
            }
            else
            {
                break;
            }
        }
        return ret;
    }

    set<string> expre(string &s, int &index)
    {
        set<string> ret;
        while (true)
        {
            // 用逗号隔开的表达式
            for (auto &ss : item(s, index))
                ret.insert(ss);
            if (index < s.length() && s[index] == ',')
            {
                index++;
                continue;
            }
            else
                break;
        }
        return ret;
    }
    vector<string> braceExpansionII(string s)
    {
        int index = 0;
        set<string> ret = expre(s, index);
        return vector<string>(ret.begin(), ret.end());
    }
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
    Solution solve;
    auto ans = solve.braceExpansionII(s);
    for (auto &u : ans)
    {
        cout << u << endl;
    }
    return 0;
}