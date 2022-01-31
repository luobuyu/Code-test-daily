#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<int> x(n), y(n);

    int ret = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first >> v[i].second;
        x[i] = v[i].first;
        y[i] = v[i].second;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for (int i = 0; i < n; ++i)
    {
        // 如果不是边界上的就跳过
        int cx = v[i].first, cy = v[i].second;
        int width = 40000, height = 40000;

        if (cx == x[0])
            width = x[n - 1] - x[1];
        else if (cx == x[n - 1])
            width = x[n - 2] - x[0];
        else
            width = x[n - 1] - x[0];

        if (cy == y[0])
            height = y[n - 1] - y[1];
        else if (cy == y[n - 1])
            height = y[n - 2] - y[0];
        else
            height = y[n - 1] - y[0];

        ret = min(ret, width * height);
    }

    cout << ret << endl;

    return 0;
}
