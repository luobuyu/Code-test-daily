#include <bits/stdc++.h>
#include <string>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn];
string ss;
string s;
string s1, s2;
int index1 = 0, index2 = 0;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    getline(cin, ss);
    for (int i = 0; i < ss.length(); ++i)
    {
        if (ss[i] == ' ')
            continue;
        else
        {
            s.push_back(ss[i]);
        }
    }
    int index = -1;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ']')
        {
            index = i;
            break;
        }
    }
    s1 = s.substr(0, index + 1);
    s2 = s.substr(index + 1);
    bool isNeedRead1 = true, isNeedRead2 = true;
    long long tmp1 = 0, tmp2 = 0;
    cout << "[";
    bool first = true;
    while (index1 < s1.length() && index2 < s2.length())
    {
        if (isNeedRead1 && index1 < s1.length() && (s1[index1] == '[' || s1[index1] == ']' || s1[index1] == ','))
        {
            ++index1;
            continue;
        }
        if (isNeedRead2 && index2 < s2.length() && (s2[index2] == '[' || s2[index2] == ']' || s2[index2] == ','))
        {
            ++index2;
            continue;
        }
        if (isNeedRead1)
        {
            tmp1 = 0;
            while (index1 < s1.length() && s1[index1] >= '0' && s1[index1] <= '9')
            {
                tmp1 = tmp1 * 10 + s1[index1] - '0';
                ++index1;
            }
        }
        if (isNeedRead2)
        {
            tmp2 = 0;
            while (index2 < s2.length() && s2[index2] >= '0' && s2[index2] <= '9')
            {
                tmp2 = tmp2 * 10 + s2[index2] - '0';
                ++index2;
            }
        }
        if (tmp1 < tmp2)
        {
            if (!first)
            {
                cout << ",";
            }
            cout << tmp1;
            first = false;
            isNeedRead1 = true;
            isNeedRead2 = false;
        }
        else
        {
            if (!first)
            {
                cout << ",";
            }
            cout << tmp2;
            first = false;
            isNeedRead1 = false;
            isNeedRead2 = true;
        }
    }

    if (!isNeedRead1)
    {
        if (!first)
        {
            cout << ",";
        }
        cout << tmp1;
        first = false;
    }
    if (!isNeedRead2)
    {
        if (!first)
        {
            cout << ",";
        }
        cout << tmp2;
        first = false;
    }
    while (index1 < s1.length())
    {
        if (index1 < s1.length() && (s1[index1] == '[' || s1[index1] == ']' ||
                                     s1[index1] == ','))
        {
            ++index1;
            continue;
        }

        tmp1 = 0;
        while (index1 < s1.length() && s1[index1] >= '0' && s1[index1] <= '9')
        {
            tmp1 = tmp1 * 10 + s1[index1] - '0';
            ++index1;
        }
        if (!first)
        {
            cout << ",";
        }
        cout << tmp1;
        first = false;
    }
    // cout << "index2: " << s2[index2] << ":::::" << endl;
    while (index2 < s2.length())
    {
        if (index2 < s2.length() && (s2[index2] == '[' || s2[index2] == ']' ||
                                     s2[index2] == ','))
        {
            ++index2;
            continue;
        }
        tmp2 = 0;
        while (index2 < s2.length() && s2[index2] >= '0' && s2[index2] <= '9')
        {
            tmp2 = tmp2 * 10 + s2[index2] - '0';
            ++index2;
        }
        if (!first)
        {
            cout << ",";
        }
        cout << tmp2;
        first = false;
    }
    cout << "]";
    atomic_bool a;
    return 0;
}
// 64 位输出请用 printf("%lld")