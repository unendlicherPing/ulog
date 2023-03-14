#ifndef ULOG_LOG_H
#define ULOG_LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#define log_debug(...) log_log(LOG_DEBUG, __VA_ARGS__)
#define log_info(...)  log_log(LOG_INFO,  __VA_ARGS__)
#define log_warn(...)  log_log(LOG_WARN,  __VA_ARGS__)
#define log_error(...) log_log(LOG_ERROR, __VA_ARGS__)
#define log_fatal(...) log_log(LOG_FATAL, __VA_ARGS__)

enum {
    LOG_FATAL, LOG_ERROR, LOG_WARN, LOG_INFO, LOG_DEBUG,
};

void ulog_log(LogLevel log_level, const char *fmt, ...);

#endif // ULOG_LOG_H