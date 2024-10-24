// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define PII pair<int, int>
using namespace std;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> a;
    int x;
    int target;
    string s;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> x)
    {
        a.emplace_back(x);
    }
    cin >> target;
    sort(a.begin(), a.end());
    int l = 0, r = a.size() - 1;
    cout << "S";
    bool find = false;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] == target)
        {
            find = true;
            break;
        }
        else if (a[mid] > target)
        {
            cout << "L";
            r = mid - 1;
        }
        else
        {
            cout << "R";
            l = mid + 1;
        }
    }
    if (find)
        cout << "Y" << endl;
    else
        cout << "N" << endl;
    return 0;
}