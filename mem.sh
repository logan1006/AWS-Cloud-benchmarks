echo "----Memory performance tests ---"
./measure_perf memory 1 seq 8
./measure_perf memory 1 seq 8192
./measure_perf memory 1 seq 8388608
./measure_perf memory 1 seq 83886080

./measure_perf memory 2 seq 8
./measure_perf memory 2 seq 8192
./measure_perf memory 2 seq 8388608
./measure_perf memory 2 seq 83886080

./measure_perf memory 4 seq 8
./measure_perf memory 4 seq 8192
./measure_perf memory 4 seq 8388608
./measure_perf memory 4 seq 83886080

./measure_perf memory 8 seq 8
./measure_perf memory 8 seq 8192
./measure_perf memory 8 seq 8388608
./measure_perf memory 8 seq 83886080

./measure_perf memory 1 ran 8
./measure_perf memory 1 ran 8192
./measure_perf memory 1 ran 8388608
./measure_perf memory 1 ran 83886080

./measure_perf memory 2 ran 8
./measure_perf memory 2 ran 8192
./measure_perf memory 2 ran 8388608
./measure_perf memory 2 ran 83886080

./measure_perf memory 4 ran 8
./measure_perf memory 4 ran 8192
./measure_perf memory 4 ran 8388608
./measure_perf memory 4 ran 83886080

./measure_perf memory 8 ran 8
./measure_perf memory 8 ran 8192
./measure_perf memory 8 ran 8388608
./measure_perf memory 8 ran 83886080