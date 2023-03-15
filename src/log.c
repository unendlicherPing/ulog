#include <ulog/log.h>

static char *log_string[] = {
        "FATAL",
        "ERROR",
        "WARNING",
        "INFO",
        "DEBUG",
};

void ulog_log(int log_level, const char *fmt, ...) {
    time_t raw_time;
    struct tm *time_info;
    char buffer[16];
    va_list argp;

    time(&raw_time);
    time_info = localtime(&raw_time);

    strftime(buffer, sizeof(buffer), "[%m:%d] [%H:%M]\0", time_info);

    printf("%s [%s] ", buffer, log_string[log_level]);
    va_start(argp, fmt);
    vprintf(fmt, argp);
    va_end(argp);
    printf("\n");
}
