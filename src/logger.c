#define PLIBC_LOGGER_STRUCT
#define PLIBC_LOGGER_FUNC
#include <logger.h>

void Logger_info_v(const char *fmt, va_list args) {
        time_t currentTime = time(NULL);
        struct tm time = *localtime(&currentTime);
        fprintf(stdout, "[INFO]    %02d/%02d/%04d %02d:%02d:%02d -> ", time.tm_mday, time.tm_mon + 1, time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
        vfprintf(stdout, fmt, args);
        fprintf(stdout, "\n");
}

void Logger_warn_v(const char *fmt, va_list args) {
        time_t currentTime = time(NULL);
        struct tm time = *localtime(&currentTime);
        fprintf(stderr, "[WARNING] %02d/%02d/%04d %02d:%02d:%02d -> ", time.tm_mday, time.tm_mon + 1, time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
        vfprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
}

void Logger_error_v(const char *fmt, va_list args) {
        time_t currentTime = time(NULL);
        struct tm time = *localtime(&currentTime);
        fprintf(stderr, "[ERROR]   %02d/%02d/%04d %02d:%02d:%02d -> ", time.tm_mday, time.tm_mon + 1, time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
        vfprintf(stderr, fmt, args);
        fprintf(stderr, "\n");
}

void Logger_debug_v(const char *fmt, va_list args) {
        time_t currentTime = time(NULL);
        struct tm time = *localtime(&currentTime);
        fprintf(stdout, "[DEBUG]   %02d/%02d/%04d %02d:%02d:%02d -> ", time.tm_mday, time.tm_mon + 1, time.tm_year + 1900, time.tm_hour, time.tm_min, time.tm_sec);
        vfprintf(stdout, fmt, args);
        fprintf(stdout, "\n");
}


void Logger_info(const char* fmt, ...) {
        va_list list;
        va_start(list, fmt);
        Logger_info_v(fmt, list);
        va_end(list);
}

void Logger_warn(const char* fmt, ...) {
        va_list list;
        va_start(list, fmt);
        Logger_warn_v(fmt, list);
        va_end(list);
}

void Logger_error(const char* fmt, ...) {
        va_list list;
        va_start(list, fmt);
        Logger_error_v(fmt, list);
        va_end(list);
}

void Logger_debug(const char* fmt, ...)  {
        va_list list;
        va_start(list, fmt);
        Logger_debug_v(fmt, list);
        va_end(list);
}

struct logger Logger_createDefault() {
        return (struct logger) {
                .info = Logger_info,
                .warn = Logger_warn,
                .error = Logger_error,
                .debug = Logger_debug,
        }; 
}
