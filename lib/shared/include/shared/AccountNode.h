#pragma once

#include <stdio.h>
#include <shared/Account.h>

// A doubly linked list data-structure that holds Accounts
struct AccountNode {
    Account data;
    struct AccountNode* prev;
    struct AccountNode* next;
} typedef AccountNode;

// Create a new account node
AccountNode* accnode_new(Account data);

// Create a list from a binary stream
AccountNode* accnode_new_from_binary_file(FILE*);

// Dump the list into a binary stream starting from a given node
void accnode_dump_to_binary_file(const AccountNode*, FILE*);

// Make a new list from a textual stream
AccountNode* accnode_new_from_text_file(FILE*);

// Dump the list into a text stream starting from a given node
void accnode_dump_to_text_file(const AccountNode*, FILE*);

// Display the linked list starting from a given node
void accnode_display(const AccountNode*);

// Insert a node after a given node
AccountNode* accnode_append(AccountNode**, Account data);

// Delete a node from the list
void accnode_remove(AccountNode** head, AccountNode*);

// Try finding a node by Account id starting from a given node
AccountNode* accnode_find_by_id(AccountNode*, size_t id);

// Try finding a node by Account id from user input starting from a given node
AccountNode* accnode_find_by_id_from_input(AccountNode*);

// Sort the given doubly linked list by the Account id starting from a given node
void accnode_sort_by_id(AccountNode**);
