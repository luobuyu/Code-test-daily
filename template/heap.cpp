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

// 默认大顶堆
template <class T, class Container = vector<T>, class Cmp = less<T>>
class Heap
{
private:
    Container elements;
    Cmp cmp; // 仿函数使用时必须要先创建对象

private:
    int getFa(int i) { return (i - 1) >> 1; }
    int getLc(int i) { return (i << 1) + 1; }
    int getRc(int i) { return (i + 1) << 1; }
    void adjustUp(int cur)
    {
        int fa;
        while (cur > 0)
        {
            fa = getFa(cur);
            if (cmp(elements[cur], elements[fa]))
                break;
            swap(elements[fa], elements[cur]);
            cur = fa;
        }
    }
    void adjustDown(int cur)
    {
        int bigIndex;
        while ((bigIndex = getLc(cur)) < size())
        {
            if (bigIndex + 1 < size() && cmp(elements[bigIndex], elements[bigIndex + 1]))
                ++bigIndex;
            // 大顶堆
            if (cmp(elements[bigIndex], elements[cur]))
                break;
            swap(elements[cur], elements[bigIndex]);
            cur = bigIndex;
        }
    }

public:
    Heap() {}
    template <class InputIterator>
    Heap(InputIterator first, InputIterator last)
    {
        while (first != last)
        {
            elements.push_back(*first);
            ++first;
        }
        for (int i = size() - 1; i >= 0; --i)
            adjustDown(i);
    }

    void push(const T &x)
    {
        elements.push_back(x);
        adjustUp(size() - 1);
    }
    void pop()
    {
        swap(elements[0], elements[size() - 1]);
        elements.pop_back();
        adjustDown(0);
    }

    const T &top() const
    {
        return elements[0];
    }

    bool empty() { return elements.empty(); }

    // 函数名后加 const，不能修改成员变量
    int size() const { return elements.size(); }
};
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int minSubarray(vector<int> &nums, int p)
    {
        priority_queue<int> q;
        q.size();
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
    Solution solution;
    Heap<int, vector<int>, greater<int>> heap;
    vector<int> a;
    for (int i = 0; i < 10; ++i)
        heap.push(i);
    while (heap.size())
    {
        cout << heap.top() << ", ";
        heap.pop();
    }
    cout << endl;
    return 0;
}