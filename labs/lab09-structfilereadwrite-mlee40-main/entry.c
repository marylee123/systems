#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct pop_entry {
  int year;
  int pop;
  char boro[15];
};
void print_entry(struct pop_entry *p){
    printf("year: %d    pop: %d    boro: %s    \n", p->year, p->pop, p->boro);
}
void print_list(struct pop_entry **list){
    if(list == NULL){
        printf("empty list");
    }
    int i = 0;
    struct pop_entry **p = list;
    while(p[i]!=NULL){
        printf("[%d]", i);
        print_entry(p[i]);
        i++;
    }
}
struct pop_entry *create_entry(int year, int pop, char *boro){
    struct pop_entry *s = malloc(sizeof(struct pop_entry));
    s->year = year;
    s->pop = pop;
    strcpy(s->boro,boro);
    return s;
}
