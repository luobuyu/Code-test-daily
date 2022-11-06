// #include <iostream>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// const int N = 100010, M = 1000010;
// char p[N], s[M];
// int Next[N];
// int n, m;
// void buildNext()
// {
//     int j = 0;
//     int t = Next[0] = -1;
//     while (j < n)
//     {
//         if (t < 0 || p[j] == p[t])
//             Next[++j] = ++t;
//         else
//             t = Next[t];
//     }
// }

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
// #endif
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     scanf("%d%s", &n, p);
//     scanf("%d%s", &m, s);
//     buildNext();
//     //    for(int i=0;i<n;i++)printf("%d ",Next[i]);
//     int i = 0, j = 0;
//     while (i < m)
//     {
//         while (i < m && j < n)
//         {
//             if (j < 0 || s[i] == p[j])
//             {
//                 i++;
//                 j++;
//             }
//             else
//                 j = Next[j];
//         }
//         if (j == n)
//         {
//             printf("%d ", i - j);
//             i = i - j + 1;
//             j = 0;
//         }
//     }
//     return 0;
// }

#include <iostream>

using namespace std;

const int N = 10010, M = 100010;

int n, m;
int ne[N];
char s[M], p[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> p + 1 >> m >> s + 1;

    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i++)
    {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }

    return 0;
}
