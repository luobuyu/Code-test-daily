// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{
    static string buf_line;
    static int _i;
    static int _n;
    static char _ch;
    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        _ch = buf_line[_i++];
        while (_ch < '0' || _ch > '9')
        {
            if (_ch == '-')
                flag = -1;
            _ch = buf_line[_i++];
        }
        while (_ch >= '0' && _ch <= '9')
        {
            x = (x << 3) + (x << 1) + (_ch ^ 48), _ch = buf_line[_i++];
        }
        x *= flag;
        return true;
    }

    template <class T, class... _T>
    inline bool read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline bool getline()
    {
        if (!getline(cin, buf_line))
            return false;
        _i = 0, _n = buf_line.length();
        return true;
    }
    template <class T>
    inline void show(T *a, int n)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            cout << a[i];
        }
        cout << "]";
    }

    bool endofl()
    {
        if (_i >= _n)
            return true;
        if (_i == 0)
            return false;
        if (buf_line[_i - 1] == ']')
        {
            _i++;
            return true;
        }
        return false;
    }

    template <class T, std::size_t Num>
    inline void show(T a[][Num], int n, int m)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            show(a[i], m);
        }
        cout << "]";
    }

} // namespace FAST_IO
using namespace FAST_IO;

// int init = []
// {
//     /*********** fast_read ***************/
//     freopen("user.out", "w", stdout);
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     /*************************************/

//     while (true)
//     {
//         if (!getline())
//             break;

//         getline();
//     }
//     exit(0);
//     return 0;
// }();

auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    stack<char> op;
    stack<int> nums;
    int level(char ch)
    {
        switch (ch)
        {
        case '#':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        }
        return -1;
    }
    int cal(int a, int b, char op)
    {
        switch (op)
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        }
        return -1;
    }
    int calculate(string s)
    {
        // 去除所有空格
        string ss;
        for (auto &x : s)
        {
            if (x != ' ')
                ss += x;
        }
        s = ss;
        s += '#';
        int tmp = 0;
        if (s[0] == '-')
            s = '0' + s;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '-' && s[i - 1] == '(')
            {
                nums.push(0);
                op.push('-');
                continue;
            }
            if (isdigit(s[i]))
            {
                tmp = tmp * 10 + (s[i] - '0');
                if (!isdigit(s[i + 1]))
                {
                    nums.push(tmp);
                    tmp = 0;
                }
            }
            else if (s[i] == ')')
            {
                while (op.top() != '(')
                {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    char type = op.top();
                    op.pop();
                    nums.push(cal(a, b, type));
                }
                op.pop();
            }
            else
            {
                if (s[i] == '(')
                {
                    op.push(s[i]);
                    continue;
                }
                while (op.size() && op.top() != '(' && level(op.top()) >= level(s[i]))
                {
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    char type = op.top();
                    op.pop();
                    nums.push(cal(a, b, type));
                }
                op.push(s[i]);
            }
        }
        return nums.top();
    }
};

int t, n, m, k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    cout << solution.calculate("- (3 - (- (4 + 5) ) )") << endl;
    return 0;
}