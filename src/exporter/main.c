#include <stdio.h>
#include <shared/Account.h>
#include <shared/AccountNode.h>

int main() {
    // create three accounts
    Account acc1 = { 1, "John", 1000, 1000, "a@gmail.com", "1234567890", "1234567890" };
    Account acc2 = { 2, "Mary", 1000, 1000, "a@gmail.com", "1234567890", "1234567890" };
    Account acc3 = { 3, "Peter", 1000, 1000, "a@gmail.com", "1234567890", "1234567890" };

    // create a doubly linked list
    AccountNode* head = createAccountNode(acc1);
    AccountNode* acc2Node = prepend(&head, acc2);
    append(&acc2Node, acc3);

    // display the list
    displayList(head);

    printf("\n");

    // sort list
    sort(&head);

    // display the list
    displayList(head);

    // delete second node
    deleteNode(&head, acc2Node);

    printf("\n");

    // display the list
    displayList(head);

    return 0;
}
