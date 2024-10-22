#include <bits/stdc++.h>

using namespace std;

void solve(string& s)
{
    int n = s.length();
    int i = 0;
    while(i < n)
    {
        if(s[i] != '(') {
            ++i;
            continue;
        }
        int start = i + 1;
        while(start < n && s[start - 1] == '(' && s[start] == ')') {
            start += 2;
        }
        int end1 = start - 2;
        int len_left = end1 - i + 1; // [i, j - 1]
        if (len_left <= 2) {
            i = start;
            continue;
        }

        start = end1 + 1;
        int len1 = 0;
        while(start < n && s[start] == '(') {
            ++len1;
            ++start;
        }
        int len0 = 0;
        while(start < n && s[start] == ')') {
            ++len0;
            ++start;
        }
        // [i, j - 1]  [len1] [len0]
        if (len1 > len0 || len_left < len1 * 2)
        {
            i = end1 + len1 - 1;  // 需要回退到 ((( 末尾
            continue;
        }
        else {
            // len1 <= len0, len_left >= len1 + len0;
            int len = len1 * 2;
            string sub1 = s.substr(i, len);
            string sub2 = s.substr(end1 + 1, len);
            s.replace(i, len, sub2.c_str());
            s.replace(end1 + 1, len, sub1.c_str());
            i = start;
            continue;
        }
    }
}

int main() {
    string s1 = "((()()()()()((()()()((()))))))";
    solve(s1);
    cout << s1 << endl;
    return 0;
}