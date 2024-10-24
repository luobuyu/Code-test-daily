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
    inline void read(T &x, _T &...y)
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

int Next[maxn];
void getNext(char *str, int l)
{
    Next[0] = -1;
    for (int t = -1, i = 0; i < l; Next[++i] = ++t)
        for (; ~t && str[i] != str[t]; t = Next[t])
            ;
}
int kmp(char *str, int l1, char *substr, int l2)
{
    int i = 0, j = 0;
    while (i < l1 && j < l2)
    {
        if (j == -1 || str[i] == substr[j])
            i++, j++;
        else
            j = Next[j];
        if (j == l2)
        {
            printf("%d\n", i - j + 1);
            i--;
            j--;
            j = Next[j];
        }
    }

    return -1;
}
char s1[maxn], s2[maxn];
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%s", s1 + 1);
    scanf("%s", s2 + 1);
    int l1 = strlen(s1 + 1);
    int l2 = strlen(s2 + 1);
    int tmp1 = 0;
    getNext(s2 + 1, l2);
    kmp(s1 + 1, l1, s2 + 1, l2);

    for (int i = 0; i <= l2; i++)
    {
        printf("%d%c", Next[i], " \n"[i == l2]);
    }
    return 0;
}