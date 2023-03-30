#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool vis[4];
int a[4];
int sum;

int s1[5];
int top1 = -1;
char op[5];
int optop = -1;
int s2[5];
int top2 = -1;
int pro[5];
int protop = -1;

bool dfs(int step)
{
    if (step == 3)
    {
        bool find = false;
        for (int i = 0; i < 4 && vis[i] == false; i++)
        {
            if (a[i] == 24)
            {
                find = true;
            }
        }

        if (find)
        {
            int start = 0;
            while (start <= top1)
            {
                cout << s1[start] << op[start] << s2[start] << '=' << pro[start] << endl;
                start++;
            }
            exit(0);
        }
        return find;
    }
    else
    {
        int maxe, mine, x;
        for (int i = 0; i < 4; i++)
        {
            if (vis[i] == false)
            {
                for (int j = i + 1; j < 4; j++)
                {
                    if (vis[j] == false)
                    {
                        x = a[i];
                        vis[j] = true;
                        maxe = max(a[i], a[j]);
                        mine = min(a[i], a[j]);
                        a[i] = maxe - mine;
                        s1[++top1] = maxe;
                        s2[++top2] = mine;
                        op[++optop] = '-';
                        pro[++protop] = a[i];
                        // vis[i] = false;
                        if (dfs(step + 1))
                        {
                            return true;
                        }
                        top1--;
                        top2--;
                        optop--;
                        protop--;

                        a[i] = maxe + mine;
                        // vis[i] = false;
                        s1[++top1] = maxe;
                        s2[++top2] = mine;
                        op[++optop] = '+';
                        pro[++protop] = a[i];

                        if (dfs(step + 1))
                        {
                            return true;
                        }

                        top1--;
                        top2--;
                        optop--;
                        protop--;

                        a[i] = maxe * mine;
                        // vis[i] = false;
                        s1[++top1] = maxe;
                        s2[++top2] = mine;
                        op[++optop] = '*';
                        pro[++protop] = a[i];
                        // vis[i] = false;
                        if (dfs(step + 1))
                        {
                            return true;
                        }

                        if (mine != 0 && maxe % mine == 0)
                        {

                            top1--;
                            top2--;
                            optop--;
                            protop--;

                            a[i] = maxe / mine;
                            // vis[i] = false;
                            s1[++top1] = maxe;
                            s2[++top2] = mine;
                            op[++optop] = '/';
                            pro[++protop] = a[i];

                            // vis[i] = false;
                            if (dfs(step + 1))
                            {
                                return true;
                            }
                        }

                        a[i] = x;
                        vis[j] = false;
                        top1--;
                        top2--;
                        optop--;
                        protop--;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &a[i]);
    }
    if (!dfs(0))
    {
        cout << "No answer!" << endl;
    }

    return 0;
}