#include <stdio.h>

void generateProducts(long count) {
    FILE *file = fopen("products.txt", "w");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    for (long i = 0; i < count; i++) {
        long id = i + 1;
        float price = (id * 10.5);
        int quantity = (i % 100) + 1;
        fprintf(file, "%ld Product%ld %.2f %d\n", id, id, price, quantity);

        if (id % 100000 == 0) {
            printf("%ld products generated...\n", id);
        }
    }

    fclose(file);
    printf("Database of %ld products has been saved to 'products.txt'.\n", count);
}

int main() {
    long count = 500000;
    printf("Generating %ld products...\n", count);
    generateProducts(count);
    return 0;
}
