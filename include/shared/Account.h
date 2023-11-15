#pragma once

#include <shared/types.h>

#define MAX_STRING_LENGTH 64
#define NUM_ACCOUNT_MEMBERS 7

typedef struct Account {
    usize id;
    char name[MAX_STRING_LENGTH];
    usize level;
    f32 balance;
    char email[MAX_STRING_LENGTH];
    char creationDate[MAX_STRING_LENGTH];
    char lastLoginDate[MAX_STRING_LENGTH];
} Account;

// Display an account's data
void displayAccount(Account* account);
