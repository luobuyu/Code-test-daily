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

vector<int> prime;
vector<bool> notPrime;
vector<int> from; // 每个数最小的质因子。
vector<int> Maxx;
void sieve(int n)
{
    notPrime.resize(n + 1);
    from.resize(n + 1);
    notPrime[0] = notPrime[1] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (!notPrime[i])
        {
            prime.emplace_back(i);
            from[i] = i;
        }
        for (int j = 0; j < prime.size() && i * prime[j] <= n; ++j)
        {
            notPrime[i * prime[j]] = true;
            from[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
    Maxx.resize(n + 1);
    Maxx[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        int tmp = i;
        // cout << i << endl;
        while (true)
        {
            if (from[tmp] == tmp)
            {
                Maxx[i] = tmp;
                break;
            }
            tmp /= from[tmp];
        }
    }
}

struct Node
{
    int x;
    bool operator<(const Node &p) const
    {
        return x - x / Maxx[x] < p.x - p.x / Maxx[p.x];
    }
};
priority_queue<Node> q;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // a[i] - a[i] / k
    sieve(1e6);
    cin >> n >> k;
    for (int i = 1, x; i <= n; ++i)
    {
        cin >> x;
        q.push({x});
    }
    int cnt = 0;
    while (cnt < k)
    {
        auto out = q.top();
        if (out.x == 1)
            break;
        q.pop();
        q.push({out.x / Maxx[out.x]});
        cnt++;
    }
    long long sum = 0;
    while (q.size())
    {
        sum += q.top().x;
        q.pop();
    }
    cout << sum << endl;
    string s;
    return 0;
}