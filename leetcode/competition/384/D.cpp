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
    const static int maxn = 1e6 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    int Next[maxn];
    void getNext(vector<int> &s)
    {
        int n = s.size();
        Next[0] = -1;
        for (int t = -1, i = 0; i < n; Next[++i] = ++t)
        {
            for (; ~t && s[i] != s[t]; t = Next[t])
                ;
        }
    }
    int kmp(vector<int> &s, vector<int> &substr)
    {
        int i = 0, j = 0;
        int ans = 0;
        int len1 = s.size(), len2 = substr.size();
        while (i < len1)
        {
            if (j == -1 || s[i] == substr[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = Next[j];
            }
            if (j == len2)
            {
                ans++;
                --i;
                --j;
                j = Next[j];
            }
        }
        return ans;
    }
    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
    {
        vector<int> num1;
        int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            int tmp = nums[i] - nums[i - 1];
            if (tmp == 0)
                num1.push_back(0);
            else if (tmp > 0)
                num1.push_back(1);
            else
                num1.push_back(-1);
        }
        getNext(pattern);
        return kmp(num1, pattern);
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
    vector<int> a = {1, 4, 4, 1, 3, 5, 5, 3};
    vector<int> b = {1, 0, -1};
    solution.countMatchingSubarrays(a, b);
    return 0;
}