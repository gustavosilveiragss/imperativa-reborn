#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <shared/Account.h>

// Doubly linked list node
struct AccountNode {
    Account data;
    struct AccountNode* prev;
    struct AccountNode* next;
} typedef AccountNode;

// Create a new account node
AccountNode* createAccountNode(Account data);

// Insert a node at the beginning of the linked list
AccountNode* prepend(AccountNode** at, Account data);

// Insert a node at the end of the list
AccountNode* append(AccountNode** at, Account data);

// Display the doubly linked list
void displayList(AccountNode* at);

// Swap two nodes
void swap(AccountNode* rptr, AccountNode* lptr);

// Sort the given doubly linked list
void sort(AccountNode** accountNode);

// Delete a node from the list
void deleteNode(AccountNode** head, AccountNode* at);
