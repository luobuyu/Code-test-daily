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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        unordered_map<int, int> mp;
        char aa[10] = "aeiou";
        int tmp = 0;
        int ans = 0;
        mp[0] = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (s[i] == aa[j])
                {
                    tmp ^= (1 << (s[i] - 'a'));
                    break;
                }
            }
            if (mp.count(tmp))
            {
                ans = max(ans, i - mp[tmp] + 1);
            }
            else
            {
                mp[tmp] = i + 1; // 注意这里是加一
            }
        }
        return ans;
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

    Solution ss;
    string s;
    while (cin >> s)
    {

        int ans = ss.findTheLongestSubstring(s);
        cout << ans << endl;
    }

    return 0;
}