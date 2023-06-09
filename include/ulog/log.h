#ifndef ULOG_LOG_H
#define ULOG_LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

#define ulog_debug(...) ulog_log(LOG_DEBUG, __VA_ARGS__)
#define ulog_info(...)  ulog_log(LOG_INFO,  __VA_ARGS__)
#define ulog_warn(...)  ulog_log(LOG_WARN,  __VA_ARGS__)
#define ulog_error(...) ulog_log(LOG_ERROR, __VA_ARGS__)
#define ulog_fatal(...) ulog_log(LOG_FATAL, __VA_ARGS__)

enum {
    LOG_FATAL, LOG_ERROR, LOG_WARN, LOG_INFO, LOG_DEBUG,
};

void ulog_log(int log_level, const char *fmt, ...) __attribute__ ((format(printf, 2, 3)));

#endif // ULOG_LOG_H