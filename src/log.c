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
    char buffer[19];
    va_list argp;

    time(&raw_time);
    time_info = localtime(&raw_time);

    strftime(buffer, sizeof(buffer), "[%j:%m:%d] [%H:%M]", time_info);
    free(time_info);

    fprintf(stderr, "%s [%s] ", buffer, log_string[log_level]);
    va_start(argp, fmt);
    vfprintf(stderr, fmt, argp);
    va_end(argp);
    fprintf(stderr, "\n");
}
