#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "libmysyslog.h"  // Включаем заголовочный файл

int main(int argc, char *argv[]) {
    int level = INFO;
    int driver = 0; // Текстовый драйвер по умолчанию
    const char* path = "/var/log/mysyslog.log"; // Путь по умолчанию
    const char* msg = NULL;

    int opt;
    while ((opt = getopt(argc, argv, "m:l:d:p:")) != -1) {
        switch (opt) {
            case 'm':
                msg = optarg;
                break;
            case 'l':
                level = atoi(optarg);
                break;
            case 'd':
                driver = atoi(optarg);
                break;
            case 'p':
                path = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s -m message -l level -d driver -p path\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (msg) {
        mysyslog(msg, level, driver, path);
    } else {
        fprintf(stderr, "Message is required\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
