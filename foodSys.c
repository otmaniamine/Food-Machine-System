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
void registerUser(); // akram
bool loginUser(char *role); // akram
void loadProducts(); // Person 3
void saveProducts(); // Person 3
void addProduct(); // Person 4
void viewProducts(); // Person 4
void updateProduct(); // Person 5
void deleteProduct(); // Person 5
void customerMenu(); // wassim
void purchaseProduct(); // wassim
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
    User newUser, users[100];
    int userCount = 0;
    loadUsers(users, &userCount);
    
    printf("Enter username: ");
    scanf("%s", newUser.username);

    // Check for unique username
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Please try a different username.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", newUser.password);
    printf("Enter role (Admin/Customer): ");
    scanf("%s", newUser.role);

    users[userCount++] = newUser;
    saveUsers(users, userCount);
    
    printf("Registration successful!\n");
}

bool loginUser(char *role) {
    //  Implement user login
      User users[100];
    int userCount = 0;
    loadUsers(users, &userCount);

    char username[30], password[30];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            strcpy(role, users[i].role);
            printf("Login successful! Welcome, %s.\n", username);
            return 1;
        }
    }
    printf("Invalid username or password. Please try again.\n");
    return 0;
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
    int id, quantity;
    printf("Enter product ID to purchase: ");
    scanf("%d", &id);
    printf("Enter quantity to purchase: ");
    scanf("%d", &quantity);

    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            if (products[i].quantity >= quantity) {
                products[i].quantity -= quantity;
                saveProducts();
                printf("Purchase successful!\n");
            } else {
                printf("Insufficient stock!\n");
            }
            return;
        }
    }
    printf("Product not found!\n");
}

void customerMenu() {
    int choice;
    do {
        printf("\n--- Customer Menu ---\n");
        printf("1. View Products\n");
        printf("2. Purchase Product\n");
        printf("3. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: viewProducts(); break;
            case 2: purchaseProduct(); break;
            case 3: printf("Logging out...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 3);
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
