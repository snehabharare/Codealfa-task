#include <stdio.h>

// Structure
struct Account {
    float balance;
};

// Function declarations
void deposit(struct Account *a);
void withdrawAmount(struct Account *a);
void checkBalance(struct Account a);

int main() {
    struct Account acc;
    int choice;

    // Initial balance
    acc.balance = 0;

    while (1) {
        printf("\n=== Simple Banking System ===\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            deposit(&acc);
            break;
        case 2:
            withdrawAmount(&acc);
            break;
        case 3:
            checkBalance(acc);
            break;
        case 4:
            printf("Thank you! Bye...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

// Deposit function
void deposit(struct Account *a) {
    float amt;
    printf("Enter amount to deposit: ");
    scanf("%f", &amt);
    a->balance = a->balance + amt;
    printf("Deposited successfully!\n");
}

// Withdraw function
void withdrawAmount(struct Account *a) {
    float amt;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amt);

    if (amt > a->balance) {
        printf("Insufficient balance!\n");
    } else {
        a->balance = a->balance - amt;
        printf("Withdraw successful!\n");
    }
}

// Check balance
void checkBalance(struct Account a) {
    printf("Current Balance: %.2f\n", a.balance);
}