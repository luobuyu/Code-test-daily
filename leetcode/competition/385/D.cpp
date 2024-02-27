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
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    long long mod = 1e9 + 7;
    int base = 131;
    long long hash[maxn], pow[maxn];
    void init(string &s, int n)
    {
        pow[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            pow[i + 1] = pow[i] * base % mod;
            hash[i + 1] = (hash[i] * base + (s[i] - '0')) % mod;
        }
    }
    long long get_hash(int l, int r)
    {
        return (hash[r + 1] - hash[l] * pow[r - l + 1] % mod + mod) % mod;
    }
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        unordered_map<long long, long long> mp;
        long long ans = 0;
        srand(time(0));
        mod = 998244353 + rand() % 10007;
        base = 33 + rand() % 233;
        for (int i = n - 1; i >= 0; --i)
        {
            int len = words[i].length();
            init(words[i], len);
            int h = get_hash(0, len - 1);
            if (mp.count(h))
                ans += mp[h];
            for (int j = 1; j <= len; ++j)
            {
                long long h1 = get_hash(0, j - 1);
                long long h2 = get_hash(len - j, len - 1);
                if (h1 == h2)
                {
                    mp[get_hash(0, j - 1)]++;
                }
            }
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
    vector<string> a = {"pa", "papa", "ma", "mama"};
    solution.countPrefixSuffixPairs(a);
    return 0;
}