#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv) {
    (void)argc;
    assert(argc == 3);
    printf("%s", argv[INPUT_ARG_INDEX]);
    return 0;
}
