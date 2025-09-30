#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_WORD_LEN 100

// Function to log full Haikus
void log_haiku(char haiku[][MAX_WORD_LEN * 7]) {
    FILE *log_file = fopen("student.log", "a");
    if (log_file == NULL) {
        perror("Error opening log file");
        return;
    }

    fprintf(log_file, "%s\n%s\n%s\n\n", haiku[0], haiku[1], haiku[2]); // Save full Haiku
    fclose(log_file);
}

// Function to receive words and form a Haiku
void collect_haiku(int sock) {
    char word[MAX_WORD_LEN];
    char haiku[3][MAX_WORD_LEN * 7] = {""}; // Store each Haiku line
    int word_count = 0;
    int haiku_structure[3] = {5, 7, 5}; // Haiku format
    int line = 0;

    while (1) {
        // Receive a word from the master
        if (recv(sock, word, MAX_WORD_LEN, 0) <= 0) {
            perror("Error receiving word");
            break;
        }

        printf("Received word: %s\n", word);

        // If "quit" is received, stop immediately
        if (strcmp(word, "quit") == 0) {
            printf("Received 'quit'. Exiting...\n");
            break;
        }

        // Add the word to the current Haiku line
        if (word_count == 0) {
            strcpy(haiku[line], word);
        } else {
            strcat(haiku[line], " ");
            strcat(haiku[line], word);
        }

        word_count++;

        // If a line is complete, move to the next one
        if (word_count == haiku_structure[line]) {
            word_count = 0;
            line++;

            if (line == 3) { // Full Haiku is complete
                printf("\nHaiku complete!\n%s\n%s\n%s\n\n", haiku[0], haiku[1], haiku[2]);

                log_haiku(haiku); // Save full Haiku to log

                // Reset for the next Haiku
                memset(haiku, 0, sizeof(haiku));
                line = 0;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <host_ip> <port>\n", argv[0]);
        return 1;
    }

    int sock;
    struct sockaddr_in server_addr;
    char *hostname = argv[1];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket error");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the Master
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection error");
        return 1;
    }

    // Start collecting words for Haikus
    collect_haiku(sock);

    // Close the socket before exiting
    close(sock);
    return 0;
}
