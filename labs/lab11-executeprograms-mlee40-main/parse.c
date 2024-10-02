#include <string.h>

void parse_args( char * line, char ** arg_ary ){
    char *s;
    int i = 0;
    while((s = strsep(&line, " "))){
        arg_ary[i] = s;
        //printf("%s\n",arg_ary[i]);
        i++;
    }
    arg_ary[i] = NULL;
}
