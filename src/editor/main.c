#include "shared/types.h"
#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <shared/args.h>
#include <shared/Account.h>
#include <shared/AccountNode.h>
#include <stdlib.h>
#include <string.h>

void printMenu() {
    printf("\nOptions:\n");
    printf("1. Add new account\n");
    printf("2. Remove account\n");
    printf("3. Display account details\n");
    printf("4. Display all accounts\n");
    printf("5. Exit\n\n");
}

AccountNode* readBinary(const char* input) {
    FILE* file = fopen(input, "rb");
    if (!file) {
        perror(strerror(errno));
        return NULL;
    }

    AccountNode* head = NULL;
    Account data = { 0 };
    while (fread(&data, sizeof(Account), 1, file) == 1) {
        if (head == NULL)
            head = createAccountNode(data);
        else
            append(&head, data);
    }

    fclose(file);

    // -------- MOCK DATA --------
    // (void)input;
    // Account acc1 = { 1, "John", 1000, 1000, "a@gmail.com", "1234567890", "1234567890" };
    // Account acc2 = { 2, "Mary", 1000, 1000, "a@gmail.com", "1234567890", "1234567890" };
    // Account acc3 = { 3, "Peter", 1000, 1000, "a@gmail.com", "1234567890", "1234567890" };
    // AccountNode* head = createAccountNode(acc1);
    // AccountNode* acc2Node = prepend(&head, acc2);
    // append(&acc2Node, acc3);

    return head;
}

AccountNode* getNodeByIdInput(AccountNode* at) {
    usize id = 0;
    printf("Enter id: ");
    scanf("%zu", &id);
    printf("\n");

    AccountNode* node = getById(at, id);

    if (node == NULL) {
        printf("Account not found\n");
        return NULL;
    }

    return node;
}

void addNewAccount(AccountNode* head) {
    Account* acc = malloc(sizeof(Account));

    if (acc == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter account details:\n");
    printf("Id: ");
    scanf("%zu", &acc->id);

    if (getById(head, acc->id) != NULL) {
        printf("Account with id %zu already exists\n", acc->id);
        return;
    }

    printf("Name: ");
    scanf("%s", acc->name);
    printf("Level: ");
    scanf("%zu", &acc->level);
    printf("Balance: ");
    scanf("%f", &acc->balance);
    printf("Email: ");
    scanf("%s", acc->email);
    printf("Creation Date (dd/mm/yyyy): ");
    scanf("%s", acc->creationDate);
    printf("Last Login Date (dd/mm/yyyy): ");
    scanf("%s", acc->lastLoginDate);

    printf("\nChoose an account's id to insert after\n");
    displayList(head);

    AccountNode* node = getNodeByIdInput(head);
    if (node == NULL)
        return;

    append(&node, *acc);

    printf("\nAccount added successfully:\n");
    sort(&head);
    displayList(head);
}

void deleteAccount(AccountNode* head) {
    printf("\nChoose an account's id to delete\n");
    displayList(head);

    AccountNode* node = getNodeByIdInput(head);
    if (node == NULL)
        return;

    deleteNode(&head, node);

    printf("\nAccount deleted successfully:\n");
    sort(&head);
    displayList(head);
}

void displayAccountDetails(AccountNode* head) {
    printf("\nChoose an id to display\n");
    displayList(head);

    AccountNode* node = getNodeByIdInput(head);
    if (node == NULL)
        return;

    displayAccount(&node->data);
}

void writeBinary(AccountNode* head, const char* output) {
    FILE* file = fopen(output, "wb");
    if (!file) {
        perror(strerror(errno));
        return;
    }

    for (AccountNode* curr = head; curr != NULL; curr = curr->next) {
        fwrite(&curr->data, sizeof(Account), 1, file);
    }

    fclose(file);
}

int main(int argc, char** argv) {
    assert(argc == 3);

    AccountNode* head = readBinary(argv[INPUT_ARG]);

    sort(&head);

    // CLI
    int choice = 0;
    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            // Add new account
            addNewAccount(head);
            break;
        }
        case 2: {
            // Remove account
            deleteAccount(head);
            break;
        }
        case 3: {
            // Display account details
            displayAccountDetails(head);
            break;
        }
        case 4: {
            // Display all accounts
            printf("\n");
            displayList(head);
            break;
        }
        case 5: {
            // Exit
            writeBinary(head, argv[OUTPUT_ARG]);
            free(head);
            exit(0);
            break;
        }
        default: {
            printf("Invalid choice. Please try again.\n");
            break;
        }
        }
    } while (choice != 5);

    // Write binary
    writeBinary(head, argv[OUTPUT_ARG]);
    free(head);

    return 0;
}
