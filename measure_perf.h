#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

#define MAX_THREADS 8
#define CPU_MAX_THREADS 8
#define BILLION 1000000000

extern int debug_mode;

#define LOG(...) { \
    if (debug_mode) { \
        printf(__VA_ARGS__); \
    } \
}

/* externs */
extern void cpu_benchmark(void);
extern void mem_benchmark(void);
extern void disk_benchmark(void);

extern int sample;
extern int threads;
extern int block_size;
extern int access_type;
extern int ops;