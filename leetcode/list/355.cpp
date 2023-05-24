// #pragma GCC optimize(2)
#include <bits/stdc++.h>
#include "head.h"
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{

    inline char nextChar()
    {
        static char buf[1000000], *p1 = buf, *p2 = buf;
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    }
#define getch getchar
    template <class T>
    inline void read(T &x)
    {
        T flag = 1;
        x = 0;
        char ch = getch();
        while (ch < '0' || ch > '9')
        {
            if (ch == '-')
                flag = -1;
            ch = getch();
        }
        while (ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch ^ 48), ch = getch();
        }
        x *= flag;
    }

    template <class T, class... _T>
    inline void read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline void print128(lll x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            print128(x / 10);
        putchar(x % 10 + '0');
    }

} // namespace FAST_IO
using namespace std;
using namespace FAST_IO;
const ll mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-5;
int t, n, m, k;
auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Tweet
{
public:
    int time;
    int tweetId;
    Tweet() {}
    Tweet(int id, int time) : tweetId(id), time(time) {}
};
class User
{
public:
    int userId;
    unordered_set<int> followee;
    list<Tweet> articles;

    User(int id) : userId(id) { followee.insert(id); }
    void postTweet(int tweetId, int time) { articles.push_front(Tweet(tweetId, time)); }
    void follow(int followeeId) { followee.insert(followeeId); }
    void unfollow(int followeeId) { followee.erase(followeeId); }
};

struct Node
{
    list<Tweet>::iterator it;
    Tweet tweet;
    int userId;
    Node(list<Tweet>::iterator p, int id)
    {
        it = p;
        tweet = *p;
        userId = id;
    }
    bool operator<(const Node &p) const { return (*it).time < (*(p.it)).time; }
};

class Twitter
{
public:
    int time;
    unordered_map<int, User *> mp; // userId, User
    Twitter()
    {
    }

    void checkUserId(int userId)
    {
        if (!mp.count(userId))
            mp[userId] = new User(userId);
    }

    void postTweet(int userId, int tweetId)
    {
        checkUserId(userId);
        mp[userId]->postTweet(tweetId, time++);
    }

    vector<int> getNewsFeed(int userId)
    {
        checkUserId(userId);
        priority_queue<Node> q;
        vector<int> ans;
        for (auto &id : mp[userId]->followee)
        {
            if (mp[id]->articles.size() == 0)
                continue;
            q.push(Node(mp[id]->articles.begin(), id));
        }
        while (q.size() && ans.size() < 10)
        {
            auto out = q.top();
            q.pop();
            ans.emplace_back(out.tweet.tweetId);
            out.it++;
            if (out.it != mp[out.userId]->articles.end())
                q.push(Node(out.it, out.userId));
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        checkUserId(followerId);
        checkUserId(followeeId);
        mp[followerId]->follow(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        checkUserId(followerId);
        checkUserId(followeeId);
        mp[followerId]->unfollow(followeeId);
    }
};
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Twitter solution;
    solution.postTweet(1, 5);
    solution.getNewsFeed(1);
    return 0;
}