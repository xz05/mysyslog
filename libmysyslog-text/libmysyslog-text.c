#include <stdio.h>
#include <time.h>
#include "libmysyslog.h"  // Включаем заголовочный файл

void log_function(const char* msg, int level, const char* process, const char* path) {
    time_t now = time(NULL);
    FILE *file = fopen(path, "a");
    if (file) {
        fprintf(file, "%ld %d %s %s\n", now, level, process, msg);
        fclose(file);
    } else {
        perror("Failed to open log file");
    }
}
