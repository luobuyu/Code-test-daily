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
    int maximumXorProduct(long long a, long long b, int n)
    {
        long long mod = 1e9 + 7;
        long long x = 0;
        if (n == 0)
            return (a % mod) * (b % mod) % mod;
        if (a > b)
            swap(a, b);
        long long p = 0, q = 0;
        // a < b;
        int index = 0;
        for (int i = 50; i >= 0; --i)
        {
            if (b >> i & 1 == 1)
            {
                index = i;
                break;
            }
        }
        bool flag = true; // 前面全相等
        for (int i = index; i >= n; --i)
        {
            if ((a >> i & 1) != (b >> i & 1))
                flag = false;
            if (a >> i & 1 == 1)
                p |= (1ll << i);
            if (b >> i & 1 == 1)
                q |= (1ll << i);
        }
        if (flag)
        {
            bool ff = false;
            for (int i = n - 1; i >= 0; --i)
            {
                if ((a >> i & 1) == (b >> i & 1))
                {
                    p |= (1ll << i);
                    q |= (1ll << i);
                }
                else
                {
                    if (!ff)
                    {
                        p |= (1ll << i);
                        ff = true;
                    }
                    else
                    {
                        q |= (1ll << i);
                    }
                }
            }
        }
        else
        {
            // a < b
            for (int i = n - 1; i >= 0; --i)
            {
                if ((a >> i & 1) != (b >> i & 1))
                {
                    p |= (1ll << i);
                }
                else
                {
                    p |= (1ll << i);
                    q |= (1ll << i);
                }
            }
        }
        p %= mod;
        q %= mod;
        return p * q % mod;
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
    solution.maximumXorProduct(8, 9, 1);
    return 0;
}