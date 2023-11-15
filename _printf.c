#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format) {
        if (*format == '%') {
            format++; // Move past '%'
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    break;
                case 's':
                    fputs(va_arg(args, const char *), stdout);
                    break;
                case '%':
                    putchar('%');
                    break;
                default:
                    // Unsupported specifier, ignore for simplicity
                    break;
            }
        } else {
            putchar(*format);
        }

        format++;
        count++;
    }

    va_end(args);

    return count;
}

int main() {
    _printf("Hello, %s! This is a %c example. %%\n", "world", 'C');
    return 0;
}
