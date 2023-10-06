#ifndef PLIBC_LOGGER_BASE_H
#define PLIBC_LOGGER_BASE_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#include "types.h"

#ifdef  PLIBC_LOGGER_STRUCT

struct logger {
        char name[100];
        void (*info)(const char *, ...);
        void (*warn)(const char *, ...);
        void (*error)(const char *, ...);
        void (*debug)(const char *, ...);
};

struct logger Logger_createDefault();

#endif

#ifdef  PLIBC_LOGGER_FUNC

void Logger_info_v(const char *fmt, va_list args);
void Logger_warn_v(const char *fmt, va_list args);
void Logger_error_v(const char *fmt, va_list args);
void Logger_debug_v(const char *fmt, va_list args);

void Logger_info(const char *fmt, ...);
void Logger_warn(const char *fmt, ...);
void Logger_error(const char *fmt, ...);
void Logger_debug(const char *fmt, ...);

#endif
#endif
