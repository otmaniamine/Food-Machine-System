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
void loadUsers(); // Person 1
void saveUsers(); // Person 1
void registerUser(); // Person 2
bool loginUser(char *role); // Person 2
void loadProducts(); // Person 3
void saveProducts(); // Person 3
void addProduct(); // Person 4
void viewProducts(); // Person 4
void updateProduct(); // Person 5
void deleteProduct(); // Person 5
void customerMenu(); // Person 6
void purchaseProduct(); // Person 6
void adminMenu(); // Person 7
void clearBuffer(); // Person 8

// Placeholder Functions
void loadUsers() {
    // Implement user loading from "users.txt"
}

void saveUsers() {
    //  Implement user saving to "users.txt"
}

void registerUser() {
    //  Implement user registration
}

bool loginUser(char *role) {
    //  Implement user login
    return false; // Temporary return value
}

void loadProducts() {
    // Implement product loading from "products.txt"
}

void saveProducts() {
    // Implement product saving to "products.txt"
}

void addProduct() {
    //  Implement adding a product
}

void viewProducts() {
    //  Implement viewing products
}

void updateProduct() {
    //  Implement updating a product
}

void deleteProduct() {
    //  Implement deleting a product
}

void purchaseProduct() {
    // Implement purchasing a product
}

void customerMenu() {
    //  Implement the customer menu
}

void adminMenu() {
    //  Implement the admin menu
}

void clearBuffer() {
    //  Implement clearing the input buffer
}

int main() {
    char role[10];
    int choice;

    printf("Loading users and products...\n");
    loadUsers();
    loadProducts();

    do {
        printf("\n--- Food Machine Management System ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser(role)) {
                    if (strcmp(role, "Admin") == 0) {
                        adminMenu();
                    } else {
                        customerMenu();
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}