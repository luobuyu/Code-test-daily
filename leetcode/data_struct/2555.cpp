// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll long long
#define PII pair<int, int>
namespace FAST_IO
{
    static string buf_line;
    static int _i;
    static int _n;
    static char _ch;
    template <class T>
    inline bool read(T &x)
    {
        T flag = 1;
        x = 0;
        if (_i >= _n)
            return false;
        _ch = buf_line[_i++];
        while (_ch < '0' || _ch > '9')
        {
            if (_ch == '-')
                flag = -1;
            _ch = buf_line[_i++];
        }
        while (_ch >= '0' && _ch <= '9')
        {
            x = (x << 3) + (x << 1) + (_ch ^ 48), _ch = buf_line[_i++];
        }
        x *= flag;
        return true;
    }

    template <class T, class... _T>
    inline bool read(T &x, _T &...y)
    {
        return read(x), read(y...);
    }

    inline bool getline()
    {
        if (!getline(cin, buf_line))
            return false;
        _i = 0, _n = buf_line.length();
        return true;
    }
    template <class T>
    inline void show(T *a, int n)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            cout << a[i];
        }
        cout << "]";
    }

    bool endofl()
    {
        if (_i >= _n)
            return true;
        if (_i == 0)
            return false;
        if (buf_line[_i - 1] == ']')
        {
            _i++;
            return true;
        }
        return false;
    }

    template <class T, std::size_t Num>
    inline void show(T a[][Num], int n, int m)
    {
        cout << "[";
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                cout << ",";
            show(a[i], m);
        }
        cout << "]";
    }

} // namespace FAST_IO
using namespace FAST_IO;

// int init = []
// {
//     /*********** fast_read ***************/
//     freopen("user.out", "w", stdout);
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     /*************************************/

//     while (true)
//     {
//         if (!getline())
//             break;

//         getline();
//     }
//     exit(0);
//     return 0;
// }();

auto optimize_cpp_stdio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution
{
public:
    const static int maxn = 1e5 + 10;
    const static int maxm = 1e5 + 10;
    const int INF = 0x3f3f3f3f;
    int maximizeWin(vector<int> &prizePositions, int k)
    {
        // 枚举第二条线段的左端点
        // 先用滑动窗口预处理出，每个点左侧最多能覆盖多少个点
        int n = prizePositions.size();
        vector<int> left(n);
        int l = 0, r;
        for (int r = 0; r < n; ++r)
        {
            while (prizePositions[r] - prizePositions[l] > k)
                ++l;
            left[r] = r - l + 1;
            if (r >= 1)
                left[r] = max(left[r], left[r - 1]);
        }
        // 枚举第二条线段左端点
        r = l = 1;
        int ans = 0;
        for (r = 1; r < n; ++r)
        {
            while (prizePositions[r] - prizePositions[l] > k)
                ++l;
            ans = max(ans, left[l - 1] + r - l + 1);
        }
        return ans;
    }
};

int t, n, m, k;
int main()
{
// #define COMP_DATA
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution solution;
    vector<int> a = {3937, 3938, 3939, 3951, 3951, 3959, 3975, 3988, 3993, 4010, 4031, 4033, 4036, 4038, 4039, 4041, 4047, 4058, 4059, 4064, 4072, 4081, 4084, 4084, 4089, 4094, 4098, 4112, 4114, 4116, 4123, 4123, 4127, 4130, 4135, 4143, 4149, 4152, 4163, 4164, 4176, 4178, 4180, 4198, 4216, 4224, 4233, 4240, 4253, 4259, 4273, 4286, 4305, 4322, 4335, 4350, 4364, 4378, 4396, 4397, 4398, 4404, 4415, 4421, 4430, 4469, 4476, 4490, 4492, 4497, 4504, 4519, 4519, 4525, 4526, 4530, 4530, 4540, 4550, 4554, 4563, 4571, 4571, 4595, 4595, 4606, 4639, 4639, 4660, 4663, 4676, 4678, 4680, 4695, 4697, 4709, 4709, 4711, 4724, 4751, 4781, 4786, 4786, 4794, 4797, 4801, 4807, 4808, 4817, 4822, 4824, 4825, 4840, 4851, 4887, 4889, 4891, 4910, 4917, 4927, 4931, 4932, 4951, 4959, 4964, 4993, 4997, 5003, 5003, 5006, 5006, 5022, 5029, 5035, 5043, 5045, 5045, 5046, 5059, 5060, 5079, 5084, 5105, 5109, 5109, 5112, 5120, 5126, 5130, 5142, 5143, 5151, 5152, 5154, 5156, 5168, 5189, 5213, 5214, 5223, 5226, 5235, 5247, 5259, 5272, 5289, 5303, 5309, 5317, 5322, 5344, 5347, 5352, 5374, 5379, 5380, 5383, 5385, 5391, 5418, 5425, 5429, 5432, 5479, 5486, 5490, 5502, 5502, 5505, 5506, 5509, 5515, 5518, 5519, 5521, 5526, 5528, 5533, 5536, 5536, 5538, 5555, 5556, 5557, 5557, 5566, 5571, 5580, 5585, 5596, 5604, 5619, 5634, 5649, 5668, 5694, 5696, 5699, 5701, 5704, 5709, 5732, 5745, 5745, 5746, 5749, 5762, 5766, 5766, 5770, 5773, 5796, 5810, 5817, 5823, 5838, 5843, 5846, 5860, 5869, 5872, 5877, 5880, 5896, 5899, 5902, 5905, 5910, 5913, 5913, 5915, 5923};
    solution.maximizeWin(a, 220);
    return 0;
}