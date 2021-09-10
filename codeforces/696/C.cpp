#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &... y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e6 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int a[maxn];
int cnt[maxn];
vector<pair<int, int>> ans;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    int x;
    while (tcase--)
    {
        read(n);
        for (int i = 1; i <= 2 * n; i++)
        {
            read(a[i]);
        }
        sort(a + 1, a + 1 + n + n);
        bool flag = false;
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            for (int j = 1; j <= 2 * n; j++)
            {
                cnt[a[j]]++;
            }
            ans.clear();
            int index = 2 * n;
            x = a[i] + a[index];
            // 找到最大的
            while (true)
            {
                while (index >= 1 && cnt[a[index]] == 0)
                    index--;
                if (index == 0)
                {
                    flag = true;
                    break;
                }
                cnt[a[index]]--, cnt[x - a[index]]--;
                if (cnt[a[index]] < 0 || cnt[x - a[index]] < 0)
                {
                    cnt[a[index]] = 0;
                    cnt[x - a[index]] = 0;
                    break;
                }
                ans.push_back({a[index], x - a[index]});
                x = max(a[index], x - a[index]);
            }
            if (flag)
                break;
            for (int j = 1; j <= 2 * n; j++)
            {
                cnt[a[j]] = 0;
            }
        }

        if (flag)
        {
            printf("YES\n");
            printf("%d\n", ans[0].first + ans[0].second);
            for (auto item : ans)
            {
                printf("%d %d\n", item.first, item.second);
            }
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}