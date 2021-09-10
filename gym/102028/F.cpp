#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <vector>
#include <queue>
#include <cassert>
#include <cstring>

using namespace std;

using longs = long long;

#define $peek "cin.peek = " << '\'' << (char)cin.peek() << "\' (" << cin.peek() << ")"

const int N = 1e7 + 5, M = 10060;
char line[M];

namespace FWS
{
    struct edge
    {
        int u, v, next;
        edge() = default;
        edge(int u, int v, int next) : u(u), v(v), next(next) {}
    };

    int head[N], tot;
    edge ee[N * 24];

    void init(int n)
    {
        memset(head, -1, sizeof(int) * (n + 1));
        tot = 0;
    }

    void addEdge(int u, int v)
    {
        ee[tot] = edge(u, v, head[u]);
        head[u] = tot++;
    }

    template <class fun>
    void forEach(int u, const fun recurrence)
    {
        for (auto c = head[u];
             c != -1;
             c = ee[c].next)
            if (recurrence(ee[c]))
                continue;
            else
                break;
    }
} // namespace FWS

struct Node
{
    int u;
    //int flag;
};
int fg[N][2];
queue<Node> que[2];
int ans;

int duoBfs(int s, int t, int lim)
{
    for (int i = 1; i <= lim; ++i)
        fg[i][0] = fg[i][1] = 0;
    while (!que[0].empty())
        que[0].pop();
    while (!que[1].empty())
        que[1].pop();
    que[0].push({s});
    que[1].push({t});
    fg[s][0] = 1;
    fg[t][1] = 1;
    while (!que[0].empty() && !que[1].empty())
    {
        auto out = que[0].front();
        que[0].pop();
        using namespace FWS;
        for (auto c = head[out.u];
             c != -1;
             c = ee[c].next)
        {
            const auto &e = ee[c];
            int v = e.v;
            if (fg[v][0])
                continue; // continue
            if (fg[v][1]) // return
            {
                return ans = fg[out.u][0] + fg[v][1];
            }
            fg[v][0] = fg[out.u][0] + 1;
            que[0].push({v});
        }
        out = que[1].front();
        que[1].pop();
        for (auto c = head[out.u];
             c != -1;
             c = ee[c].next)
        {
            const auto &e = ee[c];
            int v = e.v;
            if (fg[v][1])
                continue; // continue
            if (fg[v][0]) // return
            {
                return ans = fg[out.u][1] + fg[v][0];
            }
            fg[v][1] = fg[out.u][1] + 1;
            que[1].push({v});
        }
    }
    return ans = -1;
}

//#define LOG_INPUT_DEBUG
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T, r, c, n, m, lim, s, t;
    const auto parseCore = [&](int row, int col) {
        if (row < 1 || col < 1 || row > n || col > m)
            return 0;
        row = (row + 1) / 4, col = (col + 4) / 6;
        return row * c + col - c;
    };
    const auto parseSlash = [&](int row, int col) {
        bool a = (row / 2) % 2, b = ((col + 4) / 6) % 2;
        if (!(a ^ b))
            return make_pair(
                parseCore(row - 1, col - 3),
                parseCore(row + 1, col + 3));
        else
            return make_pair(
                parseCore(row + 1, col - 3),
                parseCore(row - 1, col + 3));
    };
    const auto evenLine = [&](int row, int lim) {
        for (int i = 2; i <= lim; i += 6)
        {
            if (line[i] == ' ')
            {
                auto [a, b] = parseSlash(row, i);
                if (!a || !b || a > lim || b > lim)
                    continue;
                FWS::addEdge(a, b), FWS::addEdge(b, a);
            }
        }
    };
    const auto oddLine = [&](int row, int lim) {
        int sign = (row + 1) / 2 % 2;
        for (int i = 5, j = 1; i <= lim; i += 6, j = !j)
            if (j != sign)
                if (line[i] == 'S')
                    s = parseCore(row, i);
                else if (line[i] == 'T')
                    t = parseCore(row, i);
                else
                    continue;
            else if (line[i] == '-')
                continue;
            else
            {
                int a = parseCore(row - 2, i),
                    b = parseCore(row + 2, i);
                if (!a || !b || a > lim || b > lim)
                    continue;
                FWS::addEdge(a, b), FWS::addEdge(b, a);
            }
    };
    cin >> T;
    while (T--)
    {
        cin >> r >> c;
        n = 4 * r + 3, m = 6 * c + 3;
        lim = r * c;
        FWS::init(lim);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 1; i <= n; ++i)
        {
            cin.getline(&line[1], m + 1, '\n');
#ifdef LOG_INPUT_DEBUG
            cerr << (line + 1) << " | " << $peek << endl;
#endif
            const auto siz = strlen(line + 1);
            if (i % 2)
                oddLine(i, siz);
            else
                evenLine(i, siz);
        }
#ifdef LOG_INPUT_DEBUG
        cerr << "S = " << s << ", T = " << t << endl;
        assert(FWS::tot % 2 == 0);
        for (int i = 0; i < FWS::tot; i += 2)
            cerr << "Edge:: " << FWS::ee[i].u
                 << "<----->" << FWS::ee[i].v << endl;
        cerr << "Total " << FWS::tot / 2 << " edges" << endl;
#endif
        auto ret = duoBfs(s, t, lim);
        cout << ret << endl;
    }
    return 0;
}