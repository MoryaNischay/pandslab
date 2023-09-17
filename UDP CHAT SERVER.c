UDP CHAT SERVER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

//#define SERVER_IP "127.0.0.1"
#define PORT 12345

int main() {
	char sendline[100];
	char recvline[100];
	int listen_fd,comm_fd;
	struct sockaddr_in servaddr, caddr;
	listen_fd = socket(AF_INET,SOCK_DGRAM,0);
	bzero(&servaddr,sizeof(servaddr));
	socklen_t len = sizeof(caddr);
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	bind(listen_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	while(1){
		bzero(recvline,100);
		bzero(sendline,100);
		recvfrom(listen_fd,recvline,sizeof(recvline),0,(struct sockaddr*)& caddr,&len);
		printf("From Client: %s \n",recvline);
		if (strncmp("exit",recvline,4)==0){
			close(comm_fd);
			break;
		}
		printf("\tTo Client: ");
		fgets(sendline,100,stdin);
		sendto(listen_fd,sendline,sizeof(sendline),0,(struct sockaddr*)& caddr,sizeof(caddr));
		if (strncmp("exit",sendline,4)==0){
		close(comm_fd);
		break;
		}
	}
}




UDP CHAT CLIENT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
//#define SERVER_IP "127.0.0.1"
#define PORT 12345

int main() {
	char sendl[100],recvl[100];
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	struct sockaddr_in servaddr;
	bzero(&servaddr,sizeof(servaddr));
	
	socklen_t len = sizeof(servaddr);
	servaddr.sin_family= AF_INET;
	servaddr.sin_port=htons(PORT);
	
	while(1){
		bzero(sendl,100);
		bzero(recvl,100);
		printf("To server: ");
		fgets(sendl,100,stdin);
		sendto(sockfd,sendl,sizeof(sendl),0,(struct sockaddr*) &servaddr,sizeof(servaddr));
		if (strncmp("exit",sendl,4)==0){
			close(sockfd);
			break;
		}
		recvfrom(sockfd,recvl,sizeof(recvl),0,(struct sockaddr*)&servaddr,&len);
		printf("From Server: %s\n",recvl);
		if (strncmp("exit",recvl,4)==0){
			close(sockfd);
			break;
		}
		
	}
}

