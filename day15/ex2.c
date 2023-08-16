#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <arg1> <arg2> ... <argN>\n", argv[0]);
        return 1;
    }


    qsort(argv + 1, argc - 1, sizeof(char *), compareStrings);


    char filename[100];
    printf("Enter the filename to save sorted arguments: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        printf("Error: File '%s' already exists.\n", filename);
        fclose(file);
        return 1;
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file '%s'\n", filename);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        fprintf(file, "%s\n", argv[i]);
    }

    fclose(file);
    printf("Sorted arguments have been written to '%s'\n", filename);

    return 0;
}
