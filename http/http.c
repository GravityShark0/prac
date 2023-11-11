#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

/* Socket headers */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <arpa/inet.h>

#define SIZE 1024
#define BACKLOG 10


int main(int argc, char *argv[])
{
    /* Define the header */
    char http_header[] = "HTTP/1.1 200 OK\r\n\n";

    /* socket(domain, type, protocol) to define a socket
     * AF_INET = ipv4
     * SOCK_STREAM is something
     * 0 cause there is a single protocol
     * man socket */
    int server_socket = socket(
        AF_INET,
        SOCK_STREAM,
        0 
    );

    /* sockaddr_in it describes a socket */
    struct sockaddr_in server_address;


    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8000);
    /* INADDR_ANY = 0.0.0.0 */
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    /* then we bind it */
    
    /* bind() assigns the address specified by serverAddress to the socket
     * referred to by the file descriptor serverSocket.
     * bind(int fd, const struct sockaddr *addr, socklen_t len) */
    int binding = bind(
        server_socket,
        (struct sockaddr *) &server_address,
        sizeof(server_address)
    );

    int listening = listen(server_socket, BACKLOG);

    /* Check if its working */
    if ((listening) ) {
        puts("Holy shit this is womba balony");
        return 1;
    }

    /* SO MANY MACROS
     * INET6_ADDRSTRLEN = length of inet6 address
     * NI_MAXSERV = 32, which is a reasonable amount it says
     *
     * */
    /* char host_buffer[INET6_ADDRSTRLEN]; */
    /* char service_buffer[NI_MAXSERV]; // defined in `<netdb.h>` */
    /* socklen_t addr_len = sizeof(server_address); */
    /* int err = getnameinfo( */
    /*     server_address, */
    /*     addr_len, */
    /*     host_buffer, */
    /*     sizeof(host_buffer), */
    /*     service_buffer, */
    /*     sizeof(service_buffer), */
    /*     NI_NUMERICHOST */
    /* ); */
    /* if (err != 0) { */
    /*     printf("It's not working!!\n"); */
    /* } */
    /* printf("\n\n\tServer listening on http://%s:%s\n", host_buffer, service_buffer); */
            

    FILE* openhtml = fopen("index.html", "r");

    if ()
    char line[100];
    char responseData[8000];
    while (fgets(line, 100, htmlData) != 0) {
        strcat(responseData, line);
    }
    // char httpHeader[8000] = "HTTP/1.1 200 OK\r\n\n";
    strcat(http_header, responseData);

    int client_socket;
    while(1) {
        client_socket = accept(server_socket, NULL, NULL);
        send(client_socket, http_header, sizeof(http_header), 0);
        close(client_socket);
    }

    return EXIT_SUCCESS;
}
