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

    int calculate(string s)
    {
        // 去除所有空格
        stack<int> nums;
        string ss;
        for (auto &x : s)
            if (x != ' ')
                ss += x;
        s = ss;
        int n = s.length();
        int i = 0;
        int num = 0;
        char sign = '+';
        while (i < n)
        {
            if (s[i] == '(')
            {
                int left = 1;
                int j = i + 1;
                for (; j < n; ++j)
                {
                    if (s[j] == ')')
                        --left;
                    if (s[j] == '(')
                        ++left;
                    if (left == 0)
                        break;
                }
                num = calculate(s.substr(i + 1, j - i - 1));
                i = j;
            }
            if (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            if (!isdigit(s[i]) || i == n - 1)
            {
                if (sign == '+')
                    nums.push(num);
                else if (sign == '-')
                    nums.push(-num);
                else if (sign == '*')
                {
                    int a = nums.top();
                    nums.pop();
                    nums.push(a * num);
                }
                else if (sign == '/')
                {
                    int a = nums.top();
                    nums.pop();
                    nums.push(a / num);
                }
                num = 0;
                sign = s[i];
            }
            ++i;
        }
        int ans = 0;
        while (nums.size())
        {
            ans += nums.top();
            nums.pop();
        }
        return ans;
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
    cout << solution.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    return 0;
}