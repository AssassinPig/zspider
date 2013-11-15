#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include<sys/stat.h>
#include<fcntl.h>

#define URL_MAX 1024
#define HOST_MAX 1024
#define REQUEST_MAX 1024
#define BUF_MAX 1024

