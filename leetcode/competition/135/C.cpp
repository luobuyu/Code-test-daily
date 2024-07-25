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
    unordered_map<int, int> mm;
    int tot = 1;
    int getVal(int x)
    {
        if (!mm.count(x))
            mm[x] = tot++;
        return mm[x];
    }
    int minChanges(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp; // diff, cnt;
        int max_cnt = 0, aim = -1;
        int maxx = 0, minx = k;
        vector<pair<int, int>> q;
        for (int i = 0, j = n - 1; i < j; ++i, --j)
        {
            int tmp = abs(nums[i] - nums[j]);
            mp[tmp]++;
            if (mp[tmp] > max_cnt)
            {
                max_cnt = mp[tmp];
                aim = tmp;
            }
            q.emplace_back(max(nums[i], nums[j]), k - min(nums[i], nums[j]));
        }
        sort(q.begin(), q.end());
        int ans = INF;

        vector<int> xx;
        for (auto &x : q)
        {
            xx.emplace_back(x.first);
            xx.emplace_back(x.second);
        }
        for (auto &[key, val] : mp)
        {
            xx.emplace_back(key);
        }
        sort(xx.begin(), xx.end());
        for (auto &x : xx)
        {
            getVal(x);
        }
        for (auto &x : q)
        {
            x.first = getVal(x.first);
            x.second = getVal(x.second);
        }
        vector<vector<int>> dp;
        dp.resize(tot, vector<int>(tot));
        for (auto &x : q)
        {
            dp[x.first][x.second] = 1;
        }
        for (int i = 1; i < tot; ++i)
        {
            for (int j = 1; j < tot; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + dp[i][j];
            }
        }
        for (auto &[key, val] : mp)
        {
            pair<int, int> cur = {key, key};
            int tmp = getVal(key);
            int cnt = dp[tmp - 1][tmp - 1];
            ans = min(ans, (cnt) * 2 + (n / 2 - cnt) - val);
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
    vector<int> a = {7, 0, 3, 7, 3, 10, 2, 11, 7, 8, 7, 5};
    cout << solution.minChanges(a, 14) << endl;
    return 0;
}