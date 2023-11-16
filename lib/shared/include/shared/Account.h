#pragma once

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 64

typedef struct Account {
    size_t id;
    char name[MAX_STRING_LENGTH];
    size_t level;
    float balance;
    char email[MAX_STRING_LENGTH];
    char creation_date[MAX_STRING_LENGTH];
    char last_login_date[MAX_STRING_LENGTH];
} Account;

// Create a new account from user input
Account acc_new_from_input(void);

// Create a new account from a binary stream
// returns false on failure
bool acc_new_from_binary_file(Account*, FILE*);

// Dump an account's data into a binary stream
void acc_dump_to_binary_file(const Account*, FILE*);

// Create a new account from a textual stream
// returns false on failure
bool acc_new_from_text_file(Account*, FILE*);

// Dump an account's data into a textual stream
void acc_dump_to_text_file(const Account*, FILE*);

// Display an account's data
void acc_display(const Account* account);
