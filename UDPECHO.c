UDP ECHO SERVER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 12388

int main(){
	char sendline[100];
	char str[100];
	int sockfd;
	struct sockaddr_in servaddr,caddr;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	socklen_t len;
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr= htonl(INADDR_ANY);
	servaddr.sin_port=htons(SERVER_PORT);
	bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	while(1){
		bzero(str,100);
		len=sizeof(caddr);
		recvfrom(sockfd,str,sizeof(str),0,(struct sockaddr*)& caddr,&len);
		printf("Echoing back: %s\n",str);
		strcpy(sendline,str);
		sendto(sockfd,sendline,sizeof(sendline),0,(struct sockaddr*)& caddr,sizeof(caddr));
		printf("Echo Msg Sent\n");
	}
}

UDP ECHO CLIENT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include<sys/socket.h>
#include<sys/types.h>


#define SERVER_PORT 12388

int main(){
	char sendl[100],recvl[100];
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in servaddr;
	
	bzero(&servaddr,sizeof(servaddr));
	
	socklen_t len = sizeof(servaddr);
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	servaddr.sin_port=htons(SERVER_PORT);
	
	while(1){
	bzero(sendl,100);
	bzero(recvl,100);
	printf("To server: ");
	fgets(sendl,100,stdin);
	sendto(sockfd,sendl,sizeof(sendl),0,(struct sockaddr*)&servaddr,len);
	recvfrom(sockfd,recvl,sizeof(sendl),0,(struct sockaddr*)&servaddr,&len);
	printf("From server: %s",recvl);
	}
}