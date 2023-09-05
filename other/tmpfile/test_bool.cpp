#include <bits/stdc++.h>

using namespace std;

enum TYPE
{
    IN = 0,
    OUT = 1,
    UNKNOWN = 2,
};
int main(int argc, char const *argv[])
{
    vector<int> a;
    int b = 3;
    if (a.back() != b)
        a.push_back(b);
    cout << a.size() << endl;
    return 0;
}
