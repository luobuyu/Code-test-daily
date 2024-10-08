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
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        vector<int> pos0;
        vector<int> presum1(n + 1);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
                pos0.emplace_back(i + 1);
            presum1[i + 1] = presum1[i] + (s[i] == '1');
        }
        pos0.emplace_back(n + 1);
        int left = 0;
        // "101101"
        for (int i = 1; i <= n; ++i)
        {
            if(s[i - 1] == '1') {
                ans += pos0[left] - i;
            }
            for (int j = left; j < pos0.size() - 1; ++j) {
                int cnt0 = j - left + 1;
                // 右端点 pos[j + 1] - 1, 左端点 i, len = pos[j + 1] - 1 - i + 1, cnt1 = len - cnt0;
                int cnt1 = pos0[j + 1] - 1 - i + 1 - cnt0;
                // pos0[k] 前面有多少个 1
                int precnt1 = pos0[j] - i + 1 - (j - left + 1);

                // 剩余 1 的数量，presum[n] - presum[i - 1]
                int left1 = presum1[n] - presum1[i - 1];
                if(cnt0 * cnt0 > left1) break;
                if (cnt1 >= cnt0 * cnt0)
                {
                    ans += max(cnt1 - precnt1 - max(cnt0 * cnt0 - precnt1, 0) + 1, 0);
                }
            }
            if(s[i - 1] == '0')
                left++;
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
    cout << solution.numberOfSubstrings("00011") << endl;
    // cout << solution.numberOfSubstrings("101101") << endl;
    return 0;
}