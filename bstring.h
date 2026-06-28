#ifndef BSTRING_H
#define BSTRING_H


#include <stdlib.h>

typedef struct bstring_t 
{
    char* text;
    int size;

} bstring;

bstring* bstring_create(char*,int);
char* bstring_convert(const bstring*);
int bstring_dup(bstring*,const bstring*);
int bstring_length(bstring*);
int bstring_assign(bstring*,char*,int);
int bsutil_least_size(int,int);

#endif