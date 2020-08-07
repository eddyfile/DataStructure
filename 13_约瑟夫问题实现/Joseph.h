#ifndef __YOSEPH_H_
#define __YOSEPH_H_

#include <stdio.h>
#include <stdlib.h>

/*结构*/
typedef struct Node{
	
	int 	data;
	struct Node *next;
	
}*PtrNode;

/*返回状态*/
typedef enum Status{
	_Success_,
	_Fail
}Status;

Status InitJoseph(PtrNode jop_list,int n);
Status DeleteJosephNode(PtrNode list, int k);

#endif