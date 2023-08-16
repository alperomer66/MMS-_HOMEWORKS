#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_a[2]; 
    int pipe_b[2];
    int pipe_c[2]; 

    if (pipe(pipe_a) == -1 || pipe(pipe_b) == -1 || pipe(pipe_c) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid_a, pid_b;
    pid_a = fork();

    if (pid_a < 0) {
        perror("Fork A failed");
        return 1;
    } else if (pid_a == 0) { 
        close(pipe_a[1]); 
        close(pipe_b[0]); 
        close(pipe_c[0]); 

        int numbers[100];
        int even_sum = 0;

        read(pipe_a[0], numbers, sizeof(numbers));

        for (int i = 0; i < 100; i++) {
            if (numbers[i] % 2 == 0) {
                even_sum += numbers[i];
            }
        }

        write(pipe_b[1], &even_sum, sizeof(even_sum));
        close(pipe_a[0]);
        close(pipe_b[1]);

        exit(0);
    } else { 
        pid_b = fork();

        if (pid_b < 0) {
            perror("Fork B failed");
            return 1;
        } else if (pid_b == 0) { 
            close(pipe_b[1]); 
            close(pipe_a[0]); 
            close(pipe_c[0]); 

            int even_sum;

            read(pipe_b[0], &even_sum, sizeof(even_sum));
            int even_sum_squared = even_sum * even_sum;

            write(pipe_c[1], &even_sum_squared, sizeof(even_sum_squared));
            close(pipe_b[0]);
            close(pipe_c[1]);

            exit(0);
        } else { 
            close(pipe_a[0]);
            close(pipe_b[0]); 
            close(pipe_b[1]); 
            close(pipe_c[1]); 

            int numbers[100];
            for (int i = 0; i < 100; i++) {
                numbers[i] = rand() % 100 + 1; 
            }

            write(pipe_a[1], numbers, sizeof(numbers));
            close(pipe_a[1]);

            int even_sum_squared;

            read(pipe_c[0], &even_sum_squared, sizeof(even_sum_squared));
            close(pipe_c[0]);

            printf("Sum of squares of even numbers: %d\n", even_sum_squared);

            wait(NULL);
            wait(NULL);

            return 0;
        }
    }//homework from Krasi;
}//end of main
