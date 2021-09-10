#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 500 + 10;

char s[maxn];
int k;
char ans[maxn], top;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> (s + 1);
    cin >> k;
    int len = strlen(s + 1);
    int left = len - k;
    int cnt = 0;
    int l = k + 1;
    int start = 1;
    top = 0;
    while(cnt < left)
    {
        char minx = s[start];
        int p = start;
        for (int i = start; i < start + l; i++)
        {
            if(s[i] < minx)
            {
                minx = s[i];
                p = i;
            }
        }
        ans[++top] = minx;
        l -= p - start;
        start = p + 1;
        cnt++;
    }
    int i = 1;
    while (i <= top && ans[i] == '0')
        i++;
    if(i > top)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int j = i; j <= top; j++)
        {
            cout << ans[j];
        }
    }
    

    return 0;
}