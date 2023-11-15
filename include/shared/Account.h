#pragma once

#include <shared/types.h>

typedef struct {
    usize id;
    const char* name;
    usize level;
    f32 balance;
    const char* email;
    const char* creationDate;
    const char* lastLoginDate;
} Account;
