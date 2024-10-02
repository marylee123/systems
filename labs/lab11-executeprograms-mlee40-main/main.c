#include <unistd.h>
#include "parse.h"

int main(int argc, char *argv[]){
    char * args[16];
    char line[] = "banner -w 30 One Piece";
    parse_args(line,args);
    execvp(args[0], args);
  
    return 0;
}


