#pragma once

#include <shared/types.h>

typedef struct {
    usize id;
    char* name;
    usize level;
    f32 balance;
    char* email;
    char* creationDate;
    char* lastLoginDate;
} Account;

// Display an account's data
void displayAccount(Account* account);
