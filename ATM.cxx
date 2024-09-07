#include <stdio.h>

int main() {
    int balance = 2000;  // Initial balance
    int choice;
    int amount;

    while (1) {
        // Display options
        printf("\n********* ATM *********\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Check Balance
                printf("Your current balance is: %d\n", balance);
                break;

            case 2:  // Deposit
                printf("Enter amount to deposit: ");
                scanf("%d", &amount);
                balance += amount;
                printf("You have deposited %d. Your new balance is: %d\n", amount, balance);
                break;

            case 3:  // Withdraw
                printf("Enter amount to withdraw: ");
                scanf("%d", &amount);
                if (amount > balance) {
                    printf("Insufficient balance! Your current balance is: %d\n", balance);
                } else {
                    balance -= amount;
                    printf("You have withdrawn %d. Your new balance is: %d\n", amount, balance);
                }
                break;

            case 4:  // Exit
                printf("Thank you for using the ATM. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;qa
}
