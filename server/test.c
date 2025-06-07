#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_fd) {
    char buffer[BUFFER_SIZE];
    read(client_fd, buffer, sizeof(buffer) - 1);

    // Very simple parse: get the requested path
    char method[8], path[256];
    sscanf(buffer, "%s %s", method, path);

    // If root, serve index.html
    if (strcmp(path, "/") == 0) {
        strcpy(path, "/index.html");
    }

    char full_path[512];
    sprintf(full_path, "www%s", path); // www/ is your web root

    int file_fd = open(full_path, O_RDONLY);
    if (file_fd < 0) {
        // File not found
        const char *not_found = "HTTP/1.1 404 Not Found\r\n\r\n404 Not Found";
        send(client_fd, not_found, strlen(not_found), 0);
    } else {
        const char *header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
        send(client_fd, header, strlen(header), 0);

        ssize_t n;
        while ((n = read(file_fd, buffer, sizeof(buffer))) > 0) {
            send(client_fd, buffer, n, 0);
        }
        close(file_fd);
    }
    close(client_fd);
}
