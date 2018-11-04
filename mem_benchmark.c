#include "measure_perf.h"
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>


typedef struct memory_details {
    int threadId;
    unsigned long memorysize;
} memory_info;

unsigned long memorysize[] = {8, 8192, 8388608, 83886080};
long long int  bc= 1000000000;
char *source, *destination;


void * sequential_read_write (void *arg) {
    memory_info *mi = (memory_info *)arg;
    long blocksize = mi->memorysize;
    int threadId = mi->threadId;
    int begin = 0, finish = 10 * blocksize;
    long count = bc, i = 0, j = 0;

 if (threadId == 1) {
        finish = finish/2;
        count = bc / 2;
    } else if (threadId == 2) {
        begin = finish/2;
        i = bc / 2;
    } else if (threadId == 3) {
        begin = finish/4;
        i = bc / 4;
    } else if (threadId == 4) {
        begin = finish/4;
        i = bc / 4;
        } else if (threadId == 5) {
        begin = finish/4;
        i = bc / 4;
        } else if (threadId == 6) {
        begin = finish/4;
        i = bc / 4;
        } else if (threadId == 7) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 8) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 9) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 10) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 11) {
        begin = finish/8;
        i = bc / 8;
} else if (threadId == 12) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 13) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 14) {
        begin = finish/8;
        i = bc / 8;
        }

    for (; i < count;) {
        for (j = begin; j < finish; j += blocksize) {
            /* Copy in chunks of blocksize */
            memcpy(&destination[j], &source[j], blocksize);
            i += blocksize;
        }
    }
    return NULL;
}


void * random_read_write (void *arg)
{
    memory_info *mi = (memory_info *)arg;
    unsigned long blocksize = mi->memorysize;
    int threadId = mi->threadId;
    int begin = 0, finish = 10 * blocksize;
    int count = bc, i = 0, j = 0, random = 0;
    time_t key;

    srand((unsigned)time(&key));

    if (threadId == 1) {
        finish = finish/2;
        count = bc / 2;
    } else if (threadId == 2) {
        begin = finish/2;
        i = bc / 2;
    } else if (threadId == 3) {
        begin = finish/4;
        i = bc / 4;
    } else if (threadId == 4) {
        begin = finish/4;
        i = bc / 4;
        } else if (threadId == 5) {
        begin = finish/4;
        i = bc / 4;
        } else if (threadId == 6) {
        begin = finish/4;
        i = bc / 4;
        } else if (threadId == 7) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 8) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 9) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 10) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 11) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 12) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 13) {
        begin = finish/8;
        i = bc / 8;
        } else if (threadId == 14) {
        begin = finish/8;
        i = bc /8;
        }
    for (; i < count; ) {
        for (j = begin; j < finish; j += blocksize) {
            if (threadId == 1) {
                random = rand() % 49;
            } else if (threadId == 2) {
                random = (rand() % 49) + 50;
            } else if(threadId == 0){
                random = rand() % 98;
            } else if(threadId == 3){
                random = rand() % 23;
            }else if(threadId == 4){
                random = (rand() % 23)+24;
            }else if(threadId == 5){
                random = (rand() % 23)+48;
            }else if(threadId == 6){
                random = (rand() % 23)+72;
            }else if(threadId == 7){
                random = (rand() % 11);
            }else if(threadId == 8){
                random = (rand() % 11)+12;
}else if(threadId == 9){
                random = (rand() % 11)+24;
            }else if(threadId == 10){
                random = (rand() % 11)+36;
            }else if(threadId == 11){
                random = (rand() % 11)+48;
            }else if(threadId == 12){
                random = (rand() % 11)+60;
            }else if(threadId == 13){
                random = (rand() % 11)+72;
            }else if(threadId == 14){
                random = (rand() % 11)+84;
            }

            memset(&source[random * blocksize], '-', blocksize);
            i += blocksize;
        }
    }
    return NULL;
}


