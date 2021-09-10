#include <bits/stdc++.h>

using namespace std;
using number = long double;
const number eps = 1e-7;
number n, p1, v1, p2, v2;
int main()
{
    int tcase;
    scanf("%d", &tcase);
    constexpr int left = 0, right = 1;
    constexpr int A = 0, B = 1;
    number s[2][2];
    cout << fixed << setprecision(10);
    const auto check = [&](number time) {
        number p[] = {p1, p2}, v[] = {v1, v2};
        number ll[2][2], rr[2][2];
        for (int x = 0; x < 2; ++x)
            for (int dir = 0; dir < 2; ++dir)
            {
                number dx = v[x] * time;
                if (dx < s[x][dir] + eps)
                    if (dir == left)
                        rr[x][dir] = p[x], ll[x][dir] = p[x] - dx;
                    else
                        ll[x][dir] = p[x], rr[x][dir] = p[x] + dx;
                else if (dx <= 2 * s[x][dir] + eps)
                    if (dir == left)
                        ll[x][dir] = 0, rr[x][dir] = p[x];
                    else
                        ll[x][dir] = p[x], rr[x][dir] = n;
                else if (dir == left)
                    ll[x][dir] = 0, rr[x][dir] = dx - s[x][dir];
                else
                    rr[x][dir] = n, ll[x][dir] = n - dx + s[x][dir];
            }
        for (int aDir = 0; aDir < 2; ++aDir)
            for (int bDir = 0; bDir < 2; ++bDir)
            {
                auto L = make_pair(ll[A][aDir], rr[A][aDir]),
                     R = make_pair(ll[B][bDir], rr[B][bDir]);
                if (L > R)
                    swap(L, R);
                if (L.second < R.first + eps)
                    continue;
                if (L.first <= 0 && R.second >= n)
                    return true;
            }
        return false;
    };
    while (tcase--)
    {
        scanf("%llf %llf %llf %llf %llf", &n, &p1, &v1, &p2, &v2);
        if (p1 > p2)
        {
            swap(p1, p2);
            swap(v1, v2);
        }
        number v[] = {v1, v2};
        s[A][left] = p1, s[B][left] = p2;
        s[A][right] = n - p1, s[B][right] = n - p2;
        cerr << fixed << setprecision(10);
        cerr << check(5001000) << endl;
        // 1.相对2
        //10000.0 1.0 0.001 9999.0 0.001
        //4306.063 4079.874 0.607 1033.423 0.847
        number l = 0, r = 1e9;
        number ans = 0;
        while (l <= r - eps)
        {
            number mid = (l + r) / 2;
            if (check(mid))
            {
                ans = mid;
                r = mid;
            }
            else
                l = mid;
        }
        cout << ans << endl;
    }
    return 0;
}
