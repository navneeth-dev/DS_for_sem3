#include <stdio.h>

struct BankAccount {
    char accountName[100];
    int age;
};

void createAccount(struct BankAccount *account);
int withdrawAmount(int currentBalance);
int depositAmount(int currentBalance);

int main() {
    int choice, balance = 0;

    printf("Enter:\n1 to Create new account\n2 to Withdraw\n3 to Deposit\n4 to Check balance\n5 to Exit\n");

    while (choice != 5) {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    struct BankAccount userAccount;
                    createAccount(&userAccount);
                    break;
                }
            case 2:
                balance -= withdrawAmount(balance);
                break;
            case 3:
                balance += depositAmount(balance);
                break;
            case 4:
                printf("Balance is %d\n", balance);
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}

void createAccount(struct BankAccount *account) {
    printf("Enter account name: ");
    scanf("%s", account->accountName);

    printf("Enter age: ");
    scanf("%d", &account->age);
}

int withdrawAmount(int currentBalance) {
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    return amount;
}

int depositAmount(int currentBalance) {
    int amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);
    return amount;
}
