#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

int main(){
    struct sockaddr_in server;   // 实例化一个套接字
    int sock;                    // 文件描述符
    char buff[684];
    // 协议 SOCK_INET IPv4,SOCK_INET6 IPv6
    // SOCK_DGRAM 无连接UDP SOCK_STREAM 有连接TCP

    if((sock = socket(AF_INET,SOCK_DGRAM,0))==-1){
        perror("error");
    }

    memset(&server,0,sizeof(server));
    server.sin_family = AF_INET;           
    server.sin_port = htons(8888);
    server.sin_addr.s_addr = INADDR_ANY;          //地址

    if(bind(sock,(struct sockaddr *)&server,sizeof(server)) == -1){
        perror("error");
    }
    int sock_len = sizeof(server);
    // 绑定端口后等待客户端连接
    recvfrom(sock,buff,sizeof(buff)-1,0,(struct sockaddr*)&server,&sock_len);
    // 套接字有了通信协议，IP地址，端口
    printf("message:%s\n",buff);
    return 0;
}
