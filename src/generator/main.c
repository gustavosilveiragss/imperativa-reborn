#include <stdio.h>
#include <shared/args.h>
#include <shared/AccountNode.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[INPUT_ARG], "r");
    AccountNode* head = accnode_new_from_text_file(input_file);
    fclose(input_file);

    FILE* output_file = fopen(argv[OUTPUT_ARG], "wb");
    accnode_dump_to_binary_file(head, output_file);

    long file_size = ftell(output_file);
    printf("Generated %ld bytes\n", file_size);

    fclose(output_file);

    return 0;
}
