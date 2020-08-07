#ifndef __MAGICIAN_H_
#define __MAGICIAN_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType ;
#define MAX_CARDS 13
typedef struct magician
{
    ElemType data;
    struct magician *next;
}magician , * Ptrmagician;




#endif