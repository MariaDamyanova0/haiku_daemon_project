// master/haiku_master.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 100

void start_master(int port, const char *dict_filename, int cooldown);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <port> <dictionary_file> <cooldown>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    const char *dict_filename = argv[2];
    int cooldown = atoi(argv[3]);
    
    start_master(port, dict_filename, cooldown);
    return 0;
}

void start_master(int port, const char *dict_filename, int cooldown) {
    FILE *dict_file = fopen(dict_filename, "r");
    if (!dict_file) {
        perror("Could not open dictionary file");
        exit(1);
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int word_count = 0;
    while (fgets(dictionary[word_count], MAX_WORD_LENGTH, dict_file)) {
        dictionary[word_count][strcspn(dictionary[word_count], "\n")] = '\0';
        word_count++;
    }
    fclose(dict_file);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        exit(1);
    }

    printf("Haiku Master listening on port %d...\n", port);

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("Failed to accept connection");
            continue;
        }

        for (int i = 0; i < word_count; i++) {
            send(client_fd, dictionary[i], strlen(dictionary[i]) + 1, 0);
            sleep(cooldown);
        }

        close(client_fd);
    }
}
