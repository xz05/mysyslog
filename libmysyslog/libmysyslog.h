#ifndef MYSYSLOG_H
#define MYSYSLOG_H

// Уровни логирования
#define DEBUG 0
#define INFO 1
#define WARN 2
#define ERROR 3
#define CRITICAL 4

// Функция для логирования сообщений
int mysyslog(const char* msg, int level, int driver, const char* path);

#endif // MYSYSLOG_H
