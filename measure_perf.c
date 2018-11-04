#include <stdio.h>
#include <string.h>
#include "measure_perf.h"

int threads;

int access_type;
int block_size;
int ops;

int debug_mode = 0;

int main (int argc, char *argv[])
{
    if (argc < 3) {
        goto INVALID;
    }

    threads = atoi(argv[2]);


   if (strcmp(argv[1], "memory") == 0) {

        if (threads > MAX_THREADS)
            threads = MAX_THREADS;
        if (argc < 5) {
            printf("Invalid number of arguments for memory benchmark\n");
            goto INVALID;
        }
        if (strcmp(argv[3], "seq") == 0) {
            access_type = 0;
        } else {
            access_type = 1;
        }
        block_size = atoi(argv[4]);
        if ((block_size != 8) && (block_size != 8192) && (block_size != (8388608)) && (block_size != (83886080))) {
            printf("Invalid block size\n");
            goto INVALID;
        }

        memory_benchmark();
    }
  else {
        goto INVALID;
    }
    return 0;

INVALID:
    printf ("Usage: ./measure_perf <cpu/memory/disk> <num_of_threads> [sample/seq/ran] "
            "<block_size> [read/write]\n. Refer manual for details\n");
    return 1;
}
