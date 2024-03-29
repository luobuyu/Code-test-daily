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
        T vis = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                vis = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= vis;
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
const int maxn = 1e1 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
bool vis[4];
double a[4];
int sum;

// int s1[5];
// int top1 = -1;
// char op[5];
// int optop = -1;
// int s2[5];
// int top2 = -1;
// int pro[5];
// int protop = -1;

// bool dfs1(int step)
// {

//     if (step == 3)
//     {
//         bool v = false;
//         for (int i = 0; i < 4 && vis[i] == false; i++)
//         {
//             if (a[i] == 24)
//             {
//                 v = true;
//             }
//         }

//         if (v)
//         {
//             int start = 0;
//             while (start <= top1)
//             {
//                 cout << s1[start] << op[start] << s2[start] << '=' << pro[start] << endl;
//                 start++;
//             }
//             exit(0);
//         }
//         return v;
//     }
//     else
//     {
//         int maxe, mine, x;
//         for (int i = 0; i < 4; i++)
//         {
//             if (vis[i] == false)
//             {
//                 for (int j = i + 1; j < 4; j++)
//                 {
//                     if (vis[j] == false)
//                     {
//                         x = a[i];
//                         vis[j] = true;
//                         maxe = max(a[i], a[j]);
//                         mine = min(a[i], a[j]);
//                         a[i] = maxe - mine;
//                         s1[++top1] = maxe;
//                         s2[++top2] = mine;
//                         op[++optop] = '-';
//                         pro[++protop] = a[i];
//                         // vis[i] = false;
//                         if (dfs1(step + 1))
//                         {
//                             return true;
//                         }
//                         top1--;
//                         top2--;
//                         optop--;
//                         protop--;

//                         a[i] = maxe + mine;
//                         // vis[i] = false;
//                         s1[++top1] = maxe;
//                         s2[++top2] = mine;
//                         op[++optop] = '+';
//                         pro[++protop] = a[i];

//                         if (dfs1(step + 1))
//                         {
//                             return true;
//                         }

//                         top1--;
//                         top2--;
//                         optop--;
//                         protop--;

//                         a[i] = maxe * mine;
//                         // vis[i] = false;
//                         s1[++top1] = maxe;
//                         s2[++top2] = mine;
//                         op[++optop] = '*';
//                         pro[++protop] = a[i];
//                         // vis[i] = false;
//                         if (dfs1(step + 1))
//                         {
//                             return true;
//                         }

//                         if (mine != 0 && maxe % mine == 0)
//                         {

//                             top1--;
//                             top2--;
//                             optop--;
//                             protop--;

//                             a[i] = maxe / mine;
//                             // vis[i] = false;
//                             s1[++top1] = maxe;
//                             s2[++top2] = mine;
//                             op[++optop] = '/';
//                             pro[++protop] = a[i];

//                             // vis[i] = false;
//                             if (dfs1(step + 1))
//                             {
//                                 return true;
//                             }
//                         }

//                         a[i] = x;
//                         vis[j] = false;
//                         top1--;
//                         top2--;
//                         optop--;
//                         protop--;
//                     }
//                 }
//             }
//         }
//     }
//     return false;
// }
set<string> ans;
template <typename T>
struct st
{
    T a[5];
    int top = -1;
    void push(T x)
    {
        a[++top] = x;
    }
    int size(){return top + 1};
    T &operator[](int x) { return a[x]; }
};

st<char> op;
st<double> s1, s2, result;
st<string> result_string;
bool vis[4];
int get_op_level(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
}
int sgn(double x)
{
    if (fabs(x) < eps)
        return 0;
    return x < -1 ? -1 : 1;
}
double get_result(double nums1, double nums2, int op)
{
    if (op == 0)
        return nums1 + nums2;
    else if (op == 1)
        return nums1 - nums2;
    else if (op == 2)
        return nums1 * nums2;
    else
        return nums1 / nums2;
}
void dfs(int step)
{
    if (step == 3)
    {
        // 三次运算之后就得到了结果
        bool find = false;
        for (int i = 0; i < 4; ++i)
        {
            if (!vis[i] && fabs(a[i] - 24) < eps)
            {
                find = true;
                break;
            }
        }
        if (find)
        {
            string s;
            // 全加上小括号
            double pre_result;
            for (int i = 0; i < op.size(); ++i)
            {
            }
        }
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (vis[i])
            continue;
        for (int j = 1; j < 4; ++j)
        {
            if (vis[j])
                continue;
            double op_num1 = a[i];
            double op_num2 = a[j];
            for (int is_swap = 0; is_swap < 2; ++is_swap)
            {
                if (is_swap)
                    swap(op_num1, op_num2);
                for (int k = 0; k < 4; ++k)
                {
                    // 首先 nums1 op nums2
                    if (k == 3 && fabs(op_num2) < eps)
                        continue;
                    if (k == 2 && sgn(op_num1 - op_num2) == -1)
                        continue;
                    int tmp = a[i]; // 方便恢复现场
                    int res = get_result(op_num1, op_num2, k);
                }
            }
        }
    }
}
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 4; ++i)
    {
        read(a[i]);
    }
    string cur;

    return 0;
}