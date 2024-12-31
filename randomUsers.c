<<<<<<< HEAD
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
=======

#include <stdio.h>

int main() {
    FILE *file;
    char user_data[5000][50];
    char role[10];

    for (int i = 0; i < 5000; i++) {

        if (i % 2 != 0) {
            snprintf(role, sizeof(role), "Customer");
        } else {
            snprintf(role, sizeof(role), "Admin");
        }

        snprintf(user_data[i], sizeof(user_data[i]), "user%d pass%d %s\n", i, i, role);
    }

    file = fopen("users.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < 5000; i++) {
        fputs(user_data[i], file);
    }

    fclose(file);

    printf("User data has been saved to 'users.txt'.\n");

>>>>>>> 76a4054984aa26375897ff8474dbdbdec077b413
    return 0;
}
