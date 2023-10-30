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
    int check(int mid, vector<int> &a)
    {
        // 每组都为 mid + 1，或 mid
        int ret = 0;
        for (auto &x : a)
        {
            int p = x / mid;
            int r = x % mid;
            if (p < r)
                return -1;
            // p >= r;
            if ((p - r) >= (mid + 1))
            {
                ret += p - (p - r) / (mid + 1);
            }
            else
            {
                ret += p;
            }
        }
        return ret;
    }

    int check2(int mid, vector<int> &a)
    {
        int ret = 0;
        for (auto &x : a)
        {
            int p = x / (mid + 1);
            int r = x % (mid + 1);
            if (r == 0)
                ret += p;
            else
            {
                if (p < mid - r)
                    return -1;
                ret += p + 1;
            }
        }
        return ret;
    }
    int minGroupsForValidAssignment(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        int minx = INF;
        for (auto &x : nums)
        {
            cnt[x]++;
        }
        vector<int> a;
        for (auto &[key, value] : cnt)
        {
            a.emplace_back(value);
            minx = min(minx, value);
        }
        if (a.size() == 1)
            return 1;
        // 每组至少的数量
        for (int i = minx; i >= 1; --i)
        {
            int ret = check2(i, a);
            if (ret != -1)
            {
                return ret;
            }
        }
        return 1;
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
    vector<int> a = {3, 2, 3, 2, 3};
    cout << solution.minGroupsForValidAssignment(a) << endl;
    return 0;
}