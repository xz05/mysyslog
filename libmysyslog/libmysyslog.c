#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dlfcn.h>
#include "libmysyslog.h"  // Включаем заголовочный файл

typedef void (*log_func)(const char*, int, const char*, const char*);

static log_func logger = NULL;

void load_driver(int driver) {
    const char* lib_name;
    switch (driver) {
        case 0:
            lib_name = "libmysyslog-text.so";
            break;
        case 1:
            lib_name = "libmysyslog-json.so";
            break;
        default:
            fprintf(stderr, "Unknown driver: %d\n", driver);
            exit(EXIT_FAILURE);
    }

    void* handle = dlopen(lib_name, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Could not open library: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    logger = (log_func)dlsym(handle, "log_function");
    if (!logger) {
        fprintf(stderr, "Could not load function: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }
}

int mysyslog(const char* msg, int level, int driver, const char* path) {
    load_driver(driver);
    logger(msg, level, "mysyslog", path);
    return 0; // Успех
}
