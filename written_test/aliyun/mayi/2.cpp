/**
 *
 * 小红一开始有一个空串，每次操作可以在这个串的末尾添加
任意一个字符，另外最多有一次操作，可以复制当前字符事
本身，然后粘贴到末尾。现在小红想知道，最少经过多少次
操作，可以得到目标字符串
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int dp[maxn][2]; // dp[i][0] 不用粘贴，dp[i][1] 用了粘贴。
int solve(string& target)
{
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = 0;
    int n = target.length();
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0] + 1;
        dp[i][1] = dp[i - 1][1] + 1;
        // i 也是长度, 偶数
        if(i % 2 != 0) continue;
        int len = i / 2;
        if(target.substr(0, len) == target.substr(len, len)) {
            dp[i][1] = min(dp[i][1], dp[len][0] + 1);
        }
    }
    return min(dp[n][0], dp[n][1]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}