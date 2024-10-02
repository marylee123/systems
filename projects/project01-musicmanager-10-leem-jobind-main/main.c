#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linkedList.h"
#include "library.h"
int main(){

    printf("\n");
    printf("LINKED LIST TESTS\n====================================\n");
    
    printf("---TESTING PRINT PLAYLIST---\n\n");
    struct song_node *playlist = NULL;
    playlist = insert_order(playlist, "Cruel Summer", "Taylor Swift");
    playlist = insert_order(playlist, "Viva La Vida", "Coldplay");
    playlist = insert_order(playlist, "Mr. Blue Sky", "Electric Light Orchestra");
    playlist = insert_order(playlist, "Ain't No Mountain High Enough", "Marvin Gaye & Tammi Terrell");
    playlist = insert_order(playlist, "Creep", "Radiohead");
    playlist = insert_order(playlist, "The Pool", "Stephen Sanchez");
    playlist = insert_order(playlist, "As the World Caves In", "Matt Maltese");
    playlist = insert_order(playlist, "Bohemian Rhapsody", "Queen");
    print_playlist(playlist);
    printf("\n");
    
    printf("---TESTING INSERT SONG---\n\n");
    printf("Inserting [Taylor Swift: Wildest Dreams]...\n");
    playlist = insert_order(playlist, "Wildest Dreams", "Taylor Swift");
    printf("Inserting [Taylor Swift: Cruel Summer]...\n");
    playlist = insert_order(playlist, "Cruel Summer", "Taylor Swift");
    printf("Inserting [Taylor Swift: Blank Space]...\n");
    playlist = insert_order(playlist, "Blank Space", "Taylor Swift");
    printf("Inserting [Rainbow: Since You Been Gone]...\n");
    playlist = insert_order(playlist, "Since You Been Gone", "Rainbow");
    printf("\n");
    print_playlist(playlist);
    printf("\n");

    printf("---TESTING FIND SONG W/ ARTIST AND SONG NAME---\n\n");
    printf("Searching [Coldplay: Viva La Vida]...\n");
    print_song(find_song(playlist,"Viva La Vida","Coldplay"));
    printf("\n");
    
    printf("Searching [Taylor Swift: Cruel Summer]...\n");
    print_song(find_song(playlist,"Cruel Summer","Taylor Swift"));
    printf("\n");
    
    printf("Searching [Katy Perry: The One that Got Away]...\n");
    print_song(find_song(playlist,"The One that Got Away","Katy Perry"));
    printf("\n");
    
    printf("---TESTING FIND FIRST SONG BASED ON ARTIST NAME---\n\n");
    printf("Searching for a song by [Coldplay]...\n");
    print_song(find_song_artist(playlist,"Coldplay"));
    printf("\n");
    
    printf("Searching for a song by [Taylor Swift]...\n");
    print_song(find_song_artist(playlist,"Taylor Swift"));
    printf("\n");
    
    printf("Searching for a song by [Katy Perry]...\n");
    print_song(find_song_artist(playlist,"Katy Perry"));
    printf("\n");
    
    printf("---TESTING RANDOM SONG---\n\n");
    print_song(find_randomSong(playlist));
    print_song(find_randomSong(playlist));
    print_song(find_randomSong(playlist));
    print_song(find_randomSong(playlist));
    printf("\n");
    
    printf("---TESTING REMOVE SONG---\n\n");
    printf("Removing [Taylor Swift: Cruel Summer]...\n");
    playlist = remove_song(playlist, "Cruel Summer", "Taylor Swift");
    printf("Removing [Katy Perry: The One that Got Away]...\n");
    playlist = remove_song(playlist, "The One that Got Away", "Katy Perry");
    printf("\n");
    print_playlist(playlist);
    
    printf("\n");
    printf("Removing (Again) [Katy Perry: The One that Got Away]...\n");
    playlist = remove_song(playlist, "The One that Got Away", "Katy Perry");
    print_playlist(playlist);
    printf("\n");
    
    printf("---TESTING FREE PLAYLIST---\n");
    playlist = free_playlist(playlist);
    print_playlist(playlist);
    
    printf("\n\n\n\n\n\n\n");
    
    /*
    struct song_node *testNode = create_node("test","test",NULL);
    //printf("\n%d\n", strcmp("Greetings", "Hello"));
    //testing print_playlist
    
    struct song_node *a[3];
    a[2] = create_node("a2","s2",NULL);
    a[1] = create_node("a1","s1",a[2]);
    a[0] = create_node("a0","s0",a[1]);

    print_playlist(*a);
    *a = insert_order(*a, "a", "john");
    print_playlist(*a);
    
    printf("\n\n");
    struct song_node* where = find_song(*a,"a2","s2");
    print_playlist(where);
    printf("\n\n");
    *a = insert_order(*a, "b", "s1");
    where = find_song_artist(*a,"s1");
    print_playlist(where);
    */
    //print_playlist(*a);
    //printf("%d", strcmp("s1","s0"));
    /*
    struct song_node *rt = create_node("0","0",NULL);
    char n[100] ="";
    char r[100] ="";
    for(int i=0; i<26; i++){
        n[0] = (char)(65+i);
        r[0] = (char)(97+i);
        rt = insert_order(rt,n,r);
    }
    */
    //printf("%s\n",(rt->next)->name);
    /*
    print_playlist(rt);
    printf("\n");
    rt=remove_song(rt,"B","b");
    print_playlist(rt);
    printf("\n");
    rt=remove_song(rt,"D","d");
    print_playlist(rt);
    printf("\n");
    rt=remove_song(rt,"H","h");
    print_playlist(rt);
    printf("\n");
    rt=remove_song(rt,"R","r");
    print_playlist(rt);
    */
    
    /*
    print_playlist(*a);
    printf("%d\n", size(*a));
    print_song(find_randomSong(*a));*/
   /* printf("\n\n");
    *a = free_playlist(*a);
    print_playlist(*a);*/
    //printf("%d\n", testfunc());
    
    
    
    
    
    
    
    
    
    //TESTING LIB
    /*struct song_node *playlist = NULL;
    playlist = insert_order(playlist, "Cruel Summer", "Taylor Swift");
    playlist = insert_order(playlist, "Viva La Vida", "Coldplay");
    playlist = insert_order(playlist, "Viva La Vida", "11");
    print_playlist(playlist);
    printf("\n\n");
    
    struct song_node **library = newlib();
    library = add_song_lib(library, "Cruel Summer", "Taylor Swift");
    library = add_song_lib(library, "Viva La Vida", "Coldplay");
    library = add_song_lib(library, "Nobody Like U", "4*TOWN");
    print_lib(library);
    printf("\n");*/
    printf("LIBRARY TESTS\n====================================\n");
    
    printf("---TESTING PRINT LIBRARY---\n\n");
    struct song_node **library = newlib();
    library = add_song_lib(library, "Cruel Summer", "Taylor Swift");
    library = add_song_lib(library, "Viva La Vida", "Coldplay");
    library = add_song_lib(library, "Mr. Blue Sky", "Electric Light Orchestra");
    library = add_song_lib(library, "Ain't No Mountain High Enough", "Electric Light Orchestra");
    library = add_song_lib(library, "Creep", "Radiohead");
    library = add_song_lib(library, "The Pool", "Stephen Sanchez");
    library = add_song_lib(library, "As the World Caves In", "Matt Maltese");
    library = add_song_lib(library, "7 Years", "Lukas Graham");
    library = add_song_lib(library, "Bohemian Rhapsody", "Queen");
    library = add_song_lib(library, "Nobody Like U", "4*TOWN");
    print_lib(library);
    printf("\n");
    
    printf("---TESTING ADD SONG---\n\n");
    
    printf("Adding [Nena: 99 Red Balloons]...\n");
    library = add_song_lib(library, "99 Red Balloons", "Nena");
    
    printf("Adding [2CELLOS: We Found Love]...\n");
    library = add_song_lib(library, "We Found Love", "2CELLOS");
    
    printf("Adding [Taylor Swift: 22]...\n");
    library = add_song_lib(library, "22", "Taylor Swift");
    
    printf("Adding [Taylor Swift: Cruel Summer]...\n");
    library = add_song_lib(library, "Cruel Summer", "Taylor Swift");
    printf("\n");
    print_lib(library);
    printf("\n");

    printf("---TESTING FIND SONG W/ ARTIST AND SONG NAME---\n\n");
    printf("Searching [Coldplay: Viva La Vida]...\n");
    print_song(search_song_lib(library,"Viva La Vida","Coldplay"));
    printf("\n");
    
    printf("Searching [Taylor Swift: Cruel Summer]...\n");
    print_song(search_song_lib(library,"Cruel Summer","Taylor Swift"));
    printf("\n");
    
    printf("Searching [Katy Perry: The One that Got Away]...\n");
    print_song(search_song_lib(library,"The One that Got Away","Katy Perry"));
    printf("\n");
    
    printf("---TESTING LIST SONGS UNDER ARTIST---\n\n");
    printf("Searching for songs by [Coldplay]...\n");
    print_lib_artist(library,"Coldplay");
    printf("\n");
    
    printf("Searching for songs by [Taylor Swift]...\n");
    print_lib_artist(library,"Taylor Swift");
    printf("\n");
    
    printf("Searching for songs by [Katy Perry]...\n");
    print_lib_artist(library,"Katy Perry");
    printf("\n");
    
    printf("---TESTING SHUFFLE---\n\n");
    shuffle(library, 5);
    printf("\n");
    
    printf("---TESTING DELETE SONG---\n\n");
    printf("Removing [Taylor Swift: Cruel Summer]...\n");
    library = remove_song_lib(library, "Cruel Summer", "Taylor Swift");
    printf("Removing [Katy Perry: The One that Got Away]...\n");
    library = remove_song_lib(library, "99 Red Balloons", "Nena");
    printf("\n");
    print_lib(library);
    
    printf("\n");
    printf("Removing (Again) [Katy Perry: The One that Got Away]...\n");
    library = remove_song_lib(library, "99 Red Balloons", "Nena");
    print_lib(library);
    printf("\n");
    
    printf("---TESTING CLEAR LIBRARY---\n\n");
    library = clear_lib(library);
    print_lib(library);
    
    /*
    //print_lib(lib);
    struct song_node * a1 = create_node("song_name1","artist_name1",NULL);
    struct song_node * a2 = create_node("song_name2","artist_name2",NULL);
    //a1->next = a2;
    //(*lib) = a1;
    add_song_lib(lib, a2);
    add_song_lib(lib, a1);
    //print_playlist(a1);
    print_lib(lib);
    struct song_node * finder = search_artist_lib(lib, "artist_name2");
    //print_song(finder);
    //print_lib_letter(lib,'a');
    printf("\n\n\n");
    add_song_lib(lib, create_node("lolol","bartist",NULL));
    add_song_lib(lib, create_node("lilil","bartist",NULL));
    add_song_lib(lib, create_node("lelel","bertist",NULL));
    add_song_lib(lib, create_node("lalal","bertist",NULL));
    print_lib_letter(lib, 'b');
    printf("\n\n\n");
    //print_lib_letter(lib, 'a');
    //print_lib_artist(lib, "artist_name2");
    //printf("\ntesting shuffle\n\n");
    //shuffle(lib, 4);
    //printf("\n\n");
    //print_lib(lib);

    remove_song_lib(lib,"lalal","bertist");
    remove_song_lib(lib,"lelel","bertist");
    print_lib_letter(lib, 'b');

    //clear_lib(lib);
    //print_lib(lib);*/
    return 0;
}
