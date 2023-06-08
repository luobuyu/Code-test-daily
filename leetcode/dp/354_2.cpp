// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
int t, n, m, k;
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
    vector<int> pre;
    vector<pair<int, int>> dp; // 高度，下标
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        auto old = envelopes;
        int len = 1, n = envelopes.size();
        pre.resize(n, -1);
        dp.resize(n + 1, {0, 0});
        sort(envelopes.begin(), envelopes.end(), [&](const vector<int> &x, const vector<int> &y)
             { if(x[0] != y[0]) return x[0] < y[0];
             else return x[1] > y[1]; });
        dp[0] = {envelopes[0][1], 0};
        for (int i = 1; i < n; ++i)
        {
            if (envelopes[i][1] > dp[len - 1].first)
            {
                pre[i] = dp[len - 1].second;
                dp[len++] = {envelopes[i][1], i};
            }
            else
            {
                int index = lower_bound(dp.begin(), dp.begin() + len, make_pair(envelopes[i][1], i),
                                        [&](const pair<int, int> &x, const pair<int, int> &y)
                                        {
                                            return x.first < y.first;
                                        }) -
                            dp.begin();
                pre[i] = pre[dp[index].second];
                dp[index] = {envelopes[i][1], i};
            }
        }
        vector<int> ans;
        int tmp = dp[len - 1].second;
        while (tmp != -1)
        {
            ans.push_back(tmp);
            tmp = pre[tmp];
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < len; ++i)
        {
            cout << envelopes[ans[i]][0] << ", " << envelopes[ans[i]][1] << endl;
        }
        return len;
    }
};

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<vector<int>> a = {{4, 5},
                             {4, 6},
                             {6, 7},
                             {2, 3},
                             {1, 1},
                             {1, 1}};
    solution.maxEnvelopes(a);
    return 0;
}