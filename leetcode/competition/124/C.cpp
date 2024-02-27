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
    const static int maxn = 2e1 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    bool vis[maxn][maxn];
    struct Node
    {
        int l, r;
        int cnt;
    };
    int solve(vector<int> &nums, int start, int end, int sum)
    {
        int ans = 1;
        int len = end - start + 1;
        queue<Node> q;
        q.push({start, end, 1});
        memset(vis, 0, sizeof(vis));
        if (end < 0 || start < 0)
            return ans;
        vis[start][end] = 1;
        while (q.size())
        {
            auto out = q.front();
            ans = max(ans, out.cnt);
            q.pop();
            int l = out.l, r = out.r, cnt = out.cnt;
            if (r - l + 1 < 2)
                continue;
            if (nums[l] + nums[l + 1] == sum && !vis[l + 2][r])
            {
                q.push({l + 2, r, cnt + 1});
                vis[l + 2][r] = 1;
            }
            if (nums[r] + nums[r - 1] == sum && r - 2 >= 0 && !vis[l][r - 2])
            {
                q.push({l, r - 2, cnt + 1});
                vis[l][r - 2] = 1;
            }
            if (nums[l] + nums[r] == sum && r - 1 >= 0 && !vis[l + 1][r - 1])
            {
                q.push({l + 1, r - 1, cnt + 1});
                vis[l + 1][r - 1] = 1;
            }
            // ans++;
        }
        return ans;
    }
    int maxOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ret1 = solve(nums, 2, n - 1, nums[0] + nums[1]);
        int ret2 = solve(nums, 1, n - 2, nums[0] + nums[n - 1]);
        int ret3 = solve(nums, 0, n - 3, nums[n - 1] + nums[n - 2]);
        return max(ret1, max(ret2, ret3));
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
    vector<int> a = {1, 2, 1, 2, 1, 2, 1, 2};
    cout << solution.maxOperations(a) << endl;
    return 0;
}