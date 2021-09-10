#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int p[N], d[N];
bitset<N> vis;

int main()
{
    ios::sync_with_stdio(false);

    int t, n;
    cin >> t;
    while (t --)
    {
        cin >> n;
        memset(d, 0, sizeof d);
        for (int i = 2; i <= n; ++ i)
            cin >> p[i], ++ d[p[i]];
        p[1] = 0, d[0] = 0x3f3f3f3f;
        vis.reset();
        bool fail = false;
        for (int i = 1; i <= n; ++ i)
            if (!d[i]) 
            {
                int len = 0, x = i;
                while (d[p[x]] == 1 && x != 1) 
                    x = p[x], ++ len;
                if (len % 2) 
                {
                    fail = true;
                    break;
                }
            }
        
        cout << (!fail ? "Takeru" : "Meiya") << endl;
    }


}