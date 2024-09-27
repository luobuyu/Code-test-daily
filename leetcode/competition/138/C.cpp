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
    unordered_set<string> mp;
    long long countGoodIntegers(int n, int k)
    {
        int len = n / 2;
        long long num = 0;
        int upper = pow(10, len);
        vector<long long> jc(11);
        jc[0] = 1;
        for (int i = 1; i <= 10; ++i)
        {
            jc[i] = jc[i - 1] * i;
        }
        cout << pow(10, len - 1) << ", " << upper << endl;
        for (int i = pow(10, len - 1); i < upper; ++i)
        {
            string tmp;
            if (i != 0)
                tmp = to_string(i);

            reverse(tmp.begin(), tmp.end());
            if (n & 1)
            {
                for (int j = 0; j < 10; ++j)
                {
                    string cur = tmp;
                    cur.push_back('0' + j);
                    cur += tmp;
                    long long cur_num = atoi(cur.c_str());
                    if (cur_num % k != 0 || to_string(cur_num).length() != n)
                        continue;
                    // cout << cur_num << endl;
                    if (cur_num == 0)
                        continue;
                    sort(cur.begin(), cur.end());
                    mp.insert(cur);
                }
            }
            else
            {
                string cur = tmp;
                cur += tmp;
                long long cur_num = atoi(cur.c_str());
                if (cur_num % k != 0 || to_string(cur_num).length() != n)
                    continue;
                if (cur_num == 0)
                    continue;
                sort(cur.begin(), cur.end());
                mp.insert(cur);
            }
        }
        cout << mp.size() << endl;
        long long ans = 0;
        for (auto &s : mp)
        {
            // cout << s << endl;
            vector<int> cnt(10);
            int len = s.length();
            if (len == 1)
            {
                ans++;
                continue;
            }
            for (auto &ch : s)
            {
                cnt[ch - '0']++;
            }
            long long tmp = (len - cnt[0]) * (len - 1);
            for (int i = 0; i < 10; ++i)
            {
                tmp /= jc[cnt[i]];
            }
            ans += tmp;
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
    solution.countGoodIntegers(2, 1);
    return 0;
}