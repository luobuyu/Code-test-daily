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
const int maxn = 2e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
long long a[maxn];
vector<long long> nums;
void sieve(long long x)
{
    for (long long i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            nums.emplace_back(i);
        }
        while (x % i == 0)
        {
            x /= i;
        }
    }
    if (x != 1)
        nums.emplace_back(x);
}

bool check(long long x, long long sum)
{
    long long newsum = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] & 1)
        {
            // 奇数， x
            newsum += x;
        }
        else
        {
            newsum += 2ll * x;
        }
    }
    return newsum <= sum;
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
    long long sum = 0;
    bool hasJi = false;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] & 1)
            hasJi = true;
        sum += a[i];
    }

    if (hasJi == false)
    {
        cout << "YES" << endl;
        cout << 2 << endl;
    }
    else
    {
        sieve(sum);
        sort(nums.begin(), nums.end());
        vector<long long> ans;
        for (auto &x : nums)
        {
            if (x % 2 == 0)
                continue;
            if (check(x, sum))
            {
                ans.emplace_back(x);
            }
        }
        if (ans.size() == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < ans.size(); ++i)
            {
                cout << ans[i] << (" \n"[i == ans.size() - 1]);
            }
        }
    }

    return 0;
}