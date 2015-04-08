#include <stdio.h>


int factorial(int n) {
    int result = 1;

    /* Keep looping while n is larger than 0 */
    while (n > 0) {
        result *= n; /* shorthand for "result = result * n" */
        n--;
    }
    
    return result;
}

int main() {

    printf("10! = 3628800\n");
    int result = factorial(10);
    printf("Our function says 10! = %d\n", result);
    if (result == 3628800)
        printf("Yay!\n");
    else
        printf("Boo. Hiss.\n");
    
    return 0;
}
