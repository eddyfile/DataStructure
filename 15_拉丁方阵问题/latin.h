#ifndef __LATIN_H_
#define __LATIN_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType ;

typedef struct latin
{
    ElemType data;
    struct latin *next;
}latin , * Ptrlatin;




#endif