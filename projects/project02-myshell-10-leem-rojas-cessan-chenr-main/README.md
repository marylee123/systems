[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/77as2zNO)
# Systems Project2 - MyShell
## Features our shell implements
- executes known terminal commands
- forking
- error messages
- exit
- cd
- <, >, and |
## Features our shell attempted to implement
## Bugs
## Every function header
int main();
- arguments : none
- return: int
- purpose: initiates the shell, takes in input from terminal, forks and calls to execute commands
  
int err();
- arguments: none
- return: int
- purpose: print errnos in a readable way

int parse_args( char * line, char * parse_by, char ** arg_ary ); 
- arguments:
- - line -> string of input from terminal
- - arg_ary -> array of strings of command and flags so that it can be used in execvp
- return: void -> only modifies arg_ary
- purpose: to process data from stdin so that it can be exectued in shell

void cd_cmd(char * change_dir); 
- arguments:
- - change_dir -> new directory shell is changing to
- return: void -> no variable is altered after function runs
- purpose: change directories

void redirect_stdout(char ** temp, char *filename);
- arguments:
- - temp -> string array of arguements after command
- - filename -> string of name of file command is outputting to
- return: void -> no variable is altered after function runs
- purpose: handle ">" operations
  
void redirect_stdin(char ** temp, char *filename); 
- arguments:
- - filename -> string of file name so it can take in new input
- - args -> array of strings of command and flags so that it can be used in execvp
- return: void -> nothing outside of the function should be altered
- purpose: to handle "<" operations

int* checkforspecialcharacters(char ** args);
- arguments:
- - args -> array of strings of command and arguments so that special characters ("<", ">", and/or "|") can be identified
- return: int * -> index of the special character 
- purpose: find the location of the special character (helper function)

void piping(char** args);
- arguments:
- - args -> array of strings of command and arguments 
- return: void -> nothing outside of the function should be altered
- purpose: handles "|" operations

void executer(char ** args);
- arguments:
- - args -> array of strings of command and arguments 
- return: int -> returns 0 if no errors (or exits)
- purpose: organize how to handle each command including <, >, and |


