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

const int N = 1e5 + 5;
typedef long long LL;
const int p = 10007;
int tot, num;
int n, m, r, t, cases = 0;

int w[N] = {}, a[N] = {}, sum1[N * 4] = {}, sum2[N * 4] = {};
int sum3[N * 4] = {}, lazy_mul[N * 4] = {}, lazy_add[N * 4] = {}; // w[i]=j表示时间戳为i的点的值为j，a[]输入每个节点的值，dat线段树每个点权值，lazy线段树每个点的懒标记
vector<int> mp[N];

void solve(int rt, int len, int a, int b)
{ // a为add b为mul
    lazy_mul[rt] = 1ll * lazy_mul[rt] * b % p;
    lazy_add[rt] = 1ll * lazy_add[rt] * b % p;
    lazy_add[rt] = ((lazy_add[rt] + a) % p + p) % p;
    if (b != 1)
    { // 先乘后加
        sum1[rt] = 1ll * sum1[rt] * b % p;
        sum2[rt] = (1ll * sum2[rt] * b % p) * b % p;
        sum3[rt] = ((1ll * sum3[rt] * b % p) * b % p) * b % p;
    }
    if (a != 0)
    {
        int a2 = 1ll * a * a % p, a3 = 1ll * a2 * a % p;
        sum3[rt] = ((sum3[rt] + (LL)len * a3 % p) + p) % p;
        sum3[rt] = ((sum3[rt] + 3ll * (LL)sum2[rt] % p * a % p) + p) % p;
        sum3[rt] = ((sum3[rt] + 3ll * (LL)sum1[rt] % p * a2 % p) + p) % p;
        sum2[rt] = ((sum2[rt] + 2ll * (LL)sum1[rt] % p * a % p) + p) % p;
        sum2[rt] = ((sum2[rt] + (LL)len * a2 % p) + p) % p;
        sum1[rt] = ((sum1[rt] + (LL)len * a % p) + p) % p;
    }
}

void pushup(int rt)
{
    sum1[rt] = (sum1[rt << 1] + sum1[rt << 1 | 1]) % p;
    sum2[rt] = (sum2[rt << 1] + sum2[rt << 1 | 1]) % p;
    sum3[rt] = (sum3[rt << 1] + sum3[rt << 1 | 1]) % p;
}

// 建线段树，rt为根，l为rt点管辖的左边界， r为rt点管辖的有边界
void build(int rt, int l, int r)
{
    lazy_add[rt] = 0;
    lazy_mul[rt] = 1;
    if (l == r)
    {
        int temp = a[l];
        sum1[rt] = temp;
        sum2[rt] = (1ll * sum1[rt] * sum1[rt]) % p;
        sum3[rt] = (1ll * sum1[rt] * sum2[rt]) % p;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

// 下传
void pushdown(int rt, int l, int r)
{
    int mid = (l + r) >> 1;
    solve(rt << 1, mid - l + 1, lazy_add[rt], lazy_mul[rt]);
    solve(rt << 1 | 1, r - mid, lazy_add[rt], lazy_mul[rt]);
    lazy_add[rt] = 0;
    lazy_mul[rt] = 1;
}

// rt为根，l为rt点管辖的左边界， r为rt点管辖的有边界， L为需要修改的左区间，R为需要修改的右区间
void modify(int rt, int l, int r, int L, int R, int a, int b)
{
    if (L <= l && r <= R)
    {
        solve(rt, r - l + 1, a, b);
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid)
        modify(rt << 1, l, mid, L, R, a, b);
    if (mid < R)
        modify(rt << 1 | 1, mid + 1, r, L, R, a, b);
    pushup(rt);
}

// rt为根，l为rt点管辖的左边界， r为rt点管辖的有边界， L为需要查询的左区间，R为查询的右区间,k代表查询的是k次方和
int query(int rt, int l, int r, int L, int R, int k)
{
    if (L <= l && r <= R)
    {
        if (k == 1)
            return sum1[rt];
        if (k == 2)
            return sum2[rt];
        if (k == 3)
            return sum3[rt];
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    int ans = 0;
    if (L <= mid)
        ans += query(rt << 1, l, mid, L, R, k), ans %= p;
    if (mid < R)
        ans += query(rt << 1 | 1, mid + 1, r, L, R, k), ans %= p;
    pushup(rt);
    return ans;
}
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const static long long mod = 1e9 + 7;
    const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
    const int INF = 0x3f3f3f3f;
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 1; i <= n; ++i)
            a[i] = 1;
        build(1, 1, n);

        for (int i = 0; i < m; ++i)
        {
            if (queries[i][0] + 1 != queries[i][1])
            {
                modify(1, 1, n, queries[i][0] + 1 + 1, queries[i][1] + 1 - 1, 0, 0);
            }
            ans[i] = query(1, 1, n, 1, n, 1) - 1;
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

    return 0;
}