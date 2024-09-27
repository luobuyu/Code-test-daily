#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const long long INF_LL = 0x3f3f3f3f3f3f3f3f;
int n, m, q, k;

struct PairHash
{
    template<class T, class U>
    size_t operator()(const pair<T, U>& p) const {
        return hash<T>()(p.first) ^ hash<U>()(p.second);
    }
};
unordered_map<string, string> mp; // 店名，主店
unordered_set<pair<string, string>, PairHash> s;
unordered_map<string, int> cnt; // 店名，数量
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    vector<string> allname;
    string name, address;
    for (int i = 1; i <= n; ++i)
    {
        cin >> name >> address;
        bool flag = true;
        for(auto& ch: name)
        {
            if(isupper(ch)) 
            {
                flag = false;
                break;
            }
        }
        if(!flag) continue;
        for(auto& ch: address)
        {
            if (isupper(ch))
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            continue;
        if(s.count({name, address})) continue;
        if(!mp.count(name))
        {
            mp[name] = address;
            cnt[name] = 0;
            allname.emplace_back(name);
            s.insert({name, address});
        }
        else
        {
            if(mp[name] != address)
            {
                cnt[name]++;
                s.insert({name, address});
            }
        }
    }
    sort(allname.begin(), allname.end());
    for(auto& nn: allname)
    {
        cout << nn << " " << mp[nn] << " " << cnt[nn] << endl;
    }
    return 0;
}