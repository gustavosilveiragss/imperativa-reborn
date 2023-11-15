#include "shared/Account.h"
#include <stdio.h>

// Display an account's data
void displayAccount(Account* acc) {
    printf("[%zu] %s %zu %.2f %s %s %s\n",
           acc->id,
           acc->name,
           acc->level,
           acc->balance,
           acc->email,
           acc->creationDate,
           acc->lastLoginDate);
}
