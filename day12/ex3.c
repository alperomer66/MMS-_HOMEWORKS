#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *fmt) {
    va_list args;
    va_start(args, fmt);

    int count = 0;

    while (*fmt != '\0') {
        if (*fmt == '%' && *(fmt + 1) != '\0') {
            fmt++;
            
            if (*fmt == 'd') {
                count += printf("%d", va_arg(args, int));
            } else if (*fmt == 'f') {
                count += printf("%f", va_arg(args, double));
            } else if (*fmt == 'c') {
                count += printf("%c", va_arg(args, int));
            } else {
                count += putchar('%');
                count += putchar(*fmt);
            }
        } else {
            count += putchar(*fmt);
        }
        fmt++;
    }

    va_end(args);

    return count;
}

int main() {
    int num = 42;
    double float_num = 3.14;
    char character = 'A';

    int printed_count = my_printf("Integer: %d, Float: %f, Character: %c\n", num, float_num, character);

    printf("Total characters printed: %d\n", printed_count);

    return 0;
}
