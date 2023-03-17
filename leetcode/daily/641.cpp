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

class MyCircularDeque
{
public:
    int a[1010];
    int size;
    int head, tail;
    // head 指向第一个元素，tail指向队尾下一个位置
    MyCircularDeque(int k)
    {
        size = k + 1;
        head = tail = 0;
    }

    int getIndex(int x)
    {
        return (x + size) % size;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        head = getIndex(head - 1);
        a[head] = value;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        a[tail] = value;
        tail = getIndex(head + 1);
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        head = getIndex(head + 1);
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        tail = getIndex(tail - 1);
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return a[head];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return a[getIndex(tail - 1)];
    }

    bool isEmpty()
    {
        return head == tail;
    }

    bool isFull()
    {
        return head == getIndex(tail + 1);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tcase;
    read(tcase);
    while (tcase--)
    {
    }
    return 0;
}