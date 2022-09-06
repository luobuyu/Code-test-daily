#include <stdio.h>
#include <iostream>
#include <time.h>
#include <unordered_set>
using namespace std;
int main(int argc, char *argv[])
{
    unordered_set<int> s(100);
    cout << s.size() << endl;
    return 0;
}
