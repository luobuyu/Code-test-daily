#include <stdio.h>

float minx = 0x7fffffff, maxx = 0;
int main()
{
    int num1, num2;
    float avg1, avg2;
    float statistic(int num);
    void print_m();
    scanf("%d", &num1); //输入乐理评委的人数
    avg1 = statistic(num1);
    printf("乐理知识的平均分是%.2f\n", avg1);
    print_m();
    scanf("%d", &num2); //输入演唱评委的人数
    avg2 = statistic(num2);
    printf("演唱的平均分是%.2f\n", avg2);
    print_m();
}

/* 请在这里填写答案 */
float statistic(int num)
{
    minx = 0x7fffffff, maxx = 0;
    float x, sum = 0;
    for (int i = 1; i <= num; i++)
    {
        scanf("%lf", &x);
        if (i == 1)
        {
            minx = maxx = x;
        }
        else
        {
            minx = (minx < x ? minx : x);
            maxx = (maxx > x ? maxx : x);
        }
        sum += x;
    }
    return sum / num;
}

void print_m()
{
    printf("最高分是%.2f\n", maxx);
    printf("最低分是%.2f\n", minx);
}