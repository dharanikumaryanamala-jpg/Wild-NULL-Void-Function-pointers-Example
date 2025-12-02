#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} BankAccount;

void deposit(BankAccount *acc, double amount) {
    acc->balance += amount;
    printf("Deposited %.2f into account %d. New Balance: %.2f\n",
           amount, acc->accountNumber, acc->balance);
}

void withdraw(BankAccount *acc, double amount) {
    if (acc->balance >= amount) {
        acc->balance -= amount;
        printf("Withdrew %.2f from account %d. New Balance: %.2f\n",
               amount, acc->accountNumber, acc->balance);
    } else {
        printf("Insufficient balance in account %d!\n", acc->accountNumber);
    }
}

void checkBalance(BankAccount *acc, double dummy) {
    printf("Account %d Balance: %.2f\n", acc->accountNumber, acc->balance);
}

int main() {
    printf("=== Pointers in C with Real-Time Sector Examples ===\n\n");

    // Wild Pointer
    int *wildPtr;
    printf("Wild Pointer Example:\n");
    printf("Nurse has a random patient file - wildPtr points to unknown memory\n");

    // NULL Pointer
    int *nullPtr = NULL;
    printf("\nNULL Pointer Example :\n");
    if (nullPtr == NULL) {
        printf("Teacher has a roll number card but it points to no student.\n");
    }

    // Void Pointer (E-Commerce)
    printf("\nVoid Pointer Example :\n");
    int productId = 101;
    double productPrice = 299.99;
    char productName[20] = "Laptop";

    void *vptr; // universal pointer

    vptr = &productId;
    printf("Void pointer pointing to int Product ID: %d\n", *(int*)vptr);

    vptr = &productPrice;
    printf("Void pointer pointing to double Price: %.2f\n", *(double*)vptr);

    vptr = productName;
    printf("Void pointer pointing to string Name: %s\n", (char*)vptr);
    printf("Function pointer Example :\n");
    //Function Pointer
    BankAccount acc1;
    acc1.accountNumber = 501;
    strcpy(acc1.name, "Dharani");
    acc1.balance = 10000.0;

    // Function pointer declaration
    void (*bankOperation)(BankAccount*, double);

    // Deposit using function pointer
    bankOperation = deposit;
    bankOperation(&acc1, 2000);

    // Withdraw using function pointer
    bankOperation = withdraw;
    bankOperation(&acc1, 5000);

    // Check balance using function pointer
    bankOperation = checkBalance;
    bankOperation(&acc1, 0);
    return 0;
}


