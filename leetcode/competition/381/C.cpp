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

    int min_key_presses(const std::string &word)
    {
        // 定义字母到电话按键的映射
        std::unordered_map<char, int> key_mapping = {
            {'a', 2},
            {'b', 2},
            {'c', 2},
            {'d', 3},
            {'e', 3},
            {'f', 3},
            {'g', 4},
            {'h', 4},
            {'i', 4},
            {'j', 5},
            {'k', 5},
            {'l', 5},
            {'m', 6},
            {'n', 6},
            {'o', 6},
            {'p', 7},
            {'q', 7},
            {'r', 7},
            {'s', 7},
            {'t', 8},
            {'u', 8},
            {'v', 8},
            {'w', 9},
            {'x', 9},
            {'y', 9},
            {'z', 9},
        };

        int total_pushes = 0;
        int prev_key = -1;

        for (char letter : word)
        {
            int key = key_mapping[letter];

            // 如果当前按键与上一个按键相同，则添加一个空格按键
            if (key == prev_key)
            {
                total_pushes += 1;
            }

            // 计算当前字母所需的按键次数
            total_pushes += key_mapping[letter];

            // 更新上一个按键
            prev_key = key;
        }

        return total_pushes;
    }
    int minimumPushes(string word)
    {
        return min_key_presses(word);
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
    solution.minimumPushes(7, 2);
    return 0;
}