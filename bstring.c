#include "bstring.h"
#include <stdio.h>

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

        char* cursor = cstring;
        int index = 0;
        while (index < bstring_in->size) 
        {
            *cursor = bstring_in->text[index];
            cursor++;
            index++;
        }
        *cursor = '\0';

        return cstring;
    }
    
    return NULL;
}

int bstring_dup(bstring* destination,const bstring* source) 
{
    if (source->size > 0 && source->text != NULL) 
    {
        if (destination->text == NULL) 
        {
            if (destination->size > 0) 
            {
                destination->text = (char*)malloc(sizeof(char) * destination->size);
            }
            else 
            {
                return 1;
            }
        }

        int index = 0;
        int dup_size = bsutil_least_size(source->size,destination->size);
       
        while(index < dup_size) 
        {
            destination->text[index] = source->text[index];
            index++;
        }

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
        char *cursor = new_text;
        while (index < bstring_in->size) 
        {
            *cursor = buffer[index];
            cursor++;
            index++;
        }

        bstring_in->text = new_text;
        return 0;   
    }
    return 1;
}

int bstring_compare(const bstring* bstring_in1, const bstring* bstring_in2) 
{
    int compare_limit = bsutil_least_size(bstring_in1->size,bstring_in2->size);
    for (int index = 0; index < compare_limit; index++) 
    {
        if (bstring_in1->[index] != bstring_in2->text[index]) return bstring_in1->[index] - bstring_in2->text[index];
    }
    
}

int bsutil_least_size(int in1,int in2) 
{
     if (in1 < in2) return in1;
        else return in2;
}