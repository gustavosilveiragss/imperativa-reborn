#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <shared/AccountNode.h>
#include <shared/Account.h>

AccountNode* accnode_new(Account data) {
    AccountNode* new_node = malloc(sizeof(AccountNode));
    assert(new_node);

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

AccountNode* accnode_append(AccountNode** node, Account data) {
    assert(node);

    AccountNode* new_node = accnode_new(data);
    if (*node == NULL) {
        *node = new_node;
        return new_node;
    }

    new_node->next = (*node)->next;
    (*node)->next = new_node;
    new_node->prev = *node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;

    return new_node;
}

AccountNode* accnode_find_by_id(AccountNode* head, size_t id) {
    assert(head);

    for (AccountNode* curr = head; curr != NULL; curr = curr->next)
        if (curr->data.id == id)
            return curr;

    return NULL;
}

AccountNode* accnode_find_by_id_from_input(AccountNode* node) {
    assert(node);

    size_t id = 0;
    printf("Enter id: ");
    scanf("%zu", &id);

    return accnode_find_by_id(node, id);
}

void accnode_display(AccountNode* node) {
    assert(node);

    for (AccountNode* curr = node; curr != NULL; curr = curr->next)
        acc_display(&curr->data);

    // extra newline for clarity
    putchar('\n');
}

static void swap(AccountNode* rnode, AccountNode* lnode) {
    assert(rnode && lnode);

    Account temp = rnode->data;
    rnode->data = lnode->data;
    lnode->data = temp;
}

void accnode_sort_by_id(AccountNode** accountNode) {
    assert(accountNode != NULL && *accountNode != NULL);

    bool swapped = false;
    AccountNode* rnode = NULL;
    AccountNode* lnode = NULL;
    do {
        swapped = false;
        rnode = *accountNode;

        while (rnode->next != lnode) {
            if (rnode->data.id > rnode->next->data.id) {
                swap(rnode, rnode->next);
                swapped = true;
            }
            rnode = rnode->next;
        }

        lnode = rnode;
    } while (swapped);
}

void accnode_remove(AccountNode** head, AccountNode* node) {
    assert(head != NULL && *head != NULL && node != NULL);

    if (*head == node)
        *head = node->next;

    if (node->next != NULL)
        node->next->prev = node->prev;

    if (node->prev != NULL)
        node->prev->next = node->next;

    free(node);
    return;
}

AccountNode* accnode_new_from_binary_file(FILE* file) {
    assert(file);

    Account data = { 0 };
    // there must be node least one account in the file so that head can be created
    bool success = acc_new_from_binary_file(&data, file);
    (void)success; // to avoid -Wunused-variable on release
    assert(success);

    AccountNode* head = accnode_new(data);

    while (acc_new_from_binary_file(&data, file))
        accnode_append(&head, data);

    return head;
}

void accnode_dump_to_binary_file(AccountNode* node, FILE* file) {
    assert(node && file);

    for (AccountNode* curr = node; curr != NULL; curr = curr->next)
        acc_dump_to_binary_file(&curr->data, file);
}

AccountNode* accnode_new_from_text_file(FILE* file) {
    assert(file);

    Account data = { 0 };
    // there must be node least one account in the file so that head can be created
    bool success = acc_new_from_text_file(&data, file);
    (void)success; // to avoid -Wunused-variable on release
    assert(success);

    AccountNode* head = accnode_new(data);

    while (acc_new_from_text_file(&data, file))
        accnode_append(&head, data);

    return head;
}

void accnode_dump_to_text_file(AccountNode* node, FILE* file) {
    assert(node && file);

    for (AccountNode* curr = node; curr != NULL; curr = curr->next)
        acc_dump_to_text_file(&curr->data, file);
}
