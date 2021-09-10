#include<bits/stdc++.h>

namespace FAST_IO
{
    template<class T>
    inline void read(T & x)
    {
        T flag = 1;
        x = 0;
        char ch = getchar();
        while(ch < '0' || ch > '9')
        {
            if(ch == '-')
                flag = -1;
            ch = getchar();
        }

        while(ch >= '0' && ch <= '9')
        {
            x = (x << 3) + (x << 1) + (ch - '0');
            ch = getchar();
        }
        x *= flag;
    }

    template <class T, class ... _T>
    inline void read(T&x, _T & ...y)
    {
        return read(x), read(y...);
    }
}

using namespace FAST_IO;
int n, m;
int main()
{
    read(n, m);
    printf("%d %d\n", n, m);
    return 0;
}