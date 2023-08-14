#include <stdio.h>
#include <stdlib.h>

int isPositive(int a) {
    return a > 0;
}

int addOne(int a) {
    return a + 1;
}

void filter_and_map(
    const int arr[],
    size_t n,
    int (*filter_f)(int),
    int (*map_f)(int),
    int dest[],
    size_t* dest_cnt
) {
    if (dest == NULL) {
    
        *dest_cnt = 0;
        for (size_t i = 0; i < n; i++) {
            if (filter_f(arr[i])) {
                (*dest_cnt)++;
            }
        }
        return;
    }

    size_t count = 0;
    for (size_t i = 0; i < n; i++) {
        if (filter_f(arr[i])) {
            dest[count++] = map_f(arr[i]);
        }
    }
    *dest_cnt = count;
}

int main() {
    int arr[8] = {1, 2, 3, 4, -1, -2, 11, -100};
    int dest[10];
    size_t new_size;

    filter_and_map(arr, 8, isPositive, addOne, dest, &new_size);

    printf("Mapped and filtered array:\n");
    for (size_t i = 0; i < new_size; i++) {
        printf("%d\n", dest[i]);
    }

    return 0;
}
