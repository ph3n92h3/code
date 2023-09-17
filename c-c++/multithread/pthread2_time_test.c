#include <stdio.h>
#include <time.h>
#include <windows.h>

int g_number = 0;

#define MAX_COUNT 1000

void counter()
{
    for (int i = 1; i <= MAX_COUNT; ++i)
    {
        g_number++;
        printf("my g_number is [%d]\n", g_number);
        Sleep(1);
    }
}

int main()
{
    clock_t begin_t, end_t;

    begin_t = clock();
    counter();
    end_t = clock();

    printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs", CLOCKS_PER_SEC, (double)(end_t - begin_t) / CLOCKS_PER_SEC);

    return 0;
}

//constant CLOCKS_PER_SEC is: 1000, time cost is: 15.526000 secs