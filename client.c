#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

int main()
{
    struct sockaddr_in client;
    int sock;                    //文件描述符
    char buff[684];
    // 协议 SOCK_INET IPv4,SOCK_INET6 IPv6
    // SOCK_DGRAM 无连接UDP SOCK_STREAM 有连接TCP

    if((sock = socket(AF_INET,SOCK_DGRAM,0))==-1)
    {
        perror("error");
    }

    memset(&client,0,sizeof(client));
    client.sin_family = AF_INET;           
    client.sin_port = htons(8888);                //端口号
    client.sin_addr.s_addr = INADDR_ANY;          //地址0x0000

    scanf("%s",buff);

    int sock_len = sizeof(client);

    sendto(sock,buff,strlen(buff),0,(struct sockaddr*)&client,sock_len);
    return 0;
}
