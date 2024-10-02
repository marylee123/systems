#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};
struct song_node *create_node(char name[], char artist[], struct song_node *nextSong){
    struct song_node *s = malloc((sizeof(struct song_node)));
    strcpy(s->name,name);
    strcpy(s->artist,artist);
    s->next = nextSong;
    return s;
}
int nodecomp(struct song_node*a, struct song_node*b){
  if(a==NULL||b==NULL){
    return 1;
  }
  if(strcmp(a->artist,b->artist)==0){
    return strcmp(a->name,b->name);
  }
  return strcmp(a->artist,b->artist);
}
struct song_node *insert_order(struct song_node *front, char name[], char artist[]){
  struct song_node * p = front;
  struct song_node * l = NULL; //previous node
  struct song_node * n = create_node(name, artist, NULL); //node to insert
  while(1){
    if(nodecomp(p,n)>0){
      n->next=p;
      if(l==NULL){
          return n;
      }
      l->next=n;
      return front;
    }
    else if(nodecomp(p,n)==0){
        return front;
    }
    l=p;
    p=p->next;
  }
  return NULL;
  //return front;
}

struct song_node *find_song(struct song_node *front, char name[], char artist[]){
  if(front==NULL){
    printf("Song not found\n");
    return NULL;
  }
  struct song_node* cur = front;
  while(cur->next!=NULL){
    if(strcmp(cur->name,name)==0&&strcmp(cur->artist,artist)==0){
      return cur;
    }
    cur=cur->next;
  }
  if(strcmp(cur->name,name)==0&&strcmp(cur->artist,artist)==0){
    return cur;
  }
  printf("Song not found\n");
  return NULL;
}
struct song_node *find_song_artist(struct song_node *front, char artist[]){
    if(front==NULL){
        printf("Artist not found\n");
        return NULL;
    }
    struct song_node* cur = front;
    while(cur->next!=NULL){
        if(strcmp(cur->artist,artist)==0){
            return cur;
        }
        cur=cur->next;
    }
    if(strcmp(cur->artist,artist)==0){
        return cur;
    }
    printf("Artist not found\n");
    return NULL;
}
void print_song(struct song_node *song){
  if(song==NULL){return;}
  printf("%s: %s\n", song->artist, song->name);
}
void print_playlist(struct song_node *list){
    while(list != NULL){
        print_song(list);
        list = list->next;
    }
}
int size(struct song_node *list){
    int len = 0;
    while(list != NULL){
        list = list->next;
        len++;
    }
    return len;
}
struct song_node *remove_song(struct song_node *front, char name[], char artist[]){
  if(front==NULL){
    return NULL;
  }
  struct song_node *cur = front;
  struct song_node *l = NULL;
  while(cur!=NULL){
    if(strcmp(cur->name,name)==0&&strcmp(cur->artist,artist)==0){
      if(l==NULL){
        struct song_node *temp = cur->next;
        free(cur);
        return temp;
      } else{
        l->next=cur->next;
        free(cur);
        return front;
      }
    }
    l=cur;
    cur=cur->next;
  }
  printf("!--No Song to Remove--!\n");
  return front;
}
struct song_node *find_randomSong(struct song_node *list){
    //srand(time(0));
    int len = size(list);
    int randomIndex = rand()%len;
    int count = 0;
    while(count < randomIndex){
        if(list != NULL){
            list = list->next;
            count++;
        }
    }
    return list;
}
struct song_node * free_playlist(struct song_node * list){
    struct song_node * p;
    while(list != NULL){
        p = list->next;
        free(list);
        list = p;
    }
    return list;
}
/*
 int nodecomp(struct song_node*a, struct song_node*b){
   if(a==NULL||b==NULL){
     return 1;
   }
   if(strcmp(a->artist,b->artist)==0){
     return strcmp(a->name,b->name);
   }
   return strcmp(a->artist,b->artist);
 }
 struct song_node *insert_order(struct song_node *front, char name[], char artist[]){
   struct song_node * p = front;
   struct song_node * l = NULL; //previous node
   struct song_node * n = create_node(name, artist, NULL); //node to insert
   while(1){
     if(nodecomp(p,n)>0){
       n->next=p;
       if(l==NULL){
           return n;
       }
       l->next=n;
       return front;
     }
     l=p;
     p=p->next;
   }
   return NULL;
 }
 */
