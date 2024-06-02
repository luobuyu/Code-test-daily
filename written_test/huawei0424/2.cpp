// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
struct Node
{
    int id;
    int cnt1;         // 进球数量。
    int cnt2;         // 连续进球数量
    vector<int> lost; // 丢球vector;
    bool operator<(const Node &p)
    {
        if (cnt1 == p.cnt1)
        {
            if (cnt2 == p.cnt2)
            {
                bool flag = false; // 是否可以比较出来
                for (int i = 0, j = 0; i < lost.size() && j < p.lost.size(); ++i, ++j)
                {
                    if (lost[i] != p.lost[j])
                    {
                        return lost[i] > p.lost[j];
                    }
                }
                return id < p.id;
            }
            else
            {
                return cnt2 > p.cnt2;
            }
        }
        else
        {
            return cnt1 > p.cnt1;
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
    cin >> n >> m;
    string s;
    vector<Node> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        auto &cur = a[i];
        cur.id = i + 1;
        for (int j = 0; j < m; ++j)
        {
            if (s[j] == '0')
            {
                cur.lost.emplace_back(j);
            }
        }
        cur.cnt1 = m - cur.lost.size();
        int pre = -1;
        for (auto &lostId : cur.lost)
        {
            cur.cnt2 = max(cur.cnt2, lostId - pre - 1);
            pre = lostId;
        }
        cur.cnt2 = max(cur.cnt2, m - pre - 1);
    }
    sort(a.begin(), a.end());
    for (auto &x : a)
    {
        cout << x.id << " ";
    }
    cout << endl;
    return 0;
}