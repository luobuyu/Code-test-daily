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
    stack<char> op;
    stack<set<string>> s;

    set<string> cal()
    {
        auto opch = op.top();
        op.pop();
        set<string> b = s.top();
        s.pop();
        set<string> a = s.top();
        s.pop();
        if (opch == '+')
        {
            for (auto &u : b)
                a.insert(u);
            return a;
        }
        else
        {
            set<string> ret;
            for (auto &u : a)
            {
                for (auto &v : b)
                {
                    ret.insert(u + v);
                }
            }
            return ret;
        }
    }
    vector<string> braceExpansionII(string expression)
    {
        expression.push_back('#');
        for (int i = 0; i < expression.length(); ++i)
        {
            if (isalpha(expression[i]))
            {
                if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1])))
                {
                    op.push('*');
                }
                set<string> tmp;
                tmp.insert(string(1, expression[i]));
                s.push(tmp);
            }
            else if (expression[i] == '{')
            {
                if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1])))
                {
                    op.push('*');
                }
                op.push('(');
            }
            else if (expression[i] == '}')
            {
                while (op.size() && op.top() != '(')
                {
                    s.push(cal());
                }
                op.pop();
            }
            else if (expression[i] == ',') // 加号，优先级低
            {
                while (op.size() && op.top() == '*')
                {
                    s.push(cal());
                }
                op.push('+');
            }
            else if (expression[i] == '#')
            {
                while (op.size())
                {

                    s.push(cal());
                }
            }
        }
        return {s.top().begin(), s.top().end()};
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
    Solution solution;
    cin >> s;
    for (auto &u : solution.braceExpansionII(s))
    {
        cout << u << endl;
    }
    return 0;
}