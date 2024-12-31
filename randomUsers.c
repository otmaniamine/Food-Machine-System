#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_USERS 500000
#define USERNAME_LENGTH 10
#define PASSWORD_LENGTH 10

//random string of given length
void generateRandomString(char *str, int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length; i++) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    str[length] = '\0';
}

// Function to fill the users file
void generateUsersFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open file %s for writing.\n", filename);
        return;
    }

    char username[USERNAME_LENGTH + 1];
    char password[PASSWORD_LENGTH + 1];
    const char *roles[] = {"Admin", "Customer"};

    for (int i = 0; i < NUM_USERS; i++) {
        generateRandomString(username, USERNAME_LENGTH);
        generateRandomString(password, PASSWORD_LENGTH);
        const char *role = roles[rand() % 2]; // Randomly assign role

        fprintf(file, "%s %s %s\n", username, password, role);
    }

    fclose(file);
    printf("Successfully wrote %d users to %s.\n", NUM_USERS, filename);
}

int main() {
    srand(time(NULL)); 
    generateUsersFile("users.txt");
    return 0;
}
