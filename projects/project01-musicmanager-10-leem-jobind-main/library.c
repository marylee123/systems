#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "linkedList.h"

struct song_node **newlib(){
    struct song_node **lib = calloc(27,sizeof(struct song_node*));
    for(int i = 0; i < 27; i++){
        lib[i] = NULL;
    }
    return lib;
}
struct song_node **add_song_lib(struct song_node **front, char name[], char artist[]){
    int lowercase = 97;
    int uppercase = 65;
    if(front != NULL){
        for(int i = 0; i < 26; i++){
            if(artist[0] == lowercase+i || artist[0] == uppercase+i){
                front[i] = insert_order(front[i], name, artist);
                //insert_order(struct song_node *front, char name[], char artist[]);
                return front;
            }
        }
        front[26] = insert_order(front[26], name, artist);
    }
    return front;
}
void print_lib(struct song_node **front){
    if(front != NULL){
        for(int i = 0; i < 27; i++){
            if(front[i]!=NULL){
                printf("————————————————————————————————————\n");
                print_playlist(front[i]);
            }
        }
        printf("————————————————————————————————————\n");
    }
}
struct song_node *search_song_lib(struct song_node **front, char name[], char artist[]){
    int lowercase = 97;
    int uppercase = 65;
    if(front != NULL){
        for(int i = 0; i < 26; i++){
            if((artist)[0] == lowercase+i || (artist)[0] == uppercase+i){
                return find_song(front[i], name, artist);
            }
        }
        return find_song(front[26], name, artist);
    }
    return NULL;
}
struct song_node *search_artist_lib(struct song_node **front, char artist[]){
    int lowercase = 97;
    int uppercase = 65;
    if(front != NULL){
        for(int i = 0; i < 26; i++){
            if((artist)[0] == lowercase+i || (artist)[0] == uppercase+i){
                return find_song_artist(front[i], artist);
            }
        }
        return find_song_artist(front[26], artist);
    }
    printf("Artist not found\n");
    return NULL;
}
void print_lib_letter(struct song_node **front, char letter){
    int lowercase = 97;
    int uppercase = 65;
    if(front != NULL){
        for(int i = 0; i < 26; i++){
            if(letter == lowercase+i || letter == uppercase+i){
                print_playlist(front[i]);
            }
        }
    }
}

void print_lib_artist(struct song_node **front, char artist[]){
    if(front != NULL){
        print_playlist(search_artist_lib(front, artist));
    }
}
void shuffle(struct song_node **front, int n){
    srand(time(NULL));
    int d = n;
    while(d>0){
        int i = rand()%27;
        if(front[i]!=NULL){
            int passer = 0;
            struct song_node * t = front[i];
            while(passer == 0){
                if(t->next==NULL){
                    passer=1;
                    print_song(t);
                } else{
                    if(rand()%2==0){
                        passer=1;
                        print_song(t);
                    }
                    t=t->next;
                }
            }
        }else{
            d++;
        }
        d--;
    }
}
struct song_node **remove_song_lib(struct song_node **front, char name[], char artist[]){
    int lowercase = 97;
    int uppercase = 65;
    for(int i = 0; i < 26; i++){
        if((artist)[0] == lowercase+i || (artist)[0] == uppercase+i){
            front[i] = remove_song(front[i], name, artist);
        }
    }
    return front;
}
struct song_node **clear_lib(struct song_node **front){
    for(int i=0; i<27; i++){
        front[i] = free_playlist(front[i]);
    }
    //free(front);
    return front;
}
/*
 void search_artist_lib(struct song_node **front, char artist[]){
     int lowercase = 97;
     int uppercase = 65;
     if(front != NULL){
         for(int i = 0; i < 26; i++){
             if((artist)[0] == lowercase+i || (artist)[0] == uppercase+i){
                 struct *song_node first_song = find_song_artist(front[i], artist);
                 print_song(first_song);
                 while(strcmp(first_song->artist, (first_song->next)->artist)==0){
                     first_song = first_song->next;
                     print_song(first_song);
                 }
             }
         }
         struct *song_node first_song = find_song_artist(front[26], artist);
         print_song(first_song);
         while(strcmp(first_song->artist, (first_song->next)->artist)==0){
             first_song = first_song->next;
             print_song(first_song);
         }
     }
     printf("Artist not found\n");
     //return NULL;
 }*/
