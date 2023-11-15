#pragma once

#include "shared/types.h"
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

// Insert a node before a given node
AccountNode* prepend(AccountNode** at, Account data);

// Insert a node after a given node
AccountNode* append(AccountNode** at, Account data);

// Get a node by Account id
AccountNode* getById(AccountNode* head, usize id);

// Display the doubly linked list from a given node
void displayList(AccountNode* at);

// Swap two nodes
void swap(AccountNode* rptr, AccountNode* lptr);

// Sort the given doubly linked list
void sort(AccountNode** accountNode);

// Delete a node from the list
void deleteNode(AccountNode** head, AccountNode* at);
