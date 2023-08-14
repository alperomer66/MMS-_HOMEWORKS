#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int printf_time(const char *format, ...) {
    
    time_t now;
    struct tm *timeinfo;
    char time_buffer[20]; 

    time(&now);
    timeinfo = localtime(&now);

    strftime(time_buffer, sizeof(time_buffer), "[%d.%m.%Y - %H:%M:%S]", timeinfo);

    
    printf("%s ", time_buffer);

    va_list args;
    va_start(args, format);
    int result = vprintf(format, args);
    va_end(args);

    return result;
}

int main() {
    printf_time("%d %d\n", 10, 20);
    return 0;
}
