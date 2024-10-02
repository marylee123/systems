#ifndef NODE_H
#define NODE_H
struct node{
    int period;
    char name[50];
    struct teacher_node *next;
};
char printStruct(struct node *p);
char print_list(struct node * list);
struct node *create_node(int period, char teacherName[], struct node *nextNode);
struct node *create_endNode(int period, char teacherName[15]);
struct node *insert_front(struct node *list, char * name);
struct node * free_list(struct node * list);
struct node * remove_node_by_index(struct node *front, int index);
int arrayLength(struct node *list);
#endif
