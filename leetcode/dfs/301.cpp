// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
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
int t, n, m, k;
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;
    set<string> ans;
    vector<int> vis;
    void dfs(int step, int l, int r, int n, string &s)
    {
        if (l == 0 && r == 0)
        {
            if (check(s))
            {
                string tmp;
                for (int i = 0; i < s.length(); ++i)
                {
                    if (s[i] != '.')
                        tmp.push_back(s[i]);
                }
                ans.insert(tmp);
            }
            return;
        }
        if (l + r > n - step)
            return;
        if (step > 0 && !vis[step - 1] && s[step] == s[step - 1])
            dfs(step + 1, l, r, n, s);
        else if (l > 0 && s[step] == '(')
        {
            s[step] = '.';
            dfs(step + 1, l - 1, r, n, s);
            s[step] = '(';
            dfs(step + 1, l, r, n, s);
        }
        else if (r > 0 && s[step] == ')')
        {
            s[step] = '.';
            dfs(step + 1, l, r - 1, n, s);
            s[step] = ')';
            dfs(step + 1, l, r, n, s);
        }
        else if (s[step])
            dfs(step + 1, l, r, n, s);
    }
    bool check(string s)
    {
        int tmp = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
                tmp++;
            else if (s[i] == ')')
            {
                tmp--;
                if (tmp < 0)
                    return false;
            }
        }
        return tmp == 0;
    }
    vector<string> removeInvalidParentheses(string s)
    {
        int l = 0, r = 0;
        vis.resize(s.length());
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
                l++;
            else if (s[i] == ')')
                if (l == 0)
                    r++;
                else
                    l--;
        }
        string cur;
        dfs(0, l, r, s.length(), s);
        if (ans.size() == 0)
            return vector<string>(1, "");
        return vector<string>(ans.begin(), ans.end());
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
    Solution solution;
    string s;
    while (cin >> s)
    {
        solution.ans.clear();
        auto ans = solution.removeInvalidParentheses(s);
        for (auto u : ans)
        {
            cout << u << endl;
        }
        cout << "------------" << endl;
    }
    return 0;
}