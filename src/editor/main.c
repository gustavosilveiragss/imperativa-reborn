#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <shared/args.h>
#include <shared/Account.h>
#include <shared/AccountNode.h>
#include <shared/util.h>
#include <stdlib.h>
#include <string.h>

static void print_options(void) {
    printf("Options:\n");
    printf("1. Add new account\n");
    printf("2. Remove account\n");
    printf("3. Display account details\n");
    printf("4. Display all accounts\n");
    printf("5. Exit\n\n");
}

static void add_account(AccountNode* head) {
    Account acc = acc_new_from_input();
    if (accnode_find_by_id(head, acc.id) != NULL) {
        u_prompt("Account with id %zu already exists!", acc.id);
        return;
    }

    AccountNode* node = NULL;
    while (node == NULL) {
        u_prompt("Pick one id to insert after...");
        accnode_display(head);
        putchar('\n');
        node = accnode_find_by_id_from_input(head);
    }

    accnode_append(&node, acc);

    u_prompt("Account added successfully.");

    accnode_sort_by_id(&head);
    accnode_display(head);
}

static void delete_account(AccountNode** head) {
    assert(head);

    AccountNode* node = NULL;
    while (node == NULL) {
        u_prompt("Pick one id to delete...");
        accnode_display(*head);
        node = accnode_find_by_id_from_input(*head);
    };

    accnode_remove(head, node);

    if (node == *head)
        *head = node;

    u_prompt("Account deleted successfully.");

    accnode_sort_by_id(head);
    accnode_display(*head);
}

static void display_account_details(AccountNode* head) {
    u_prompt("Pick one id to display...");

    accnode_display(head);

    AccountNode* node = accnode_find_by_id_from_input(head);
    if (node == NULL) {
        u_prompt("Account not found!");
        return;
    }

    acc_display(&node->data);

    // extra newline for clarity
    putchar('\n');
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[INPUT_ARG], "rb");
    AccountNode* head = accnode_new_from_binary_file(input_file);
    fclose(input_file);

    accnode_sort_by_id(&head);

    // cli loop
    int choice = 0;
    do {
        print_options();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            add_account(head);
            break;
        }
        case 2: {
            delete_account(&head);
            break;
        }
        case 3: {
            display_account_details(head);
            break;
        }
        case 4: {
            accnode_display(head);
            break;
        }
        case 5: {
            goto done;
            break;
        }
        default: {
            printf("Invalid choice. Please try again.\n");
            break;
        }
        }
    } while (choice != 5);

done : {
    FILE* output_file = fopen(argv[OUTPUT_ARG], "wb+");
    accnode_dump_to_binary_file(head, output_file);
    fclose(output_file);

    return 0;
}
}
