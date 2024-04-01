#include <bits/stdc++.h>

using namespace std;

class A
{
public:
    void fun() {
        delete this;
    }
};

void test()
{
    A *a = new A();
    a->fun();
}

int main()
{
    test();
    cout << "2131" << endl;
    return 0;
}