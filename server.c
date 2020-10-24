#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<signal.h>
#include<fcntl.h>

void serve(const char* name, int port)
{

}

int main(int argc, char const **argv)
{
    const char* name = argv[1];
    int port = atoi(argv[2]);
    //check port number is valid
    if (port < 65536 && port > 1024)
    {
        //continue
        serve(name, port);
    }
    else
    {
        printf("invalid port id:%d\n", port);
        return 1;
    }
    return 0;
}
