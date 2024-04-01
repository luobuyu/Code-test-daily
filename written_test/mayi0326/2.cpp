#include <bits/stdc++.h>

using namespace std;
int n, m, k, q;
const int maxn = 2e5 + 10;
unordered_map<int, int> mp;
pair<int, int> pos[maxn];
vector<int> nums;
int cnt = 0;

int newArr[maxn];
int getHash(int x)
{
    if(!mp.count(x))
        mp[x] = ++cnt;
    return mp[x];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 1, x, y; i <= n; ++i)
    {
        cin >> x >> y;
        pos[i] = {x, y};
        nums.emplace_back(x);
        nums.emplace_back(y);
    }
    sort(nums.begin(), nums.end());
    for(auto& x: nums)
        getHash(x);
    for (int i = 1; i <= n; ++i)
    {
        pos[i].first = getHash(pos[i].first);
        pos[i].second = getHash(pos[i].second);
        newArr[pos[i].first]++;
        newArr[pos[i].second + 1]--;
    }
    for (int i = 1; i <= cnt; ++i)
    {
        newArr[i] += newArr[i - 1];
    }
    string ans;
    for (int i = 1; i <= n; ++i)
    {
        int sum1 = newArr[pos[i].first - 1];
        int sum2 = newArr[pos[i].second + 1];
        if(sum1 == sum2) {
            ans.push_back('1');
        }else {
            ans.push_back('0');
        }
    }
    cout << ans << endl;

    return 0;
}