void memory_benchmark(void){
    memory_info mem1, mem2, mem3, mem4, mem5, mem6, mem7, mem8;
    pthread_t thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8;
    double memorypersec, difference;
    struct timeval start, finish;

    if(access_type ==0){
        if((threads == 8) || (threads == 4)){
                source = (char *) malloc(block_size*230);
                destination = (char *) malloc(block_size*230);
        } else {
                source = (char *) malloc(block_size*10);
                destination = (char *) malloc(block_size*10);
        }
    } else {
        if((threads == 8) || (threads == 4)){
                source = (char *) malloc(block_size*230);
                destination = (char *) malloc(block_size*230);

} else {
                source = (char *) malloc(block_size*100);
                destination = (char *) malloc(block_size*100);

        }
    }


        if(threads == 1){

        mem1.threadId = 0;
        mem1.memorysize = block_size;
        if (access_type == 0) {
            gettimeofday(&start, NULL);
            sequential_read_write(&mem1);
            gettimeofday(&finish, NULL);
            difference = (((double)finish.tv_usec - (double)start.tv_usec) / 1000000) +
                    ((double)finish.tv_sec - (double)start.tv_sec);
            memorypersec = bc/difference;
            printf("Memory r/w seq    test: blk size: %lu, Threads: 1 throughput %10.4f MBps "
                                        "latency %g usec\n", block_size,  (memorypersec)/(1024*1024),
                   ((difference * 1000 * 1000)/(bc)));
        } else {
            gettimeofday(&start, NULL);
            random_read_write(&mem1);
            gettimeofday(&finish, NULL);
            difference = (((double)finish.tv_usec - (double)start.tv_usec) / 1000000) +
                    ((double)finish.tv_sec - (double)start.tv_sec);
            memorypersec = (double)bc/difference;
            printf("Memory r/w random test: blk size: %9ld, Threads: 1 throughput %10.4f MBps "
                   "latency %g usec\n", block_size,  memorypersec / (1024 * 1024),
                  ((difference * 1000 * 1000)/((double) bc)));
        }
        } else if (threads == 2){

        mem1.threadId = 1;
        mem1.memorysize = block_size;
        mem2.threadId = 2;
        mem2.memorysize = block_size;
        if (access_type == 0) {
            gettimeofday(&start, NULL);
            pthread_create(&thread1, NULL, sequential_read_write, &mem1);
 pthread_create(&thread2, NULL, sequential_read_write, &mem2);

            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);

            gettimeofday(&finish, NULL);
            difference = (((double)finish.tv_usec - (double)start.tv_usec) / 1000000) +
                    ((double)finish.tv_sec - (double)start.tv_sec);
            memorypersec = (double)bc/difference;
            printf("Memory r/w seq    test: blk size: %9ld, Threads: 2 throughput %10.4f MBps "
                   "latency %g usec\n", block_size,  memorypersec / (1024 * 1024),
                   ((difference * 1000 * 1000)/((double) bc)));
       } else {
            gettimeofday(&start, NULL);
            pthread_create(&thread1, NULL, random_read_write, &mem1);
            pthread_create(&thread2, NULL, random_read_write, &mem2);


            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);

            gettimeofday(&finish, NULL);
            difference = (((double)finish.tv_usec - (double)start.tv_usec) / 1000000) +
                    ((double)finish.tv_sec - (double)start.tv_sec);
            memorypersec = (double)bc/difference;
            printf("Memory r/w random test: blk size: %9ld, Threads: 2 throughput %10.4f MBps "
                   "latency %g usec\n", block_size,  memorypersec / (1024 * 1024),
                   ((difference * 1000 * 1000)/((double) bc)));
        }

        } else if (threads == 4){
                mem1.threadId = 3;
        mem1.memorysize = block_size;
        mem2.threadId = 4;
        mem2.memorysize = block_size;
                mem3.threadId = 5;
        mem3.memorysize = block_size;
                mem4.threadId = 6;
        mem4.memorysize = block_size;
                if (access_type == 0) {
            gettimeofday(&start, NULL);
 pthread_create(&thread1, NULL, sequential_read_write, &mem1);
            pthread_create(&thread2, NULL, sequential_read_write, &mem2);
                        pthread_create(&thread3, NULL, sequential_read_write, &mem3);
                        pthread_create(&thread4, NULL, sequential_read_write, &mem4);
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);
                        pthread_join(thread3, NULL);
                        pthread_join(thread4, NULL);

            gettimeofday(&finish, NULL);
            difference = (((double)finish.tv_usec - (double)start.tv_usec) / 1000000) +
                    ((double)finish.tv_sec - (double)start.tv_sec);
            memorypersec = (double)bc/difference;
            printf("Memory r/w seq    test: blk size: %9ld, Threads: 4 throughput %10.4f MBps "
                   "latency %g usec\n", block_size,  memorypersec / (1024 * 1024),
                   ((difference * 1000 * 1000)/((double) bc)));
       } else {
            gettimeofday(&start, NULL);
            pthread_create(&thread1, NULL, sequential_read_write, &mem1);
            pthread_create(&thread2, NULL, sequential_read_write, &mem2);
                        pthread_create(&thread3, NULL, sequential_read_write, &mem3);
                        pthread_create(&thread4, NULL, sequential_read_write, &mem4);
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);
                        pthread_join(thread3, NULL);
                        pthread_join(thread4, NULL);

            gettimeofday(&finish, NULL);
            difference = (((double)finish.tv_usec - (double)start.tv_usec) / 1000000) +
                    ((double)finish.tv_sec - (double)start.tv_sec);
            memorypersec = (double)bc/difference;
            printf("Memory r/w random test: blk size: %9ld, Threads: 4 throughput %10.4f MBps "
                   "latency %g usec\n", block_size,  memorypersec / (1024 * 1024),
                   ((difference * 1000 * 1000)/((double) bc)));
        }
        } else if (threads == 8){
                mem1.threadId = 7;
        mem1.memorysize = block_size;
        mem2.threadId = 8;
        mem2.memorysize = block_size;
mem3.threadId = 9;
        mem3.memorysize = block_size;
                mem4.threadId = 10;
        mem4.memorysize = block_size;
                mem5.threadId = 11;
        mem5.memorysize = block_size;
                mem6.threadId = 12;
        mem6.memorysize = block_size;
                mem7.threadId = 13;
        mem7.memorysize = block_size;
                mem8.threadId = 14;
        mem8.memorysize = block_size;

                if (access_type == 0) {
            gettimeofday(&start, NULL);
            pthread_create(&thread1, NULL, sequential_read_write, &mem1);
            pthread_create(&thread2, NULL, sequential_read_write, &mem2);
                        pthread_create(&thread3, NULL, sequential_read_write, &mem3);
                        pthread_create(&thread4, NULL, sequential_read_write, &mem4);
                        pthread_create(&thread5, NULL, sequential_read_write, &mem5);
            pthread_create(&thread6, NULL, sequential_read_write, &mem6);
                        pthread_create(&thread7, NULL, sequential_read_write, &mem7);
                        pthread_create(&thread8, NULL, sequential_read_write, &mem8);
                        /* Wait for the threads */
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);
                        pthread_join(thread3, NULL);
                        pthread_join(thread4, NULL);
                        pthread_join(thread5, NULL);
            pthread_join(thread6, NULL);
                        pthread_join(thread7, NULL);
                        pthread_join(thread8, NULL);

            gettimeofday(&finish, NULL);
            difference = (((double)finish.tv_usec - (double)start.tv_usec) / 1000000) +
                    ((double)finish.tv_sec - (double)start.tv_sec);
            memorypersec = (double)bc/difference;
            printf("Memory r/w seq    test: blk size: %9ld, Threads: 8 throughput %10.4f MBps "
                   "latency %g usec\n", block_size,  memorypersec / (1024*1024),
                   ((difference * 1000 * 1000)/((double) bc)));
       } else {
 gettimeofday(&start, NULL);
            pthread_create(&thread1, NULL, sequential_read_write, &mem1);
            pthread_create(&thread2, NULL, sequential_read_write, &mem2);
                        pthread_create(&thread3, NULL, sequential_read_write, &mem3);
                        pthread_create(&thread4, NULL, sequential_read_write, &mem4);
                        pthread_create(&thread5, NULL, sequential_read_write, &mem5);
            pthread_create(&thread6, NULL, sequential_read_write, &mem6);
                        pthread_create(&thread7, NULL, sequential_read_write, &mem7);
                        pthread_create(&thread8, NULL, sequential_read_write, &mem8);
                        /* Wait for the threads */
            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);
                        pthread_join(thread3, NULL);
                        pthread_join(thread4, NULL);
                        pthread_join(thread5, NULL);
            pthread_join(thread6, NULL);
                        pthread_join(thread7, NULL);
                        pthread_join(thread8, NULL);

            gettimeofday(&finish, NULL);
            difference = (((double)finish.tv_usec - (double)start.tv_usec) / 1000000) +
                    ((double)finish.tv_sec - (double)start.tv_sec);
            memorypersec = (double)bc/difference;
            printf("Memory r/w random test: blk size: %9ld, Threads: 8 throughput %10.4f MBps "
                   "latency %g usec\n", block_size,  memorypersec / (1024 * 1024),
                   ((difference * 1000 * 1000)/((double) bc)));
        }

        }
    free (source);
    free (destination);
}