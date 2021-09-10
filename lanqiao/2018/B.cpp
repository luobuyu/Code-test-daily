#include<iostream>
#include<cstdio>

using namespace std;
bool check(int x)
{
    if(((x % 4 == 0) && (x % 100 != 0) )|| (x % 400 == 0))
    {
        return 1;
    }
    return 0;
}
int main()
{
    int ans = 0;
    for(int i = 1901; i <= 2000; i++)
    {
        ans += 365 + check(i);
    }
    cout << ans / 7 << endl;
    return 0;
}