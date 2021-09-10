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
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
string a, b;

bool findxun(string x, string &y)
{
    int len = x.length();
    for (int i = 1; i <= len; i++)
    {
        bool flag = true;
        if (len % i == 0)
        {
            for (int j = i; j <= len - i; j += i)
            {
                if (x.substr(0, i) != x.substr(j, i))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                y = x.substr(0, i);
                return true;
            }
        }
    }
    return false;
}

int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int tcase;
    read(tcase);
    while (tcase--)
    {
        cin >> a >> b;
        string asub, bsub;
        if (findxun(a, asub) && findxun(b, bsub))
        {
            if (asub == bsub)
            {
                int lena = a.length() / asub.length();
                int lenb = b.length() / bsub.length();
                for (int i = 1; i <= lena * lenb / __gcd(lena, lenb); i++)
                {
                    cout << asub;
                }
                cout << endl;
            }
            else
            {
                printf("-1\n");
            }
        }
        else
            printf("-1\n");
    }
    return 0;
}