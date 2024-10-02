#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int arr1[10];
    srand(time(NULL));
    
    int r;
    
    int i;
    printf("Initial Array: [");
    for(i=0; i<10; i++){
        r = rand() % 256 - 128;
        arr1[i] = r;
        printf("%d",arr1[i]);
        
        if(i != 9){
            printf(", ");
        }
        else{
            printf("]\n");
        }
    }
    printf("\n");
    int arr2[10];
    int *ptr1 = arr1;
    int *ptr2 = arr2;
    
    int j;
    printf("Reverse Array: \n");
    printf("using pointer notation *: [");
    for(j=0; j<10; j++){
        *(ptr2+j) = *(ptr1+9-j);
        printf("%d",*(ptr2+j));
        
        if(j != 9){
            printf(", ");
        }
        else{
            printf("]\n");
        }
    }
    
    int k;
    printf("using array variable []: [");
    for(k=0; k<10; k++){
        printf("%d",arr2[k]);
        if(k != 9){
            printf(", ");
        }
        else{
            printf("]\n");
        }
    }
    
    
    //int *ptr2 = arr2;
    int n;
    printf("using pointer variable []: [");
    for(n=0; n<10; n++){
        //ptr2[n] = *(ptr2+n);
        printf("%d",ptr2[n]);
        if(n != 9){
            printf(", ");
        }
        else{
            printf("]\n");
        }
    }
}
