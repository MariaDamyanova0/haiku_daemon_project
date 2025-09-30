#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HAIKU_LENGTH 256

void log_haiku(const char *student_id, const char *haiku) {
    FILE *log_file = fopen("student_log.txt", "a");
    if (!log_file) {
        perror("Error opening log file");
        return;
    }

    // Get current time
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char time_str[26];
    strftime(time_str, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    // Write to log file
    fprintf(log_file, "Time: %s, Student ID: %s, Haiku: %s\n", time_str, student_id, haiku);
    fclose(log_file);
}

int main() {
    // Example usage of logging Haikus
    log_haiku("student_1", "The quick brown fox");
    log_haiku("student_1", "Jumps over the lazy dog");
    log_haiku("student_1", "And runs away swiftly");

    printf("Haikus logged successfully!\n");
    return 0;
}
