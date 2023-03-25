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
const int maxn = 1e6 + 10;
const int maxm = 7e1 + 10;
int t, n, m, k;
struct ACTrie
{
    const static int M = 26;
    const static int maxn = 1e2 + 10;
    int next[maxn][M] = {}, fail[maxn] = {}, cnt = 0;
    int exist[maxn] = {};
    int id[maxn]; // 以u结尾的字符串对应的输入id
    int times[maxn] = {};
    queue<int> q;

    void init()
    {
        for (int i = 0; i < maxn; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                next[i][j] = 0;
            }
            fail[i] = 0;
            exist[i] = 0;
            id[i] = -1;
            times[i] = 0;
        }
        cnt = 0;
    }
    void insert(char *s, int index)
    {
        int now = 0, len = strlen(s);
        for (int i = 0; i < len; ++i)
        {
            int c = s[i] - 'a';
            if (!next[now][c])
                next[now][c] = ++cnt;
            now = next[now][c];
        }
        exist[now]++;
        id[now] = index;
    }

    void build()
    {

        for (int i = 0; i < M; ++i)
        {
            if (next[0][i])
            {
                fail[next[0][i]] = 0;
                q.push(next[0][i]);
            }
        }
        while (q.size())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < M; ++i)
            {
                if (next[u][i])
                {
                    fail[next[u][i]] = next[fail[u]][i];
                    q.push(next[u][i]);
                }
                else
                    next[u][i] = next[fail[u]][i];
            }
        }
    }

    int query(char *s)
    {
        int now = 0, len = strlen(s), ans = 0;
        for (int i = 0; i < len; ++i)
        {
            int c = s[i] - 'a';
            now = next[now][c];
            for (int j = now; j; j = fail[j])
            {
                if (id[j] != -1)
                {
                    times[id[j]]++;
                    ans = max(ans, times[id[j]]);
                }
            }
        }
        return ans;
    }
};
char a[maxn][maxm];
char s[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    ACTrie trie;
    while (cin >> n && n)
    {
        trie.init();
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            trie.insert(a[i], i);
        }
        cin >> s;
        trie.build();
        int ans = trie.query(s);
        cout << ans << endl;
        for (int i = 0; i < n; ++i)
        {
            if (trie.times[i] == ans)
            {
                cout << a[i] << endl;
            }
        }
    }
    return 0;
}