#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct node{
    int period;
    char name[50];
    struct node *next;
};
void printStruct(struct node *p){
    printf("%s, period %d\n", p->name, p->period);
}
void print_list(struct node *list){
    if(list == NULL){
        printf("empty list");
    }
    int i = 0;
    struct node * p = list;
    while(p->next != NULL){
        printf("[%d]", i);
        printStruct(p);
        p = p->next;
        i++;
    }
    printf("[%d]", i);
    printStruct(p);
}
struct node *create_node(int period, char teacherName[], struct node *nextNode){
    struct node *s = malloc(sizeof(period)+sizeof(char[50])+sizeof(nextNode));
    strcpy(s->name,teacherName);
    s->period = period;
    s->next = nextNode;
    return s;
}
struct node *create_endNode(int period, char teacherName[]){
    struct node *s = malloc(sizeof(period)+sizeof(char[50])+sizeof(NULL));
    strcpy(s->name,teacherName);
    s->period = period;
    s->next = NULL;
    return s;
}
struct node * insert_front(struct node *list, char* name){
    srand(time(NULL));
    int randomPeriod = rand()%10+1;
    struct node *s = create_node(randomPeriod, name, list);
    //list -= sizeof(node);
    //strcpy(s->name,name);
    //list = s;
    return s;
}
struct node * free_list(struct node * list){
    struct node * start = list;
    struct node * p;
    while(list->next != NULL){
        p = list->next;
        free(list);
        list = p;
    }
    free(list);
    return start;
}
int arrayLength(struct node *list){
    if(list == NULL){
        return 0;
    }
    int len = 0;
    while(list->next != NULL){
        list = list->next;
        len++;
    }
    return len+1;
}

struct node * remove_node_by_index(struct node *front, int index){
    if(index < 0 || index >= arrayLength(front) || front==NULL){
        return front;
    }
    else{
        struct node * p;
        if(index == 0){
            p = front->next;
            free(front);
            return p;
        } 
        else{
            p = front;
            int i;
            for(i = 0; i < index - 1; i++){
                p = p->next;
            }
            struct node * target = p->next;
            p->next = (p->next)->next;
            free(target);
        }
    }
    return front;

    
    /*
    
    free((front+index));
    if(index == 0){
        return front+1;
    } else{
        front[index-1].next = (front+index+1);
    }*/
}
