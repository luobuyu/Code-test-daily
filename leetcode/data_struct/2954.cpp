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
const static int maxn = 1e5 + 10;
const static int maxm = 1e5 + 10;
const static long long mod = 1e9 + 7;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
long long fac[maxn], ifac[maxn];
long long qpow(long long a, long long b)
{
    long long ret = 1, tmp = a;
    while (b)
    {
        if (b & 1)
            ret = ret * tmp % mod;
        tmp = tmp * tmp % mod;
        b >>= 1;
    }
    return ret;
}
auto init = [](int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    ifac[n] = qpow(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; --i)
    {
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    }
    return 0;
}(maxn - 1);

long long Cnm(long long n, long long m)
{
    return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
class Solution
{
public:
    int numberOfSequence(int n, vector<int> &sick)
    {
        int pre = -1;
        vector<int> nums;
        sick.emplace_back(n);
        long long sum = 0;
        for (auto &x : sick)
        {
            int tmp = x - pre - 1;
            pre = x;
            if (tmp == 0)
                continue;
            nums.emplace_back(tmp);
            sum += tmp;
        }
        if (sick[0] != 0)
            sum -= sick[0];
        if (sick[sick.size() - 1] != n - 1)
            sum -= (n - sick[sick.size() - 1] - 1);

        long long ans = 0;
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
    vector<int> a = {0, 4};
    cout << solution.numberOfSequence(5, a) << endl;
    return 0;
}