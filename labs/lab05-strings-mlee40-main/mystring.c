#include <stdio.h>
int mystrlen(char* s){
    int i = 0;
    while(s[i] != 0){
        i++;
    }
    return i;
}
char* mystrcpy(char* dest, char* source){
    int i = 0;
    while(source[i] != 0){
        dest[i]=source[i];
        i++;
    }
    dest[i] = source[i];
    return dest;
}
char *mystrncpy(char *dest, char *source, int n){
    int i = 0;
    while(i < n){
        dest[i]=source[i];
        i++;
    }
    return dest;
}
char *mystrcat(char *dest, char *source){
    int len = mystrlen(dest);
    int i = 0;
    while(source[i] != 0){
        dest[len+i]=source[i];
        i++;
    }
    dest[len+i] = source[i];
    return dest;
}
char *mystrncat(char *dest, char *source, int n){
    int len = mystrlen(dest);
    int i = 0;
    while(i < n){
        dest[len+i]=source[i];
        i++;
    }
    dest[len+i] = 0;
    return dest;
}
char *mystrchr(char *s, char c){
   // int len = mystrlen(dest);
   // int i = 0;
    while(*s){
        if(*s==c){
            return s;
        }
        s++;
    }
    if(c==0){
        return s;
    }
    //dest[len+i] = 0;
   return 0;
}
int mystrcmp(char *s1, char *s2){
    while(*s1 || *s2){
        if(*s1 < *s2){
            return -1;
        }
        else if(*s1 > *s2){
            return 1;
        }
        s1++;
        s2++;
    }
    return 0;
}

