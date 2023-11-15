#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <shared/args.h>
#include <shared/Account.h>
#include <shared/AccountNode.h>

int main(int argc, char** argv) {
    assert(argc == 3);
    
    // Read binary
    // const char* input = argv[INPUT_ARG_INDEX];
    // FILE* file = fopen(input, "w+");
    // if (!file) {
    //     perror(strerror(errno));
    //     return 1;
    // }

    // Write data into a linked list

    // -------- MOCK DATA --------
    Account acc1 = { 1, "John", 1000, 1000, "a@gmail.com", "1234567890", "1234567890" };
    Account acc2 = { 2, "Mary", 1000, 1000, "a@gmail.com", "1234567890", "1234567890" };
    Account acc3 = { 3, "Peter", 1000, 1000, "a@gmail.com", "1234567890", "1234567890" };
    AccountNode* head = createAccountNode(acc1);
    AccountNode* acc2Node = append(&head, acc2);
    append(&acc2Node, acc3);

    // Write data into an output txt file

    const char* output = argv[OUTPUT_ARG_INDEX];
    FILE* outputFile = fopen(output, "w");
    if (!outputFile) {
        perror(strerror(errno));
        return 1;
    }

    for (AccountNode* curr = head; curr != NULL; curr = curr->next) {
        fprintf(outputFile, "%zu %s %zu %f %s %s %s\n",
               curr->data.id,
               curr->data.name,
               curr->data.level,
               curr->data.balance,
               curr->data.email,
               curr->data.creationDate,
               curr->data.lastLoginDate);
    }

    fclose(outputFile);

    return 0;
}
