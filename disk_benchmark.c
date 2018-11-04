#include "measure_perf.h"

#define FILESIZE  (512*1024*1024)
#define TARGET FILESIZE

int iter;

typedef struct thread_data_ {
    FILE *fp;
    char *buf;
} thread_data;

void *
disk_seq_r (void *arg)
{
    thread_data *d = (thread_data *)arg;
    FILE *fp = d->fp;
    int i;

    fseek(fp, 0, SEEK_SET);

    for (i = 0; i < iter; i++) {
        fread(d->buf, block_size, 1, fp);
    }
    return NULL;
}

void *
disk_seq_w (void *arg)
{
    thread_data *d = (thread_data *)arg;
    FILE *fp = d->fp;
    int i;

    fseek(fp, 0, SEEK_SET);

    /* Read for "iter" iterations, each time "block_size" number of bytes */
    for (i = 0; i < iter; i++) {
        fwrite(d->buf, block_size, 1, fp);
    }
    return NULL;
}

void *
disk_ran_r (void *arg)
{
    thread_data *d = (thread_data *)arg;
    FILE *fp = d->fp;
    int i;
    time_t t;

    srand((unsigned)time(&t));
    for (i = 0; i < iter; i++) {
        fseek(fp, (rand() % ((FILESIZE) - block_size)), SEEK_SET);
        fread(d->buf, block_size, 1, fp);
    }
    return NULL;
}

void *
disk_ran_w (void *arg)
{
    thread_data *d = (thread_data *)arg;
    FILE *fp = d->fp;
    int i;
    time_t t;

    srand((unsigned)time(&t));

    for (i = 0; i < iter; i++) {
        fseek(fp, (rand() % ((FILESIZE) - block_size)), SEEK_SET);
        fwrite(d->buf, block_size, 1, fp);
    }
    return NULL;
}

void
disk_benchmark (void)
{
    pthread_t t[8];
    struct timeval s, e;
    void *(*func)(void *);
    thread_data td[8];
    int i;
    double diff, throughput, latency;

    if (op == 0) { /* read */
       if (access_type == 0) {
            func = disk_seq_r;
        } else {
            func = disk_ran_r;
        }
    } else {
        if (access_type == 0) {
            func = disk_seq_w;
        } else {
            func = disk_ran_w;
        }
    }

    if (access_type == 0) {
        iter = TARGET / block_size;
    } else {
            iter = 50000;
            if (block_size > 1024) {
                iter = iter / 100;
            }
    }

    for (i = 0; i < threads; i++) {
        char fname[10];
        sprintf(fname, "%s-%d", ((access_type == 0) ? "seq" : "ran"), i);
        td[i].fp = fopen(fname, (op == 0) ? "r" : "w");
        td[i].buf = malloc(block_size);
        if (!td[i].fp || !td[i].buf) {
            printf("Malloc or fopen failure\n");
            return;
        }
    }

    gettimeofday(&s, NULL);

    for (i = 0; i < threads; i++) {
        pthread_create(&t[i], NULL, func, &td[i]);
    }

    for (i = 0; i < threads; i++) {
        pthread_join(t[i], NULL);
    }
    gettimeofday(&e, NULL);

    diff = (((double)e.tv_usec - (double)s.tv_usec) / 1000000 +
            ((double)e.tv_sec - (double)s.tv_sec));

    throughput = ((double)threads * iter * block_size)/(diff*1024*1024);
    latency = (diff * 1000 *1000) / ((double)threads * iter * block_size);

    printf("Disk: %6s, %12s, Iterations: %10d, Threads: %d, Time taken: %8.4f "
           "Throughput: %-9.4f MBps, Blocksize: %8d, Latency: %g usec\n",
           ((op == 0) ? "read" : "write"), ((access_type == 0) ? "sequential" : "random"),
           iter, threads, diff, throughput, block_size, latency);

    for (i = 0; i < threads; i++) {
        free(td[i].buf);
        fclose(td[i].fp);
    }
}
