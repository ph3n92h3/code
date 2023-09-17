#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <windows.h> //使用Sleep的头
#include <math.h>

#define MAX_COUNT 1000
//#define PI 3.14159265358979323846
double g = 0.;

void *func()
{
    for (int i = 1; i <= MAX_COUNT; ++i)
    {
        g++;
        printf("%.15lf\t%.15lf\t%.15lf\n", sin(M_PI * g / MAX_COUNT), cos(M_PI * g / MAX_COUNT), tan(M_PI * g / MAX_COUNT));
        Sleep(1);
    }
}

int main()
{
    clock_t begin_t, end_t;

    begin_t = clock();

    func();

    end_t = clock();

    printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs", CLOCKS_PER_SEC, (double)(end_t - begin_t) / CLOCKS_PER_SEC);

    return 0;
}

//constant CLOCKS_PER_SEC is: 1000, time cost is: 15.459000 secs