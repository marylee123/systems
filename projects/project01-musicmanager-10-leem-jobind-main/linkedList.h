#ifndef NODE_H
#define NODE_H
struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};
struct song_node *create_node(char name[], char artist[], struct song_node *nextSong);
struct song_node *insert_order(struct song_node *front, char name[], char artist[]);
void print_song(struct song_node *song);
void print_playlist(struct song_node *list);
struct song_node *find_randomSong(struct song_node *list);
struct song_node * free_playlist(struct song_node * list);
int size(struct song_node *list);
struct song_node *find_song(struct song_node *front, char name[], char artist[]);
struct song_node *find_song_artist(struct song_node *front, char artist[]);
struct song_node *remove_song(struct song_node *front, char name[], char artist[]);
#endif
