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
int a[maxn][2];
int p[maxn];
struct node
{
   int tt;
   int bb;
};

#define DEBUG
#ifdef DEBUG
#define eprintf(x) fprintf(stderr, x)
#define eputs(str) fputs(str, stderr), fputc('\n', stderr)
#define var(x) "" #x " = " << x
#define watch(...) trace(#__VA_ARGS__, __VA_ARGS__)
#else
#define eprintf(...)
#define eputs(...)
#define watch(...)
#endif

template <class printable>
void trace(const char *name, printable &&value)
{
   cerr << name << " = " << value << endl;
}
template <class printable, class... args>
void trace(const char *names, printable &&value, args &&...list)
{
   const char *separate = strchr(names + 1, ',');
   cerr.write(names, separate - names) << " = " << value << ',';
   trace(separate + 1, list...);
}

struct Node
{
   vector<vector<int>> a;
   Node() : a(10, vector<int>(0)) {}
};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   ios::sync_with_stdio(false);
   cin.tie(0);
   vector<int> a(100);
   cout << a.capacity() << " " << a.size() << endl;
   vector<int> b;
   b.reserve(100);
   cout << b.capacity() << " " << b.size() << endl;
   b[99] = 100;
   cout << b[99] << endl;
   return 0;
}