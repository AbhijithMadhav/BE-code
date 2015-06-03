#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<regex.h>
#include<pthread.h>
#include<fcntl.h>

#define ERROR 0
#define UNKNOWN 1
#define OPEN 2
#define CLOSED 3

#define DEFAULT 4
#define SPECIFICATION 5
int no_of_services=3;
int http_ports[18]={80,81,1075, 1182, 3128, 4480, 6588, 8000, 8080, 8081, 8090, 5490, 7033, 8085, 8095, 8100, 8105, 8110};
int smtp_ports[5]={25,5521,5525,7721,7725};
int ftp_ports[2]={1183,21};
int no_of_hosts=0;
int scan_method=DEFAULT;

struct service_port
{
	char service[10];
	int port_no;
	struct service_port *next;
	int result;
	struct host *h;
};
typedef struct service_port service_port;

struct host
{
	char name[10];
	struct host *next;
	struct service_port *p;
};
typedef struct host host;
host *h_first=NULL;

//add from the front
void add_host(char *name)
{
	host *temp=(host*)malloc(sizeof(host));        

	strcpy(temp->name,name);
	temp->p=NULL;
	if(h_first==NULL)
		temp->next=NULL;
	else
		temp->next=h_first;

	h_first=temp;
}

//add from the back
void add_service_port(char *service,int port_no)
{
	service_port *temp=(service_port*)malloc(sizeof(service_port));
	service_port *t;

	strcpy(temp->service,service);
	temp->port_no=port_no;
	temp->next=NULL;
	temp->h=h_first;

        if(h_first->p==NULL)
  		 h_first->p=temp;
	else
	{
		t=h_first->p;
		while(t->next!=NULL)
			t=t->next;
		t->next=temp;
	}
}
	
	
void initialise_probe_list(int argc,char *argv[])
{
	int i,smtp,http,ftp,telnet,socks;

	for(i=1;i<argc;i++)
	{//for every host
		add_host(argv[i]);
		for(smtp=0;smtp<5;smtp++)	
			add_service_port("smtp",smtp_ports[smtp]);
		for(http=0;http<18;http++)
			add_service_port("http",http_ports[http]);
		for(ftp=0;ftp<2;ftp++)
			add_service_port("ftp",ftp_ports[ftp]);
	}
}
			
void process_args_init(int argc,char *argv[])
{
	int i,j;
	char *ptr;
	int ports[2000];
	int port_count=0,host_count=0;
	char host[20][20],service[20][20];
	

	for(i=2;i<argc;i++)
	{
		if(strchr(argv[i],'.')!=NULL)
			strcpy(host[host_count++],argv[i]);
		else if((ptr=strchr(argv[i],'-'))!=NULL)
		{
			ptr++;
			strcpy(service[port_count],ptr);
			if(!(!(strcmp(service[port_count],"http"))||!(strcmp(service[port_count],"ftp"))||!(strcmp(service[port_count],"smtp"))))
			{
				printf("Invalid service specification: %s.\n");
				exit(0);
			}
			ptr--;
			*ptr='\0';
			ports[port_count++]=atoi(argv[i]);
		}
		else
		{
			printf("Invalid parameter. Usage: ./a.out -p [port-service ] [host ]\n");
			exit(0);
		}

	}

	for(i=0;i<host_count;i++)
	{
		add_host(host[i]);
		for(j=0;j<port_count;j++)
		{
			add_service_port(service[j],ports[j]);
		}
	}
}

		
		
void* probe(void *t)
{
	service_port *sp_t=(service_port*)t;
	if(strcmp(sp_t->service,"smtp")==0)
		sp_t->result=check_smtp(sp_t->port_no,sp_t->h->name);
	else if(strcmp(sp_t->service,"http")==0)
		sp_t->result=check_http(sp_t->port_no,sp_t->h->name);
        else if(strcmp(sp_t->service,"ftp")==0)
                sp_t->result=check_ftp(sp_t->port_no,sp_t->h->name);
	else
		printf("Error:probe\n");
	pthread_exit(NULL);
}


