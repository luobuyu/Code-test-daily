#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 500 + 10;

char stk[maxn], top = 0;
char s[maxn];
int n, m, k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%s", s + 1);
    scanf("%d", &k);
    n = strlen(s + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top!=0 && s[i] < stk[top] && cnt < k)
            top--, cnt++;
        stk[++top] = s[i];
    }

    // cnt < k
    while(cnt < k) 
    {
        top--, cnt++;
    }
    stk[++top] = '\0';
    int start = 1;
    while(stk[start]=='0')
        start++;
    if(start == top)
    {
        printf("0\n");
    }
    else
    {
        printf("%s\n", stk + start);
    }
    
    

    return 0;
}