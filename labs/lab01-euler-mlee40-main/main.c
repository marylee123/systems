#include <stdio.h>
#include "euler.h"
int main(){
    printf("Euler01, %d\n",multOf3or5(1000));
    printf("Euler05, %d\n",lcm(20));
    printf("Euler06, %d\n",sumSqDiff(100));
    printf("Euler14, %d\n",collatz(1000000));
    printf("Euler02, %d\n",evenFib(4000000));
    return 0;
}
