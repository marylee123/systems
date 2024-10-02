#ifndef LIBRARY_H
#define LIBRARY_H
int err();
int parse_args( char * line, char * parse_by, char ** arg_ary ); //parsing by parse_by
void cd_cmd(char * change_dir); //changes directory
void redirect_stdout(char ** temp, char *filename); //redirects stdout to a file
void redirect_stdin(char ** temp, char *filename); //redirects stdin from file
int* checkforspecialcharacters(char ** args);
void piping(char** args);
int executer(char ** args);
#endif
