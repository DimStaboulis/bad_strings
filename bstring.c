#include "bstring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bstring* bstring_create(char* buffer,int size) 
{
    if (size > 0) 
    {
        bstring* new = (bstring*)malloc(sizeof(bstring));
        bstring_assign(new,buffer,size);
        return new;
    }
    return NULL;
}

char* bstring_convert(const bstring* bstring_in) 
{
    if (bstring_in->size > 0 && bstring_in->text != NULL) 
    {
        char* cstring = (char*)malloc((sizeof(char) * bstring_in->size) + 1);
        memcpy(cstring, bstring_in->text, bstring_in->size);
        cstring[bstring_in->size] = '\0';
        return cstring;
    }
    
    return NULL;
}

int bstring_dup(bstring* destination,const bstring* source) 
{
    if (source->size > 0 && source->text != NULL) 
    {
        if (destination->text != NULL) 
        {
            free(destination->text);
        }

        destination->size = source->size;
        destination->text = (char*)malloc(sizeof(char)*destination->size);

        bstring_assign(destination,source->text,destination->size);

        return 0;
    }
    
    return 1;
}

int bstring_copy(bstring* destination, const bstring* source) 
{
    if (source->size > 0 && source->text != NULL) 
    {
        if (destination->text == NULL) 
        {
            return 1;
        }

        int copy_size = bsutil_least_size(source->size,destination->size);
        destination->size = copy_size;
       
        memcpy(destination->text, source->text, copy_size);

        return 0;
    }
    
    return 1;
}

int bstring_length(bstring* bstring_in) 
{
    return bstring_in->size;
}

int bstring_assign(bstring* bstring_in,char* buffer,int size) 
{
    if (size > 0) 
    {
        bstring_in->size = size;
        if (bstring_in->text != NULL) {free(bstring_in->text);}
        char *new_text = (char*)malloc(sizeof(char) * bstring_in->size);
        int index = 0;
        char *temp_buf = new_text;

        memcpy(temp_buf, buffer, bstring_in->size);


        bstring_in->text = new_text;
        return 0;   
    }
    return 1;
}

int bstring_compare(const bstring* bstring_in1, const bstring* bstring_in2) 
{
    int index;
    int compare_limit = bsutil_least_size(bstring_in1->size,bstring_in2->size);
    for (index = 0; index < compare_limit; index++) 
    {
        if (bstring_in1->text[index] != bstring_in2->text[index]) return bstring_in1->text[index] - bstring_in2->text[index];
    }
    
    return bstring_in1->size - bstring_in2->size;
}

int bsutil_least_size(int in1,int in2) 
{
    if (in1 < in2) return in1;
    return in2;
}