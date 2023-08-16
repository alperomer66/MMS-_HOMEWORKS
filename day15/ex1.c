#include <stdio.h>

void printFileContent(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
    
        char ch;
        while ((ch = getchar()) != EOF) {
            putchar(ch);
        }
    } else {
        for (int i = 1; i < argc; i++) {
            printFileContent(argv[i]);
        }
    }

    return 0;
}
