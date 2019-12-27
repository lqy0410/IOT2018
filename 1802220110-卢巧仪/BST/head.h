#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	struct tree *lchild,*rchild;
	int data;
}*BiTree,BiNode;
 