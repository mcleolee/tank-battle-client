
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //man 3 socket 
#include <sys/socket.h>  //man 7 ip 
#include <netinet/in.h> 
#include <netinet/ip.h> /* superset of previous */
#include <sys/socket.h>   // man  3 inet_addr
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>  //man 3 toupper 

#include "tcp.h"

using namespace std;

#define SERV_IP         "121.37.187.125"
#define SERV_PORT       "22"                // 没有也可以

#define SIZE            1024

int tcp_client_init(char *ip, short port)
{
    int connectFd = socket(PF_INET, SOCK_STREAM, 0);
    if(-1 == connectFd)
    {
        perror("socket error\n");
        return -1;
    }
    struct sockaddr_in server_address =
    {
        .sin_family         = PF_INET,
        .sin_addr.s_addr    = inet_addr(ip),
        .sin_port           = htons(port)
    };
    int len = sizeof(server_address);
    if(-1 == connect(connectFd, (struct sockaddr *)&server_address, len))
    {
        perror("connect error\n");
        return -1;
    }
    return connectFd;
}

int tcp_client_communication(int connectFd, char buf[])
{
    while(1)
    {
        int sizeof_buf = sizeof(buf);
        fgets(buf, sizeof_buf, stdin);

        write(connectFd, buf, strlen(buf));
        read(connectFd, buf, sizeof_buf);

        printf("%s\n", buf);
        
    }
}

int main(int argc, char **argv)
{

    cout << "\n-------\nhi kkive, the client is working now\n-------\n" << endl;
    char buf[SIZE] = {0};

    char ip_test_client[50] = "121.37.187.125";
    short port_test_client  = 22;

    int connectFd = tcp_client_init(ip_test_client, port_test_client);
    printf("the connectFd is %d\n", connectFd);
    tcp_client_communication(connectFd, buf);
    close(connectFd);

}