#include <stdio.h>


int factorial(int n) {
	int result = n;  /* result = 1 change to result = n */

    /* Keep looping while n is larger than 0 */
	while (--n) {  /* n-- change to --n */
        result *= n; /* shorthand for "result = result * n" */
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
