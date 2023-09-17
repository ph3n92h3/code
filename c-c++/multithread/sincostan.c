#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <windows.h> //使用Sleep的头
#include <math.h>

#define MAX_COUNT 1000
//#define PI 3.14159265358979323846

double g = 0.;
pthread_mutex_t mut;

void *func(void *args)
{
    for (int i = 1; i <= MAX_COUNT / 4; ++i)
    {
        pthread_mutex_lock(&mut);
        g++;
        pthread_mutex_unlock(&mut);
        printf("%.15lf\t%.15lf\t%.15lf\n", sin(M_PI * g / MAX_COUNT), cos(M_PI * g / MAX_COUNT), tan(M_PI * g / MAX_COUNT));
        Sleep(1);
    }
}

int main()
{
    pthread_mutex_init(&mut, NULL);

    clock_t begin_t, end_t;

    begin_t = clock();

    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    /*  pthread_t t5;
    pthread_t t6;
    pthread_t t7;
    pthread_t t8;   */

    pthread_create(&t1, NULL, func, NULL);
    pthread_create(&t2, NULL, func, NULL);
    pthread_create(&t3, NULL, func, NULL);
    pthread_create(&t4, NULL, func, NULL);
    /*  pthread_create(&t5, NULL, func, NULL);
    pthread_create(&t6, NULL, func, NULL);
    pthread_create(&t7, NULL, func, NULL);
    pthread_create(&t8, NULL, func, NULL);  */

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    /*  pthread_join(t5, NULL);
    pthread_join(t6, NULL);
    pthread_join(t7, NULL);
    pthread_join(t8, NULL); */

    end_t = clock();

    printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs", CLOCKS_PER_SEC, (double)(end_t - begin_t) / CLOCKS_PER_SEC);

    return 0;
}

//constant CLOCKS_PER_SEC is : 1000, time cost is : 3.850000 secs