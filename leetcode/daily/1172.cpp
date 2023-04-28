// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
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
int t, n, m, k;
auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class DinnerPlates
{
private:
    vector<vector<int>> plates;
    set<int> not_full;
    int max_size;

public:
    DinnerPlates(int capacity)
    {
        max_size = capacity;
    }

    void push(int val)
    {
        if (not_full.empty())
        {
            vector<int> tmp;
            tmp.emplace_back(val);
            plates.emplace_back(tmp);
            if (tmp.size() < max_size)
                not_full.insert(plates.size() - 1);
        }
        else
        {
            auto it = not_full.begin();
            plates[*it].emplace_back(val);
            if (plates[*it].size() >= max_size)
                not_full.erase(it);
        }
    }

    int pop()
    {
        return popAtStack(plates.size() - 1);
    }

    int popAtStack(int index)
    {
        if (index < 0 || index >= plates.size() || plates[index].size() == 0)
            return -1;
        int val = plates[index].back();
        if (plates[index].size() == max_size)
            not_full.insert(index);
        plates[index].pop_back();
        while (plates.size() && plates.back().empty())
        {
            not_full.erase(plates.size() - 1);
            plates.pop_back();
        }
        return val;
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
    DinnerPlates solution(2);
    solution.push(1);
    solution.push(2);
    solution.push(3);
    solution.push(4);
    solution.push(5);
    solution.popAtStack(0);
    solution.push(20);
    solution.push(21);
    solution.popAtStack(0);
    solution.popAtStack(2);
    solution.pop();
    solution.pop();
    solution.pop();
    solution.pop();
    solution.pop();
    return 0;
}