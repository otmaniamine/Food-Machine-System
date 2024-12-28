#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 100
#define MAX_PRODUCTS 100

// Structures
typedef struct {
    char username[50];
    char password[50];
    char role[10]; // "Admin" or "Customer"
} User;

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// Global Variables
User users[MAX_USERS];
Product products[MAX_PRODUCTS];
int userCount = 0;
int productCount = 0;

// Function Prototypes
void loadUsers();
void saveUsers();
void loadProducts();
void saveProducts();
void registerUser();
bool loginUser(char *role);
void adminMenu();
void customerMenu();
void addProduct();
void viewProducts();
void updateProduct();
void deleteProduct();
void purchaseProduct();

// Utility Functions
void clearBuffer() {
    while (getchar() != '\n');
}

// Main function to coordinate user roles and menus
int main() {
    loadUsers();
    loadProducts();

    int choice;
    char role[10];

    do {
        printf("\n--- Food Machine Management System ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: registerUser(); break;
            case 2: if (loginUser(role)) {
                        if (strcmp(role, "Admin") == 0) {
                            adminMenu();
                        } else {
                            customerMenu();
                        }
                    } break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}

// Functions to be implemented by the team
// Person 1: void loadUsers();
// Person 1: void saveUsers();

// Person 2: void loadProducts();
// Person 2: void saveProducts();

// Person 3: void registerUser();

// Person 4: bool loginUser(char *role);

// Person 5: void adminMenu();

// Person 6: void customerMenu();

// Person 7: void addProduct();
// Person 7: void viewProducts();

// Person 8: void updateProduct();

// Person 9: void deleteProduct();

// Person 10: void purchaseProduct();
