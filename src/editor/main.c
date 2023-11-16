#include <stdio.h>
#include <shared/args.h>
#include <shared/Account.h>
#include <shared/AccountNode.h>
#include <shared/util.h>

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
        // try again
        add_account(head);
        return;
    }

    accnode_append(&head, acc);

    u_prompt("Account added successfully.");

    accnode_sort_by_id(&head);
    accnode_display(head);
}

static void delete_account(AccountNode** head) {
    u_prompt("Pick one id to delete...");
    accnode_display(*head);

    AccountNode* node = accnode_find_by_id_from_input(*head);
    if (node == NULL) {
        u_prompt("Account not found!");
        // try again
        delete_account(head);
        return;
    }

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
        // try again
        accnode_display(head);
        return;
    }

    acc_display(&node->data);
    // extra newline for clarity
    putchar('\n');
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
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
    // editor's input is the same as it's ouput :)
    FILE* output_file = fopen(argv[INPUT_ARG], "wb+");
    accnode_dump_to_binary_file(head, output_file);
    fclose(output_file);

    return 0;
}
}
