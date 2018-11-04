echo "----Disk performance tests ---"
./measure_perf disk 1 seq 8 write
./measure_perf disk 1 seq 8192 write
./measure_perf disk 1 seq 8388608 write
./measure_perf disk 1 seq 83886080 write

./measure_perf disk 1 seq 8 read
./measure_perf disk 1 seq 8192 read
./measure_perf disk 1 seq 8388608 read
./measure_perf disk 1 seq 83886080 read

./measure_perf disk 2 seq 8 write
./measure_perf disk 2 seq 8192 write
./measure_perf disk 2 seq 8388608 write
./measure_perf disk 2 seq 83886080 write

./measure_perf disk 2 seq 8 read
./measure_perf disk 2 seq 8192 read
./measure_perf disk 2 seq 8388608 read
./measure_perf disk 2 seq 83886080 read

./measure_perf disk 4 seq 8 write
./measure_perf disk 4 seq 8192 write
./measure_perf disk 4 seq 8388608 write
./measure_perf disk 4 seq 83886080 write

./measure_perf disk 4 seq 8 read
./measure_perf disk 4 seq 8192 read
./measure_perf disk 4 seq 8388608 read
./measure_perf disk 4 seq 83886080 read

./measure_perf disk 8 seq 8 write
./measure_perf disk 8 seq 8192 write
./measure_perf disk 8 seq 8388608 write
./measure_perf disk 8 seq 83886080 write

./measure_perf disk 8 seq 8 read
./measure_perf disk 8 seq 8192 read
./measure_perf disk 8 seq 8388608 read
./measure_perf disk 8 seq 83886080 read

./measure_perf disk 1 ran 8 write
./measure_perf disk 1 ran 8192 write
./measure_perf disk 1 ran 8388608 write
./measure_perf disk 1 ran 83886080 write

./measure_perf disk 1 ran 8 read
./measure_perf disk 1 ran 8192 read
./measure_perf disk 1 ran 8388608 read
./measure_perf disk 1 ran 83886080 read

./measure_perf disk 2 ran 8 write
./measure_perf disk 2 ran 8192 write
./measure_perf disk 2 ran 8388608 write
./measure_perf disk 2 ran 83886080 write

./measure_perf disk 2 ran 8 read
./measure_perf disk 2 ran 8192 read
./measure_perf disk 2 ran 8388608 read
./measure_perf disk 2 ran 83886080 read

./measure_perf disk 4 ran 8 write
./measure_perf disk 4 ran 8192 write
./measure_perf disk 4 ran 8388608 write
./measure_perf disk 4 ran 83886080 write

./measure_perf disk 4 ran 8 read
./measure_perf disk 4 ran 8192 read
./measure_perf disk 4 ran 8388608 read
./measure_perf disk 4 ran 83886080 read

./measure_perf disk 8 ran 8 write
./measure_perf disk 8 ran 8192 write
./measure_perf disk 8 ran 8388608 write
./measure_perf disk 8 ran 83886080 write

./measure_perf disk 8 ran 8 read
./measure_perf disk 8 ran 8192 read
./measure_perf disk 8 ran 8388608 read
./measure_perf disk 8 ran 83886080 read
