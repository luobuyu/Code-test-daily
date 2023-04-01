#include <bits/stdc++.h>
#define ll long long
namespace FAST_IO
{
    template<class T> inline void read(T&x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
        }
        x *= flag;
    }

    template<class T, class ..._T> inline void read(T&x, _T &...y)
    {
        return read(x), read(y...);
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eqs = 1e-5;
const int maxn = 1e3 + 10;
const int maxm = 1e5 + 10;
int t, n, m, k;
string a, b;
map<string, bool> mp;
vector<string> ans;
int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;

    for(int i = 0; i < b.length(); i++)
    {
        for(int j = 0; j < a.length(); j++)
        {
            string tmp = b; tmp[i] = a[j];
            if(b[i] != a[j] && !mp[tmp])
            {
                ans.push_back(tmp);
                mp[tmp] = 1;
            }
        }
    }

    for(int i = 0; i < b.length(); i++)
    {
        string tmp = b.substr(0, i);
        for(int j = i+1; j < b.length(); ++j)
            tmp.push_back(b[j]);
        if(!mp[tmp])
        {
            ans.push_back(tmp);
            mp[tmp] = 1;
        }
    }

    for(int i = 0; i <= b.length(); i++)
    {
        for(int j = 0; j < a.length(); j++)
        {
            string tmp = b.substr(0, i);
            tmp.push_back(a[j]);
            if(i < b.length()) tmp += b.substr(i, b.size()-i);
            if(!mp[tmp])
            {
                ans.push_back(tmp);
                mp[tmp] = 1;
            }
        }
    }

    sort(ans.begin(), ans.end());
    for(auto& i : ans) printf("%s\n", i.c_str());

    return 0;
}