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
    unordered_map<string, int> hashmp;
    int size = 0;
    int hash(string &s)
    {
        if (!hashmp.count(s))
        {
            hashmp[s] = size++;
        }
        return hashmp[s];
    }
    int get_hash(string &s)
    {
        if (!hashmp.count(s))
            return -1;
        return hashmp[s];
    }
    long long minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost)
    {
        int original_size = original.size();
        int max_s = -1;
        for (int i = 0; i < original_size; ++i)
        {
            max_s = max(max_s, (int)original[i].length());
            hash(original[i]);
            hash(changed[i]);
        }
        vector<vector<long long>> mp(size, vector<long long>(size, INF));
        for (int i = 0; i < original_size; ++i)
        {
            max_s = max(max_s, (int)original[i].length());
            int ori = hash(original[i]);
            int dest = hash(changed[i]);
            mp[ori][dest] = min(mp[ori][dest], 1ll * cost[i]);
        }
        for (int k = 0; k < size; ++k)
        {
            for (int i = 0; i < size; ++i)
            {
                for (int j = 0; j < size; ++j)
                {
                    mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
                }
            }
        }
        int n = source.size();
        // vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, INF));
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        source = "#" + source;
        target = "#" + target;
        int pre = 0;
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            cnt = 0;
            for (int j = max(max(0, i - max_s), pre); j < i; ++j)
            {
                string ori = source.substr(j + 1, (i - j));
                string dest = target.substr(j + 1, (i - j));
                if (ori == dest)
                {
                    dp[i] = min(dp[i], dp[j]);
                    pre = max(pre, i);
                    continue;
                }
                int hash_ori = get_hash(ori);
                int hash_dest = get_hash(dest);
                if (hash_ori < 0 || hash_dest < 0)
                    continue;
                if (mp[hash_ori][hash_dest] >= INF)
                    continue;
                dp[i] = min(dp[i], dp[j] + mp[hash_ori][hash_dest]);
                pre = max(pre, j);
                if (++cnt >= 10)
                    break;
            }
        }
        return dp[n] >= INF ? -1 : dp[n];
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
    string s1 = "abcdefgh", s2 = "acdeeghh";
    vector<string> ori = {"bcd", "fgh", "thh"};
    vector<string> dest = {"cde", "thh", "ghh"};
    vector<int> cost = {1, 3, 5};
    solution.minimumCost(s1, s2, ori, dest, cost);
    return 0;
}