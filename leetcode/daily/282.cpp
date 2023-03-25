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
#ifndef ll
#define ll long long
#endif
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static int INF = 0x3f3f3f3f;
    vector<string> ans;
    string op = "+-*";
    void dfs(int step, ll cur_sum, ll last_sum, string &cur, int &target, string &num)
    {
        if (step == num.length())
        {
            if (cur_sum == target)
                ans.emplace_back(cur);
            return;
        }
        int len = cur.size();
        if (step > 0)
            cur.push_back('+');
        int index = cur.size() - 1;
        ll val = 0;
        for (int i = step; i < num.size(); ++i)
        {
            val = val * 10 + (num[i] - '0');
            cur.push_back(num[i]);
            if (step == 0)
            {
                dfs(i + 1, cur_sum + val, val, cur, target, num);
            }
            else
            {
                cur[index] = '+';
                dfs(i + 1, cur_sum + val, val, cur, target, num);
                cur[index] = '-';
                dfs(i + 1, cur_sum - val, -val, cur, target, num);
                cur[index] = '*';
                dfs(i + 1, cur_sum - last_sum + last_sum * val, last_sum * val, cur, target, num);
            }
            if (i == step && num[i] == '0')
            {
                while (step + 1 < num.size() && num[step + 1] == num[step])
                    step++;
                break;
            }
        }
        cur.resize(len);
    }
    vector<string> addOperators(string num, int target)
    {
        string cur;
        dfs(0, 0, 0, cur, target, num);
        return ans;
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
    cin >> s >> n;
    solution.addOperators(s, n);
    return 0;
}