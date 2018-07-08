#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Graph.h"

struct strNode{
	unsigned long id;
	Type data;
	List adjVertex;
};
typedef struct strNode *Node;

struct strGraph{
	Node* vertex;
	unsigned long orden;
	unsigned long size;
	Comparator functionCmp;
	Clone functionClone;
	MyFree functionFree;
	MyPrint functionPrint;
};

Graph graph_create(Comparator cmp, Clone clone, MyFree myfree, MyPrint myprint){
	Graph new=(Graph)malloc(sizeof(struct strGraph));
	if(new!=NULL){
		new->vertex=NULL;
		new->orden=0;
		new->size=0;
		new->functionCmp=cmp;
		new->functionClone=clone;
		new->functionFree=myfree;
		new->functionPrint=myprint;
	}
	return new;
}

