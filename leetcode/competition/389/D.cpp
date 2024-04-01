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
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    long long minimumMoves(vector<int> &nums, int k, int maxChanges)
    {
        int n = nums.size();
        vector<int> pos;
        int cc = 0;
        for (int i = 0; i < n; ++i)
        {
            int tmp = 0;
            if (nums[i] == 1)
            {
                pos.emplace_back(i);
                for (int j = i; j < min(i + 3, n); ++j)
                {
                    if (nums[j] != 1)
                        break;
                    ++tmp;
                }
            }

            cc = max(cc, tmp);
        }
        cout << cc << endl;
        if (cc >= k)
            return cc - 1;
        if (maxChanges - cc >= k)
            return cc + (k - cc) * 2;
        vector<long long> preSum(pos.size() + 1);
        for (int i = 1; i < preSum.size(); ++i)
            preSum[i] = preSum[i - 1] + pos[i - 1];
        k -= maxChanges;
        long long ans = INF_LL;
        for (int left = 0; left + k - 1 < pos.size(); ++left)
        {
            long long tmp = maxChanges * 2;
            int right = left + k - 1;
            int index = (left + right) / 2;
            int pp = pos[index];
            tmp += 1ll * (index - left) * pp - (preSum[index - 1 + 1] - preSum[left - 1 + 1]) + (preSum[right + 1] - preSum[index + 1]) - 1ll * pp * (right - index);
            ans = min(ans, tmp);
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
    vector<int> a{0, 1};
    solution.minimumMoves(a, 2, 5);
    return 0;
}