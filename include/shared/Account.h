#pragma once

#include <shared/types.h>

typedef struct {
    usize id;
    char name[64];
    usize level;
    f32 balance;
    char email[64];
    char creationDate[64];
    char lastLoginDate[64];
} Account;

// Display an account's data
void displayAccount(Account* account);
