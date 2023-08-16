#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    pid_t child1, child2;
    child1 = fork();

    if (child1 == 0) {
        close(pipe1[1]);
        close(pipe2[0]);

        int myValue;
        read(pipe1[0], &myValue, sizeof(int));

        myValue *= 3;
        write(pipe2[1], &myValue, sizeof(int));

        close(pipe1[0]);
        close(pipe2[1]);

        exit(0);
    } else {
        child2 = fork();

        if (child2 == 0) {
            close(pipe1[1]);
            close(pipe2[1]);

            int result;
            read(pipe2[0], &result, sizeof(int));

            if (result % 2 == 0) {
                result *= result;
            } else {
                result /= 2;
            }

            write(pipe1[1], &result, sizeof(int));

            close(pipe1[1]);
            close(pipe2[0]);

            exit(0);
        } else {
            close(pipe1[0]);
            close(pipe1[1]);
            close(pipe2[0]);
            close(pipe2[1]);

            int myValue = 7;
            write(pipe1[1], &myValue, sizeof(int));

            int finalResult;
            read(pipe1[0], &finalResult, sizeof(int));

            printf("Final result: %d\n", finalResult);

            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}
//from krasi 