#include <stdio.h>
#include <shared/args.h>
#include <shared/Account.h>
#include <shared/AccountNode.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[INPUT_ARG], "rb");
    AccountNode* head = accnode_new_from_binary_file(input_file);
    fclose(input_file);

    accnode_display(head);

    FILE* output_file = fopen(argv[OUTPUT_ARG], "w");
    accnode_dump_to_text_file(head, output_file);
    fclose(output_file);

    return 0;
}
