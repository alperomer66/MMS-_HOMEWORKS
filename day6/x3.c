#include <stdio.h>

int main(){



double cbrt_custom(double x) {
    if (x == 0.0) {
        return 0.0;
    }

    double guess = x;
    double epsilon = 0.0001;  

    while (1) {
        double nextGuess = (2.0 * guess + x / (guess * guess)) / 3.0;

        if (fabs(nextGuess - guess) < epsilon) {
            return nextGuess;
        }

        guess = nextGuess;
    }
}
}//end of main