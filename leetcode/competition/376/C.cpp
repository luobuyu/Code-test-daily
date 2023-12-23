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

vector<long long> a;
bool check(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; ++i)
    {
        int j = n - 1 - i;
        if (s[i] != s[j])
            return false;
    }
    return true;
}
auto init = []()
{
    for (int i = 1; i <= 100000; ++i)
    {
        string s1 = to_string(i);
        if (check(s1))
            a.emplace_back(i);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        string tmp = s1 + s2;
        long long num = atoll(tmp.c_str());
        if (num > 1000000000)
            break;
        a.emplace_back(num);
        for (int j = 0; j < 10; ++j)
        {
            string tmp = s1 + (char)('0' + j) + s2;
            long long num = atoll(tmp.c_str());
            if (num > 1000000000)
                break;
            a.emplace_back(num);
        }
    }
    sort(a.begin(), a.end());
    cout << a.size() << endl;
    cout << a.back() << endl;
    return 0;
}();
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;

    long long minimumCost(vector<int> &nums)
    {
        long long sum = 0;
        int n = nums.size();
        if (n == 1)
            return 0;
        sort(nums.begin(), nums.end());
        vector<long long> preSum(n + 1);
        for (int i = 1; i <= n; ++i)
            preSum[i] = preSum[i - 1] + nums[i - 1];
        sum = preSum[n];

        long long ans = LLONG_MAX;
        // sumj - sumi + numi x - numj x
        //
        int index = lower_bound(a.begin(), a.end(), nums[0]) - a.begin() - 1;
        if (index >= 0)
        {
            ans = min(ans, preSum[n] - n * a[index]);
        }
        for (int i = 0; i < n; ++i)
        {
            // [0, i]  [i + 1, n - 1]
            int numi = i + 1;
            int numj = n - 1 - i;
            if (numi < numj)
            {
                // x 越大越好，找比 nums[i + 1] 小的。
                int index = lower_bound(a.begin(), a.end(), nums[i + 1]) - a.begin() - 1;
                if (index <= 0 || a[index] < nums[i])
                    continue;
                long long x = a[index];
                ans = min(ans, preSum[n] - preSum[i + 1] - preSum[i + 1] + numi * x - numj * x);
            }
            else
            {
                // x 越小越好，找大于等于 nums[i] 的
                int index = lower_bound(a.begin(), a.end(), nums[i]) - a.begin();
                if (index >= a.size())
                    continue;
                long long x = a[index];
                if (i + 1 == n)
                    ans = min(ans, -sum + numi * x);
                else if (a[index] >= nums[i + 1])
                    continue;
                else
                    ans = min(ans, preSum[n] - preSum[i + 1] - preSum[i + 1] + numi * x - numj * x);
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
    vector<int> a = {1000000000, 1000000000, 1000000000};
    cout << solution.minimumCost(a) << endl;
    return 0;
}