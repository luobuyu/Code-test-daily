// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
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

int init = []
{
    /*********** fast_read ***************/
    freopen("in.txt", "r", stdin);
    freopen("user.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    /*************************************/
    const static int maxn = 1e5;
    int n;
    int dist[maxn], speed[maxn];
    int cnt[maxn];
    while (true)
    {
        if (!getline())
            break;
        for (n = 0; !endofl(); ++n)
            read(dist[n]);
        memset(cnt, 0, sizeof(cnt));
        getline();
        for (int i = 0; !endofl(); ++i)
            read(speed[i]);
        for (int i = 0; i < n; ++i)
        {
            dist[i] = ((dist[i] - 1) / speed[i] + 1);
            if (dist[i] > n)
                continue;
            cnt[dist[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            cout << cnt[i] << endl;
        }
        int sum = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            sum += cnt[i];
            // cout << i << ", " << sum << endl;
            if (sum > i)
            {
                flag = false;
                break;
            }
            ans = sum;
        }
        if (flag)
            cout << n << endl;
        else
            cout << ans << endl;
    }
    exit(0);
    return 0;
}();

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
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; ++i)
        {
            time[i] = ((dist[i] - 1) / speed[i] + 1);
        }
        sort(time.begin(), time.end());
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (time[i] - i > 0)
                ans++;
            else
                break;
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
    // vector<int> a = {1, 1, 2, 3}, b = {1, 1, 1, 1};
    // cout << solution.eliminateMaximum(a, b) << endl;
    return 0;
}