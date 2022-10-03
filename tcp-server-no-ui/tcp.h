#ifndef _TCP_H_
#define _TCP_H_

// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//                        SERVER
// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#define SERV_IP         "121.37.187.125"
#define SERV_PORT       "22"                // 没有也可以

#define SIZE 1024

int tcp_server_init(char *ip,short port, int backlog);
int tcp_server_communication(int connectFd);
int print(char *s);

// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//                        CLIENT
// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

int tcp_client_init(char *ip,short port);
int tcp_client_communication(int connectFd, char buf[]);

#endif