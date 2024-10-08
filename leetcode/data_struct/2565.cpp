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
    int minimumScore(string s, string t)
    {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;
        vector<int> pre(n);
        // 删除的是 t 子串，剩余的需要和s前缀后缀匹配
        // 最短子串，最长前缀，最长后缀
        while (i < n)
        {
            pre[i] = (i == 0 ? 0 : pre[i - 1]);
            if (j < m && s[i] == t[j])
            {
                pre[i] = j + 1;
                ++j;
            }
            ++i;
        }
        vector<int> suf(n + 1);
        i = n - 1, j = m - 1;
        while (i >= 0)
        {
            suf[i] = (i == n - 1 ? 0 : suf[i + 1]);
            if (j >= 0 && s[i] == t[j])
            {
                suf[i] = m - j;
                --j;
            }
            --i;
        }
        int ans = INF;
        ans = min(ans, m - pre[n - 1]);
        ans = min(ans, m - suf[0]);
        if (ans == 0)
            return ans;
        for (int i = 0; i < n; ++i)
        {
            if (pre[i] + suf[i + 1] >= m)
                return 0;
            ans = min(ans, m - pre[i] - suf[i + 1]);
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
    string s = "abacaba";
    string t = "bzaa";
    solution.minimumScore(s, t);
    return 0;
}