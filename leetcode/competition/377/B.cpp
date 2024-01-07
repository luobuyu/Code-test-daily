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
    const int mod = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
    {
        int hsize = hFences.size();
        int vsize = vFences.size();
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_set<int> s1, s2;
        for (int i = 0; i < hsize; ++i)
        {
            s1.insert(hFences[i] - 1);
            s1.insert(m - hFences[i]);
        }
        for (int i = 0; i < hsize; ++i)
        {
            for (int j = i + 1; j < hsize; ++j)
            {
                s1.insert(hFences[j] - hFences[i]);
            }
        }
        s1.insert(m - 1);
        int ans = -1;
        for (int i = 0; i < vsize; ++i)
        {
            int len = vFences[i] - 1;
            if (s1.count(len))
                ans = max(ans, len);
            len = n - vFences[i];
            if (s1.count(len))
                ans = max(ans, len);
        }
        for (int i = 0; i < vsize; ++i)
        {
            for (int j = i + 1; j < vsize; ++j)
            {
                int len = vFences[j] - vFences[i];
                if (s1.count(len))
                {
                    ans = max(ans, len);
                }
            }
        }
        if (s1.count(n - 1))
            ans = max(ans, n - 1);
        if (ans == -1)
            return -1;
        else
            return 1ll * ans * ans % mod;
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
    vector<int> a = {2, 3}, b = {2};
    solution.maximizeSquareArea(4, 3, a, b);
    return 0;
}