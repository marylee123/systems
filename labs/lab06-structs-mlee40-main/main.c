#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "node.h"
//struct teacher {char name; int period;};
int main(){
    char nameList[8][50] = {"chew", "brando", "avallone", "fletcher", "tomas", "hiller", "morel", "konstantinovich"};
    int periodList[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    srand(time(NULL));

    // creating node list
    struct node *p[4];
    int i;
    for(i = 3; i >= 0; i--){
        if(i == 3){
            p[i] = create_endNode(periodList[rand()%10],nameList[rand()%8]);
            
        } else{
            p[i] = create_node(periodList[rand()%10],nameList[rand()%8],p[i+1]);
        }
    }
    
    // testing print_list()
    print_list(*p);
    
    // testing insert_front()
    *p = insert_front(*p,"baymax");
    printf("\n");
    print_list(*p);
    
    *p = insert_front(*p,"cookie monster");
    printf("\n");
    print_list(*p);
    
    // testing free_list()
    printf("\n");
    free_list(*p);
    print_list(*p);
    
    // repopulating list
    printf("\n");
    for(i = 3; i >= 0; i--){
        if(i == 3){
            p[i] = create_endNode(periodList[rand()%10],nameList[rand()%8]);
            
        } else{
            p[i] = create_node(periodList[rand()%10],nameList[rand()%8],p[i+1]);
        }
    }
    print_list(*p);
    
    // testing arrayLength()
    struct node *k[0] = {};
    printf("\n");
    printf("Array Length of Empty List: %d", arrayLength(*k));
    
    printf("\n");
    printf("Array Length of List with 4 Elements: %d", arrayLength(*p));
    
    // testing remove_node_by_index()
    struct node *start;
    
    printf("\n");
    start = remove_node_by_index(*p,2);
    print_list(start);
    
    printf("\n");
    start =  remove_node_by_index(*p,-1);
    print_list(start);
    
    printf("\n");
    start = remove_node_by_index(*p,0);
    print_list(start);

    return 0;
}
