#include <bits/stdc++.h>

using namespace std;
int n, m, q, k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    double a, b;
    double x, y;
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
            if (a <= 0 || b <= 0 || b > a)
            {
                cout << "error" << endl;
                return 0;
            }
            sum1 += a;
            sum2 += b;
    }
    cin >> x >> y;
    if (x <= 0 || y <= 0)
    {
        cout << "error" << endl;
        return 0;
    }
    if(sum1 >= x)
        sum1 -= y;
    printf("%.2f\n", min(sum1, sum2));

    return 0;
}