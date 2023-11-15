#include <shared/util.h>
#include <stdarg.h>
#include <stdio.h>
#ifdef __APPLE__
    #include <unistd.h>
#endif

void u_prompt(const char* text, ...) {
    putchar('\n');

    va_list args;
    va_start(args, text);
    vprintf(text, args);
    va_end(args);

    putchar(' ');
    // need to flush here to ensure the prompt is displayed, since there's no newline
    fflush(stdout);

#ifdef __APPLE__
    char buf;
    read(0, &buf, 1);
#else
    getchar();
#endif

    putchar('\n');
}
