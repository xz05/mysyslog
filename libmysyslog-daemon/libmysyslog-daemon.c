#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libmysyslog.h"  // Включаем заголовочный файл
void handle_signal(int signal) {
    // Обработка сигналов, можно добавить логику завершения
    if (signal == SIGTERM || signal == SIGINT) {
        printf("Received termination signal\n");
        exit(0);
    }
}

int main() {
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    while (1) {
        mysyslog("Daemon running", CRITICAL, 1, "/var/log/mysyslog.log");
        sleep(60); // Запись в лог каждую минуту
    }

    return 0;
}
