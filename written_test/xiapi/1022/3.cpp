#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     *
     * true 表示类型相同，false表示不相同
     * @param input_a string字符串
     * @param input_b string字符串
     * @return bool布尔型
     */
    bool CheckPatern(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        if(m != n)
            return false;
        vector<char> keys1, keys2;
        map<char, vector<int>> mp1, mp2;
        for(int i = 0; i < n; ++i) {
            if(!mp1.count(s[i]))
                keys1.emplace_back(s[i]);
            if(!mp2.count(t[i]))
                keys2.emplace_back(t[i]);
            mp1[s[i]].emplace_back(i);
            mp2[t[i]].emplace_back(i);
        }
        sort(keys1.begin(), keys1.end());
        sort(keys2.begin(), keys2.end());
        if(keys1.size() != keys2.size()) {
            return false;
        }
        for(int i = 0; i < keys1.size(); ++i) {
            char ch1 = keys1[i];
            char ch2 = keys2[i];
            auto &v1 = mp1[ch1];
            auto &v2 = mp2[ch2];
            if(v1.size() != v2.size()) {
                return false;
            }
            for(int j = 0; j < v1.size(); ++j) {
                if(v1[j] != v2[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string a = "ab";
    string b = "ce";
    cout << solution.CheckPatern(a, b) << endl;
    return 0;
}