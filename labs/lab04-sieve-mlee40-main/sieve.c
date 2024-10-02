#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int sieve(int target){
    if(target == 1){
        return 2;
    }
    char *p;
    
    int size = (int) (1.5*target*log(target)+50);
    int sizeSqrt = (int) (sqrt(size));

    p = calloc(size,sizeof(char));

    int i;
    int j;
    int count = 1;

    for(i = 0; i <= size; i++){
        if(*(p+i) == 0){
            if(i <= sizeSqrt){
                for(j = 3*i+3; j <= size; j+=2*i+3){
                    *(p+j) = 1;
                }
            }
            count++;
            if(count == target){
                return 2*i+3;
            }
        }
    }
    return -1;

}
