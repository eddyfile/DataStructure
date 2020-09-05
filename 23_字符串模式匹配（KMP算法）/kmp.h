#ifndef __BF_H_
#define __BF_H_
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

int KMPIndex(ElemType *s, ElemType *t);
int GetStringLen(char *s);
void GetKMPnext(ElemType *p, int next[]);



#endif // !__BF_H_
