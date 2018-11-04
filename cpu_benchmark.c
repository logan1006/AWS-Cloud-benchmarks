#include "measure_perf.h"
#include <unistd.h>


int collection_done = 0;

unsigned long long iter[4];
void *
iops(void *arg)
{
    /* Some arbitrary initializations */
    register int a = 2;
    register int b = 12;
    register int c = 19;
    register int d = 79;
    register int count = 0;
    int values[5];

    for (count = 0; count < BILLION; count++) {
        values[0] = a + b + c + d + 1 + count + a*b + b*c;
        values[1] = a + b + c + d + 2 + count  + b*c + c*d;
        values[2] = a + b + c + d + 3 + count  + a*d + b*d;
        values[3] = a + b + c + d + 4 + count  + c*d + a*b;
        values[4] = a + b + c + d + 4 + count  + c*d + a*b;
    }

    return NULL;
}
void *
flops(void *arg)
{
    /* Some arbitrary initializations */
    register float a = 220.0;
    register float b = 110.2;
    register float c = 111.9;
    register float d = 711.9;
    register int count = 0;
    float values[5];

    for (count = 0; count < BILLION; count++) {
        values[0] = a + 2*b + 3*c + 4*d + a*b + a*c + a*d + b*c + b*d + c*d;
        values[1] = a + 2*b + 3*c + 4*d + a*b + a*c + a*d + b*c + b*d + c*d;
        values[2] = a + 2*b + 3*c + 4*d + a*b + a*c + a*d + b*c + b*d + c*d;
        values[3] = a + 2*b + 3*c + 4*d + a*b + a*c + a*d + b*c + b*d + c*d;
        values[4] = a + 2*b + 3*c + 4*d + a*b + a*c + a*d + b*c + b*d + c*d;
    }
    LOG("values[0] %f\n", values[0]);
    return NULL;
}

void
cpu_benchmark (void)
{
    int t;
    pthread_t thr[CPU_MAX_THREADS];
    double diff, ops;
    struct timeval s, f;
    unsigned int count = 1;



    /* record start time */
    gettimeofday(&s, NULL);

    for (t = 0; t < threads; t++) {
        pthread_create(&thr[t], NULL, &iops, NULL);
    }

    for (t = 0; t < threads; t++) {
        pthread_join(thr[t], NULL);
    }

    gettimeofday(&f, NULL);

    ops = (double)threads * 36 * BILLION;
    diff = (((double)f.tv_usec - (double)s.tv_usec) / 1000000 +
            ((double)f.tv_sec - (double)s.tv_sec));

    printf("CPU  IOPS: Operations: %12.0f, Threads: %d, Time taken: %8.4f secs, GIOPS: %8.4f\n",
           ops, threads, diff, (ops / (diff * 1000000000)));

    gettimeofday(&s, NULL);

    for (t = 0; t < threads; t++) {
        pthread_create(&thr[t], NULL, &flops, NULL);
    }

    for (t = 0; t < threads; t++) {
        pthread_join(thr[t], NULL);
    }

    gettimeofday(&f, NULL);

    ops = (double)threads * 106 * BILLION;
    diff = (((double)f.tv_usec - (double)s.tv_usec) / 1000000 +
            ((double)f.tv_sec - (double)s.tv_sec));

    printf("CPU FLOPS: Operations: %12.0f, Threads: %d, Time taken: %8.4f secs, GFLOPS: %8.4f\n",
           ops, threads, diff, (ops / (diff * 1000000000)));
}
