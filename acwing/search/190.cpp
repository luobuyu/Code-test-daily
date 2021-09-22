#include <bits/stdc++.h>
#define ll long long
#define lll long long
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
const int maxn = 1e2 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;

string s, e;
string a[2][maxn];
int ans;
queue<string> qa, qb;

// 注意需要开两个，写个函数比较好
unordered_map<string, int> disa, disb; // 先 count
int search(queue<string> &q, unordered_map<string, int> &disa, unordered_map<string, int> &disb, string a[], string b[])
{
    int d = disa[q.front()];
    while (q.size() && disa[q.front()] == d)
    {
        string u = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            string t = a[i];
            for (int j = 0; j < u.size(); j++)
            {
                if (u.substr(j, t.size()) == t)
                {
                    string v = u.substr(0, j) + b[i] + u.substr(j + t.size());
                    if (disb.count(v))
                        return disa[u] + disb[v] + 1;
                    if (disa.count(v))
                        continue;
                    q.push(v);
                    disa[v] = disa[u] + 1;
                }
            }
        }
    }
    return 11;
}
int bfs()
{
    if (s == e)
        return 0;
    qa.push(s);
    qb.push(e);
    disa[s] = 0;
    disb[e] = 0;
    int step = 0;
    while (qa.size() && qb.size())
    {
        step++;
        int t;
        if (qa.size() < qb.size())
        {
            // 扩展比较短的
            t = search(qa, disa, disb, a[0], a[1]);
        }
        else
        {
            t = search(qb, disb, disa, a[1], a[0]);
        }
        if (t <= 10)
            return t;
        if (step >= 10)
            return -1;
    }
    return -1;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    cin >> s >> e;
    string x, y;
    n = 0;
    while (cin >> x >> y)
    {
        a[0][n] = x;
        a[1][n++] = y;
    }
    int t = bfs();
    if (t == -1)
        cout << "NO ANSWER!" << endl;
    else
        cout << t << endl;

    return 0;
}