#include"stdio.h
#include"stdlib.h"
#include"sys/types.h"
#include"sys/socket.h"
#include"string.h"
#include"netinet/in.h"
#include"netdb.h"
#include"pthread.h"
#include <time.h>

#define PORT 4444
#define BUF_SIZE 2000

void * receiveMessage(void * socket) {
 int sockfd, ret;
 int i;
// int threadCount = 0;
 char buffer[1024*64];
 sockfd = (int) socket;
 memset(buffer, 0, BUF_SIZE);
 for (i=0;i<5;i++) {
  ret = recvfrom(sockfd, buffer, BUF_SIZE, 0, NULL, NULL);
  if (ret < 0) {
   printf("Error receiving data!\n");
  } else {
   printf("server: ");
   fputs(buffer, stdout);
   //printf("\n");
  }
 }
}

int main(int argc, char**argv) {
 struct sockaddr_in addr, cl_addr;
// clock_t start_t, end_t, total_t;
 struct timeval start, end,start1,end1;
 int sockfd,ret,j=0,n;
 char buffer[1024*64];
 char * serverAddr;
 pthread_t threadCount;
 int threads = 0;

 if (argc < 2) {
  printf("usage: client < ip address >\n");
  exit(1);
 }
// start_t = clock();
gettimeofday(&start, NULL);
// printf("Starting of the program, start_t = %ld\n", start_t);
 serverAddr = argv[1];
 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 if (sockfd < 0) {
  printf("Error creating socket!\n");
  exit(1) ;}
 printf("Socket created...\n");

 memset(&addr, 0, sizeof(addr));
 addr.sin_family = AF_INET;
 addr.sin_addr.s_addr = inet_addr(serverAddr);
 addr.sin_port = PORT;

 ret = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));
 if (ret < 0) {
  printf("Error connecting to the server!\n");
  exit(1);
 }
 printf("Connected to the server...\n");

 memset(buffer, 0, BUF_SIZE);
 printf("Enter your messages one by one and press return key!\n");
 //scanf("Enter the number of threads %d",n);
 //printf("Enter the number of threads %d",n);
 //creating a new thread for receiving messages from the server
// for (j = 1; j <= n; j++)
//{
 ret = pthread_create(&threadCount, NULL, receiveMessage, (void *) sockfd);

// printf("\nNumber of threads in action: %d",j);
//}

 if (ret) {
  printf("ERROR: Return Code from pthread_create() is %d\n", ret);
  exit(1);
 }

 while (fgets(buffer, BUF_SIZE, stdin) != NULL) {
  ret = sendto(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *) &addr, sizeof(addr));
  //end_t = clock();
   gettimeofday(&end, NULL);
         // printf("End of the big loop, end_t = %ld\n", end_t);
        //  printf("%f",CLOCKS_PER_SEC);
         // total_t = (double)(end_t - start_t)*1000;

         // printf("Total time taken by CPU: %ld\n", total_t);
   double executionTime = ((1000.0*(end.tv_sec - start.tv_sec) + (end.tv_usec -start.tv_usec)/1000.0)/2000);
                        double throughput = (1 * 2 / (1048576.0)) / (executionTime/1000.0)*8*64000;
                        double network_speed=(2/executionTime)*1000000;

                        printf("*********************************************\n");
                        printf("\n network speed: %9f bits/sec \n", network_speed);
                      //printf("\nNumber of threads in action: %d",k);
                        //printf("\nRandom Access on memory: %9d bytes",block);
                        printf("\nLatency : %9f us\n", executionTime);
                        printf("Throughput : %9f Mb/sec\n",throughput);
                        printf("*********************************************\n");
  if (ret < 0) {
   printf("Error sending data!\n\t-%s", buffer);
  }
 }

 close(sockfd);
// pthread_exit(NULL);

 return 0;
}
