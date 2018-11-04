#!/bin/bash
#usage: ./measure_perf <cpu/memory/disk> <#_of_threads> <sample/seq/ran> <block_size> <read/write>
#"sleeps" are put in to avoid file being cached in memory

echo "----CPU performance tests ---"
#Gets both FLOPS and IOPS
./measure_perf cpu 1
./measure_perf cpu 2
./measure_perf cpu 4
./measure_perf cpu 8