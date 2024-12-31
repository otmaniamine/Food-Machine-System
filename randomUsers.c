
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

    return 0;
}
