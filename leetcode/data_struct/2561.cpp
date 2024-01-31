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
    const static int INF = 0x3f3f3f3f;
    const static long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const static long long mod = 1e9 + 7;
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        unordered_map<int, int> mp, mp1;
        int minx = INF;
        for (auto &x : basket1)
        {
            mp[x]++;
            mp1[x]++;
        }
        for (auto &x : basket2)
        {
            mp[x]++;
        }
        for (auto &[key, value] : mp)
        {
            minx = min(minx, key);
            if (value & 1)
                return -1;
        }
        // 最大的跟最小的交换
        vector<int> ans;
        for (auto &[key, value] : mp)
        {
            int cnt = 0;
            if (!mp1.count(key))
            {
                cnt = value / 2;
            }
            else
            {
                cnt = abs(mp1[key] - value / 2);
            }
            for (int i = 0; i < cnt; ++i)
            {
                ans.emplace_back(key);
            }
        }
        sort(ans.begin(), ans.end());
        int ret = 0;
        for (int i = 0, j = ans.size() - 1; i < j; ++i, --j)
        {
            ret += min(ans[i], minx * 2);
        }
        return ret;
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
    vector<int> a = {84, 80, 43, 8, 80, 88, 43, 14, 100, 88};
    vector<int> b = {32, 32, 42, 68, 68, 100, 42, 84, 14, 8};
    solution.minCost(a, b);
    return 0;
}