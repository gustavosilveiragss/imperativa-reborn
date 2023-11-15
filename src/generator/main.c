#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <shared/args.h>

int main(int argc, char** argv) {
    assert(argc == 3);

    const char* input = argv[INPUT_ARG];
    FILE* file = fopen(input, "w+");
    if (!file) {
        perror(strerror(errno));
        return 1;
    }

    const char* text = "12";
    const unsigned long written = fwrite(text, 1, strlen(text), file);
    printf("Wrote %lu - %s to %s\n", written, text, input);

    return 0;
}
