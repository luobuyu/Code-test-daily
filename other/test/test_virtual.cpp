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

void quick_sort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int pivot = a[l];
    int i = l + 1, j = r;
    while (i < j)
    {
        while (i < j && a[j] >= pivot)
            --j;
        while (i < j && a[i] <= pivot)
            ++i;
        if (i != j)
            swap(a[i], a[j]);
    }
    swap(a[l], a[i]);
    quick_sort(a, l, i - 1);
    quick_sort(a, i + 1, r);
}

void quick_sort2(int a[], int l, int r)
{
    if (l >= r)
        return;
    int i = l, cur = l + 1, j = r;
    int pivot = a[l];
    // [l, i - 1], i, [j + 1, r]
    while (cur <= j)
    {
        if (a[cur] <= pivot)
        {
            swap(a[i], a[cur]);
            ++i, ++cur;
        }
        else
        {
            // a[cur] > pivot;
            swap(a[cur], a[j]);
            --j;
        }
    }
    quick_sort2(a, l, i - 1);
    quick_sort2(a, j + 1, r);
}

void quick_sort3(int a[], int l, int r)
{
    if (l >= r)
        return;
    int i = l, cur = l + 1, j = r;
    int pivot = a[l];
    // [l, i - 1], [i, j], [j + 1, r]
    while (cur <= j)
    {
        if (a[cur] < pivot)
        {
            swap(a[i], a[cur]);
            ++i, ++cur;
        }
        else if (a[cur] > pivot)
        {
            // a[cur] > pivot;
            swap(a[cur], a[j]);
            --j;
        }
        else
        {
            ++cur;
        }
    }
    quick_sort3(a, l, i - 1);
    quick_sort3(a, j + 1, r);
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[] = {23, 234, 1, 4, 87, 12, 867, 1, 67, 28};
    quick_sort2(a, 0, 9);
    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << ", ";
    }
    cout << endl;
    return 0;
}