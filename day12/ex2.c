
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(double *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, m, p;

    printf("Enter the initial size of the array (n): ");
    scanf("%d", &n);

    
    double *array = (double *)malloc(n * sizeof(double));
    if (array == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        array[i] = (double)rand() / RAND_MAX;
    }

    printf("Enter the number of elements to add (m): ");
    scanf("%d", &m);

    double *temp = (double *)realloc(array, (n + m) * sizeof(double));
    if (temp == NULL) {
        printf("Memory reallocation error.\n");
        free(array);
        return 1;
    }
    array = temp;

    
    for (int i = n; i < n + m; i++) {
        array[i] = 1.0 + (double)rand() / RAND_MAX;
    }

    printf("Enter the number of elements to add (p): ");
    scanf("%d", &p);

    
    temp = (double *)realloc(array, (n + m + p) * sizeof(double));
    if (temp == NULL) {
        printf("Memory reallocation error.\n");
        free(array);
        return 1;
    }
    array = temp;

    
    for (int i = n + m; i < n + m + p; i++) {
        array[i] = 2.0 + (double)rand() / RAND_MAX;
    }

    
    printf("Array elements:\n");
    print_array(array, n + m + p);

    
    free(array);

    return 0;
}
