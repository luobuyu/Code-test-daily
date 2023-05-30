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
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    vector<int> tmp;
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        tmp.resize(k);
        int n = mat.size(), m = mat[0].size();
        vector<int> cur = mat[0];
        for (int i = 1; i < n; ++i)
        {
            merge(cur, mat[i], k);
        }
        return cur[k - 1];
    }

    void merge(vector<int> &a, vector<int> &b, int k)
    {
        int l = a[0] + b[0];
        int r = a.back() + b.back();
        int ans = 0;
        if (k < a.size() * b.size())
        {
            while (l <= r)
            {
                int mid = l + (r - l >> 1);
                int cnt = 0, rp = b.size() - 1;
                for (int lp = 0; lp < a.size(); ++lp)
                {
                    while (rp >= 0 && b[rp] + a[lp] > mid)
                        --rp;
                    cnt += rp + 1;
                }
                if (cnt >= k)
                {
                    ans = mid;
                    r = mid - 1;
                }
                else if (cnt < k)
                    l = mid + 1;
            }
            int cnt = 0;
            for (int i = 0; i < a.size(); ++i)
            {
                for (int j = 0; j < b.size(); ++j)
                {
                    if (a[i] + b[j] > ans)
                        break;
                    tmp[cnt++] = a[i] + b[j];
                    if (cnt >= k)
                        break;
                }
                if (cnt >= k)
                    break;
            }
            sort(tmp.begin(), tmp.begin() + k);
            a.resize(k);
            for (int i = 0; i < k; ++i)
            {
                a[i] = tmp[i];
            }
        }
        else
        {
            int size = a.size() * b.size();
            int cnt = 0;
            for (int i = 0; i < a.size(); ++i)
            {
                for (int j = 0; j < b.size(); ++j)
                {
                    tmp[cnt++] = a[i] + b[j];
                }
            }
            sort(tmp.begin(), tmp.begin() + cnt);
            a.resize(cnt);
            for (int i = 0; i < cnt; ++i)
            {
                a[i] = tmp[i];
            }
        }
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
    vector<vector<int>> a = {{1, 10, 10}, {1, 4, 5}, {2, 3, 6}};
    solution.kthSmallest(a, 14);

    return 0;
}