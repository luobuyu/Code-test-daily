// #pragma GCC optimize(2)
#include <bits/stdc++.h>
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
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
vector<int> popcount_num[32];
int getGx(int x)
{
    string bits;
    int tmp = x;
    while (tmp)
    {
        if (tmp & 1)
            bits.push_back('1');
        else
            bits.push_back('0');
        tmp >>= 1;
    }
    bits.push_back('0');
    // reverse(bits.begin(), bits.end());
    int index1 = bits.find_first_of('1');
    int index0 = find(bits.begin() + index1, bits.end(), '0') - bits.begin();
    for (int i = index1; i < index0; ++i)
    {
        bits[i] = '0';
    }
    for (int i = 0; i < index0 - index1 - 1; ++i)
    {
        bits[i] = '1';
    }
    bits[index0] = '1';
    int ans = 0;
    int size = bits.size();
    for (int i = size - 1; i >= 0; --i)
    {
        ans = (ans << 1) + bits[i] - '0';
    }
    // cout << x << ", " << ans << endl;
    return ans;
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        int cnt = __builtin_popcount(a[i]);
        popcount_num[cnt].emplace_back(a[i]);
    }
    int ans = 1;
    for (int cnt_i = 0; cnt_i < 32; ++cnt_i)
    {
        auto &nums = popcount_num[cnt_i];
        unordered_set<int> uset;
        unordered_set<int> vis;
        for (auto &x : nums)
            uset.insert(x);
        for (auto &x : nums)
        {
            if (vis.count(x))
                continue;
            int gx = getGx(x);
            int cnt = 1;
            while (uset.count(gx))
            {
                gx = getGx(gx);
                cnt++;
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << endl;
    return 0;
}