void display()
{
	printf("in display\n");
	host *h_t;
        service_port *sp_t;
        char state[20];	
	int port_count,host_count=0;
        for(h_t=h_first;h_t!=NULL;h_t=h_t->next)
	{
		printf("\nInteresting ports in %s.\n",h_t->name);
		printf("Port    State   Service\n");
		port_count=0;
                for(sp_t=h_t->p;sp_t!=NULL;sp_t=sp_t->next)
		{
			switch(sp_t->result)
			{
				case 0:strcpy(state,"error");
					break;
                                case 1:strcpy(state,"unknown");
                                        break;
                                case 2:strcpy(state,"open");
                                        break;
                                case 3:strcpy(state,"closed");
                                        break;
			}
			if(scan_method==DEFAULT)
			{
				if(strcmp(state,"closed"))//if not closed
				{
					if(!strcmp(state,"open"))//if open
	        		        	printf("%d	open	%s\n",sp_t->port_no,sp_t->service);
					else if(!strcmp(state,"unknown"))//if unknown
						printf("%d	open	unknown\n",sp_t->port_no);
					else if(!strcmp(state,"error"))//if error
						printf("%d	error	------\n",sp_t->port_no);
				}
			}
			else
			{	
				 if(!strcmp(state,"open"))//if open
                                                printf("%d	%s	%s\n",sp_t->port_no,state,sp_t->service);
				if(!strcmp(state,"closed"))//if closed
                                                printf("%d	%s	------\n",sp_t->port_no,state,sp_t->service);
                                  else if(!strcmp(state,"unknown"))//if unknown
                                                printf("%d      open    unknown\n",sp_t->port_no);
                                  else if(!strcmp(state,"error"))//if error
                                                printf("%d      error   ------\n",sp_t->port_no);
			}
			port_count++;
		}
		printf("%d ports scanned. Ports not shown above are closed.\n\n",port_count);
		host_count++;
	}
	printf("Proxy scanner run completed. %d hosts scanned in ",host_count);	
}
                
                                                                                                             
void spawn_threads()
{
        host *h_t;
        service_port *sp_t;

	pthread_attr_t attr;
        pthread_t threads[500];
        int no_threads=0,k;
                                                                                                                     
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	
	printf("Spawning threads...");
	for(h_t=h_first;h_t!=NULL;h_t=h_t->next)
                for(sp_t=h_t->p;sp_t!=NULL;sp_t=sp_t->next)
		{
                        pthread_create(&threads[no_threads],&attr,probe,(void *)sp_t);
                        no_threads++;
                }
        pthread_attr_destroy(&attr);
        for(k=0;k<no_threads;k++)
        	pthread_join(threads[k],NULL);
}


int main(int argc,char *argv[])
{
	time_t start,end;
	
	printf("Starting proxy scanner\n");
	
	if(strcmp(argv[1],"-p")==0)
	{
		scan_method=SPECIFICATION;
		process_args_init(argc,argv);
	}
	else
	{
		scan_method=DEFAULT;
		initialise_probe_list(argc,argv);
	}
		
	start=time(NULL);
	spawn_threads();
	end=time(NULL);
	
	display();
	printf(" %d seconds\n\n",(int)end-start);
	return 1;
}


