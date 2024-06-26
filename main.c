#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_file(const char *file_name) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Could not create file: %s\n", file_name);
        return;
    }
    printf("File created: %s\n", file_name);
    fclose(file);
}

void read_file(const char *file_name) {
    char buffer[1000];
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("File not found: %s\n", file_name);
        return;
    }
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

void write_file(const char *file_name, const char *content) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Could not open file: %s\n", file_name);
        return;
    }
    fprintf(file, "%s", content);
    printf("Written to file: %s\n", file_name);
    fclose(file);
}

int main() {
    create_file("test.txt");
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user input

    write_file("test.txt", "Ficheiro foi criado com sucesso!");
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user input

    printf("File content:\n");
    read_file("test.txt");
    printf("\nPress Enter to continue...\n");
    getchar(); // Wait for user input

    return 0;
}
