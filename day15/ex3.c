#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[16];
    double avg_grade;
};

int main() {
    FILE *file = fopen("students.bin", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    struct Student maxStudent;
    fread(&maxStudent, sizeof(struct Student), 1, file);

    struct Student currentStudent;
    while (fread(&currentStudent, sizeof(struct Student), 1, file) == 1) {
        if (currentStudent.avg_grade > maxStudent.avg_grade) {
            memcpy(&maxStudent, &currentStudent, sizeof(struct Student));
        }
    }

    fclose(file);

    printf("Student with the highest average grade:\n");
    printf("Name: %s\n", maxStudent.name);
    printf("Average Grade: %.2lf\n", maxStudent.avg_grade);

    return 0;
}