int check_ftp(int port,char *host )
{
        int sd,test,length;
        char buf[1024];
        regex_t ftpreg;
        struct sockaddr_in servaddr;
                                                                                                                             
        sd=socket(AF_INET,SOCK_STREAM,0);
        if(sd<0)
	{
        //      perror("Socket fails\n");
                close(sd);
                return ERROR;
        }
                                                                                                                             
        bzero((char*)&servaddr,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=inet_addr(host);
        servaddr.sin_port=htons(port);
                                                                                                                             
        test=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
        if(test<0)
	{
        //      	perror("Connection to ftp service failed\n");
                close(sd);
                return CLOSED;
        }
	
	fcntl(sd,F_SETFL,O_NONBLOCK);	
	length=read(sd,buf,1024);
	if(length==0)
	{
		close(sd);
		return UNKNOWN;
	}
        buf[length]='\0';
        regcomp(&ftpreg,"^220",0);
        if(regexec(&ftpreg,buf,0,NULL,REG_NOSUB))
	{
      //        printf("1.Matching failed.\nFailed to detect ftp.\n");
                close(sd);
                return UNKNOWN;
        }
	write(sd,"USER am@genius\n",50);
        length=read(sd,buf,1024);
        buf[length]='\0';
        regcomp(&ftpreg,"^331",0);
        if(regexec(&ftpreg,buf,0,NULL,REG_NOSUB))
	{
    //   		printf("2.Matching failed.\nFailed to detect ftp.\n");
                close(sd);
                return UNKNOWN;
        }
	write(sd,"QUIT\n",10);        
	length=read(sd,buf,1024);
        buf[length]='\0';
        regcomp(&ftpreg,"^530",0);
        if(regexec(&ftpreg,buf,0,NULL,REG_NOSUB))
	{
  //            printf("3.Matching failed.\nFailed to detect ftp.\n");
              close(sd);
              return UNKNOWN;
        }
	close(sd);
	return OPEN;
}


int check_smtp(int port,char *host )
{
	int sd,test,length;
	char buf[1024];
	regex_t smtpreg;
	struct sockaddr_in servaddr;

	sd=socket(AF_INET,SOCK_STREAM,0);
	if(sd<0)
	{
	//	perror("Socket fails\n");
		close(sd);
		return ERROR;
	}

	bzero((char*)&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(host);
	servaddr.sin_port=htons(port);
	
	test=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if(test<0)
	{
	//	perror("Connection to smtp service failed\n");
		close(sd);
		return CLOSED;
	}

        fcntl(sd,F_SETFL,O_NONBLOCK);
	length=read(sd,buf,1024);
	if(length==0)
	{
		close(sd);
		return UNKNOWN;
	}
	
	buf[length]='\0';
	regcomp(&smtpreg,"^220",0);
	if(regexec(&smtpreg,buf,0,NULL,REG_NOSUB))
	{
	//	printf("Matching failed.\nFailed to detect smtp.\n");
		close(sd);
		return UNKNOWN;
	}
	//printf("%s",buf);
	
	write(sd,"NOOP\n",5);
	length=read(sd,buf,1024);
	buf[length]='\0';
	regcomp(&smtpreg,"^250",0);
	if(regexec(&smtpreg,buf,0,NULL,REG_NOSUB) != 0)
	{
	//	printf("Matching failed.\nFailed to detect smtp\n");
		close(sd);
		return UNKNOWN;
	}
	//printf("%s",buf);	
	
	write(sd,"QUIT\n",5);
	length=read(sd,buf,1024);
	buf[length]='\0';
	regcomp(&smtpreg,"^221",0);
	if(regexec(&smtpreg,buf,0,NULL,REG_NOSUB) != 0)
	{
    	//	printf("Matching failed.\nFailed to detect smtp\n");
		close(sd);
		return UNKNOWN;
	}
	//printf("%s",buf);	
	close(sd);
	return OPEN;
}


int check_telnet(int port_no,char *host)
{
	int sd,test,length;
        //char buf[1024];
        regex_t smtpreg;
        struct sockaddr_in servaddr;
         unsigned char sbuf[4] = {'\0'};
        unsigned char buf[1024] = {'\0'};
                                                                                                                     
        sd=socket(AF_INET,SOCK_STREAM,0);
        if(sd<0)
	{
        //      perror("Socket fails\n");
                close(sd);
                return ERROR;
        }
                                                                                                                             
        bzero((char*)&servaddr,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=inet_addr(host);
        servaddr.sin_port=htons(port_no);
                                                                                                                             
        test=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
        if(test<0)
	{
        //      perror("Connection to smtp service failed\n");
                close(sd);
                return CLOSED;
        }

	sbuf[0] = 255;
	sbuf[1] = 251;
	sbuf[2] = 24;	
        write(sd,sbuf,3); 
    	read(sd,buf,1024);
	printf("%s\n",buf);
	return OPEN;
}


int check_http(int port,char *host )
{
        int sd,test,length,error_code;
        char buf[1024],*a;
        regex_t httpreg;
        struct sockaddr_in servaddr;
                                                                                                                             
        sd=socket(AF_INET,SOCK_STREAM,0);
        if(sd<0)
	{
        //      perror("Socket fails\n");
                close(sd);
                return ERROR;
        }
                                                                                                                             
        bzero((char*)&servaddr,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=inet_addr(host);
        servaddr.sin_port=htons(port);
                                                                                                                             
        test=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
        if(test<0)
	{
        //      perror("Connection to http service failed\n");
                close(sd);
                return CLOSED;
        }
	write(sd,"GET / HTTP/ \n\n",15);
        length=read(sd,buf,1024);
        buf[length]='\0';
        regcomp(&httpreg,"Content-Length:",0);
	if(regexec(&httpreg,buf,0,NULL,REG_NOSUB)!=0)
	{
//		printf("1.Matching failed. Could not detect http\n");
		close(sd);
		return UNKNOWN;
	}
	regcomp(&httpreg,"Content-Type:",0);
        if(regexec(&httpreg,buf,0,NULL,REG_NOSUB)!=0)
        {
  //              printf("2.Matching failed. Could not detect http\n");
                close(sd);
                return UNKNOWN;
        }
	regcomp(&httpreg,"^HTTP/",0);
	if(regexec(&httpreg,buf,0,NULL,REG_NOSUB)!=0)
	{
//		printf("3.Matching failed. Could not detect http\n");
		close(sd);
		return UNKNOWN;
	}	
	
	if(!(a=strchr(buf,' ')))
        {
//                printf("4.Matching failed. Could not detect http\n");
                close(sd);
                return UNKNOWN;
        }
                                                                                                                             
	if(a[1]<'1'||a[1]>'9')
        {
//                printf("5.Matching failed. Could not detect http\n");
          //      printf("%d\n",a[1]-'0');
               close(sd);
                return UNKNOWN;
        }
        if(a[2]<'0'||a[2]>'9')
        {
 //               printf("6.Matching failed. Could not detect http\n");
	//	printf("%d\n",a[2]-'0');
                close(sd);
                return UNKNOWN;
        }
        if(a[3]<'0'||a[3]>'9')
        {
 //               printf("7.Matching failed. Could not detect http\n");
          //      printf("%d\n",a[3]-'0');
                close(sd);
                return UNKNOWN;
        }
        error_code=(a[1]-'0')*100 + (a[2]-'0')*10 + (a[3]-'0');
	if(!(error_code>=400&&error_code<=499))
        {
 //               printf("8.Matching failed. Could not detect http\n");
	//	printf("Error code=%d\n",error_code);
                close(sd);
                return UNKNOWN;
        }                                                             
		
	close(sd);
	return OPEN;
}
