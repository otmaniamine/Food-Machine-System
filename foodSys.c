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
void loadUsers(); // LADJOUZI ADAM 
void saveUsers(); // LADJOUZI ADAM
void registerUser(); // akram
bool loginUser(char *role); // akram
void loadProducts(); // Person 3
void saveProducts(); // Person 3
void addProduct(); // Person 4
void viewProducts(); // Person 4
void updateProduct(); // IDOUI
void deleteProduct(); // IDOUI
void customerMenu(); // wassim.
void purchaseProduct(); // wassim.
void adminMenu(); // Person 7
void clearBuffer(); // Person 8

// Utility Functions
void clearBuffer() {
    while (getchar() != '\n');
}

void loadUsers() {
    FILE *file = fopen("users.txt", "r");
    if (file) {
        userCount = 0;
        while (fscanf(file, "%49s %49s %9s", users[userCount].username, users[userCount].password, users[userCount].role) == 3) {
            userCount++;
            if (userCount >= MAX_USERS) break;
        }
        fclose(file);
    } else {
        printf("Error: Unable to open users.txt\n");
    }
}

void saveUsers() {
    FILE *file = fopen("users.txt", "w");
    if (file) {
        for (int i = 0; i < userCount; i++) {
            fprintf(file, "%s %s %s\n", users[i].username, users[i].password, users[i].role);
        }
        fclose(file);
    } else {
        printf("Error: Unable to save users to users.txt\n");
    }
}

void loadProducts() {
    FILE *file = fopen("products.txt", "r");
    if (file) {
        productCount = 0;
        while (fscanf(file, "%d %49s %f %d", &products[productCount].id, products[productCount].name, &products[productCount].price, &products[productCount].quantity) == 4) {
            productCount++;
            if (productCount >= MAX_PRODUCTS) break;
        }
        fclose(file);
    } else {
        printf("Error: Unable to open products.txt\n");
    }
}

void saveProducts() {
    FILE *file = fopen("products.txt", "w");
    if (file) {
        for (int i = 0; i < productCount; i++) {
            fprintf(file, "%d %s %.2f %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
        }
        fclose(file);
    } else {
        printf("Error: Unable to save products to products.txt\n");
    }
}
void registerUser() {
    char username[50], password[50], role[10];
    printf("Enter username: ");
    scanf("%49s", username);

    // Check for unique username
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Username already exists!\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%49s", password);
    printf("Enter role (Admin/Customer): ");
    scanf("%9s", role);

    // Add new user
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    strcpy(users[userCount].role, role);
    userCount++;

    saveUsers();
    printf("User registered successfully!\n");
}

bool loginUser(char *role) {
    char username[50], password[50];
    printf("Enter username: ");
    scanf("%49s", username);
    printf("Enter password: ");
    scanf("%49s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            strcpy(role, users[i].role);
            return true;
        }
    }
    printf("Invalid credentials!\n");
    return false;
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
