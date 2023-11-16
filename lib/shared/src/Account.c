#include <shared/Account.h>
#include <assert.h>

Account acc_new_from_input(void) {
    Account acc;

    printf("Id: ");
    scanf("%zu", &acc.id);

    printf("Name: ");
    scanf("%s", acc.name);
    printf("Level: ");
    scanf("%zu", &acc.level);
    printf("Balance: ");
    scanf("%f", &acc.balance);
    printf("Email: ");
    scanf("%s", acc.email);
    printf("Creation Date (dd/mm/yyyy): ");
    scanf("%s", acc.creation_date);
    printf("Last Login Date (dd/mm/yyyy): ");
    scanf("%s", acc.last_login_date);

    return acc;
}

bool acc_new_from_binary_file(Account* account, FILE* file) {
    assert(account && file);
    return fread(account, sizeof(Account), 1, file) == 1;
}

void acc_dump_to_binary_file(const Account* account, FILE* file) {
    assert(account && file);
    fwrite(account, sizeof(Account), 1, file);
}

bool acc_new_from_text_file(Account* account, FILE* file) {
    assert(account && file);
    return fscanf(file,
                  "%zu %s %zu %f %s %s %s\n",
                  &account->id,
                  account->name,
                  &account->level,
                  &account->balance,
                  account->email,
                  account->creation_date,
                  account->last_login_date) == 7;
}

void acc_dump_to_text_file(const Account* account, FILE* file) {
    fprintf(file,
            "%zu %s %zu %.2f %s %s %s\n",
            account->id,
            account->name,
            account->level,
            account->balance,
            account->email,
            account->creation_date,
            account->last_login_date);
}

void acc_display(const Account* acc) {
    acc_dump_to_text_file(acc, stdout);
}
