#ifndef LIB
#define LIB
//int testfunc();
struct song_node **newlib();
struct song_node **add_song_lib(struct song_node **front, char name[], char artist[]);
struct song_node *search_song_lib(struct song_node **front, char name[], char artist[]);
struct song_node *search_artist_lib(struct song_node **front, char artist[]);
void print_lib_letter(struct song_node **front, char letter);
void print_lib_artist(struct song_node **front, char artist[]);
void print_lib(struct song_node **front);
void shuffle(struct song_node **front, int n);
struct song_node **remove_song_lib(struct song_node **front, char name[], char artist[]);
struct song_node **clear_lib(struct song_node **front);
#endif

