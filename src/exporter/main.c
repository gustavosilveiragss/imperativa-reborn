#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <shared/args.h>
#include <shared/Account.h>
#include <shared/AccountNode.h>

int main(int argc, char** argv) {
    assert(argc == 3);

    FILE* input_file = fopen(argv[INPUT_ARG], "rb");
    if (!input_file) {
        perror(strerror(errno));
        return 1;
    }

    // calculate the amount of elements in the file based on its size
    // doing this allows us to perform a single allocation for the entire buffer

    fseek(input_file, 0, SEEK_END);
    const long file_size = ftell(input_file);
    assert(file_size % sizeof(Account) == 0);

    const size_t num_elements = file_size / sizeof(Account);

    Account* buffer = calloc(num_elements, sizeof(Account));

    // we seeked to the end so we have to make sure we go back to the start before reading it
    rewind(input_file);

    // read the whole thing into the buffer
    fread(buffer, sizeof(Account), num_elements, input_file);

    // create a linked list from it
    AccountNode* head = createAccountNode(buffer[0]);
    for (size_t i = 1; i < num_elements; i++)
        append(&head, buffer[i]);

    displayList(head);

    return 0;
}
