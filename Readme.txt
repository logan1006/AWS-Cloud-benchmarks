Under the Source_code directory – 

Folder CPU-
Makefile.mk - makefile having rules to create the executable 
cpu_benchmark.c – CPU IOPS / FLOPS benchmarking and recording samples
measure_perf.c - 
measure_perf.h -
cpu.sh- running this script will run the benchmark

Running instructions :
run makefile then ./cpu.sh
 
Folder memory-
Makefile.mk - makefile having rules to create the executable
mem_benchmark.c – Memory benchmarking code
measure_perf.c - 
measure_perf.h -
mem.sh- running this script will run the benchmark

Running instructions :
run makefile then ./mem.sh

Folder disk-
Makefile.mk - makefile having rules to create the executable
disk_benchmark.c – Disk benchmarking code
measure_perf.c - 
measure_perf.h -
disk.sh- running this script will run the benchmark

Running instructions :
run makefile then ./disk.sh
	
Folder Network -

TCP Folder  : 
Makefile.mk - makefile having rules to create the executable
Socket-client.c -- >  client side c program file
Socket-server.c --> server side c program file

Running instructions :
After executing makefile , ser(we can give any name) and cli(we can give any name) executables are created .
Now ./ser on server , it will wait for connection from client machine
Now ./cli  127.0.0.1 on client , it will connect to server. ( ping pong message can be passed)

UDP  Folder : 
Makefile.mk - makefile having rules to create the executable
Socket-client.c -- >  client side c program file
Socket-server.c --> server side c program file

Running instructions :
After executing makefile , ser(we can give any name) and cli(we can give any name) executables are created .
Now ./ser on server , it will wait for connection from client machine
Now ./cli   on client , it will connect to server. ( ping pong message can be passed)
