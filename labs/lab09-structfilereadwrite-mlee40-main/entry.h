#ifndef ENTRY_H
#define ENTRY_H
struct pop_entry {
  int year;
  int population;
  char boro[15];
};
char print_entry(struct pop_entry *p);
char print_list(struct pop_entry **list);
struct pop_entry *create_entry(int year, int pop, char *boro);
/*struct node *create_endNode(int period, char teacherName[15]);
struct node *insert_front(struct node *list, char * name);
struct node * free_list(struct node * list);
struct node * remove_node_by_index(struct node *front, int index);
int arrayLength(struct node *list);*/
#endif

