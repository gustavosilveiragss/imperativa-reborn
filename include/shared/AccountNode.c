#include "AccountNode.h"
#include "Account.h"

AccountNode* createAccountNode(Account data) {
    AccountNode* newNode = malloc(sizeof(AccountNode));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert a node at the beginning of the linked list
AccountNode* prepend(AccountNode** at, Account data) {
    AccountNode* newNode = createAccountNode(data);

    if (*at == NULL) {
        *at = newNode;
        return newNode;
    }

    newNode->data = data;
    newNode->prev = (*at)->prev;
    (*at)->prev = newNode;
    newNode->next = *at;
    if (newNode->prev != NULL)
        newNode->prev->next = newNode;
    *at = newNode;
    
    return newNode;
}

// Insert a node at the end of the list
AccountNode* append(AccountNode** at, Account data) {
    AccountNode* newNode = createAccountNode(data);

    if (*at == NULL) {
        *at = newNode;
        return newNode;
    }
 
    newNode->next = (*at)->next;
    (*at)->next = newNode;
    newNode->prev = *at;
    
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
    
    return newNode;
}

// Display the doubly linked list
void displayList(AccountNode* at) {
    if (at == NULL) {
        printf("List is empty\n");
        return;
    }
    for (AccountNode* accNode = at; accNode != NULL; accNode = accNode->next) {
        printf("%zu %s\n", accNode->data.id, accNode->data.name);
    }
}

// Swap two nodes
void swap(AccountNode* rtpr, AccountNode* lptr) {
    Account temp = rtpr->data;
    rtpr->data = lptr->data;
    lptr->data = temp;
}

// Sort the given doubly linked list
void sort(AccountNode** accountNode) {
    bool swapped;
    AccountNode* rptr = NULL;
    AccountNode* lptr = NULL;

    if (*accountNode == NULL)
        return;

    do {
        swapped = false;
        rptr = *accountNode;

        while (rptr->next != lptr) {
            if (rptr->data.id > rptr->next->data.id) {
                swap(rptr, rptr->next);
                swapped = true;
            }
            rptr = rptr->next;
        }

        lptr = rptr;
    } while (swapped);
}

// Delete a node from the list
void deleteNode(AccountNode* at) {
    if (at == NULL) {
        printf("Node to delete is NULL\n");
        return;
    }

    if (at->prev == NULL && at->next != NULL) {
        at->next->prev = NULL;
    } else {
        at->prev->next = at->next;

        if (at->next != NULL)
            at->next->prev = at->prev;
    }

    free(at);
}
