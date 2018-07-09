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
void graph_destroy(Graph who){
    
}

boolean graph_addVertex(Graph who, Type data){
unsigned long id;    
if (who!=NULL){
    
        id=index(data);
        Node new=(Node)malloc(sizeof(struct strNode);
        new->data=data;
        new->adjVertex=list_create();
        if(who->vertex[id]==NULL){
            who->vertex[id]=new;
}
else
        while(who->vertex[id]!=NULL){
            id=
        }
    }
}
boolean graph_addEdge(Graph who, unsigned long source, unsigned long sink){
    
}
unsigned long graph_vertexCount(Graph who){
	if (who==NULL)
		return -1;
	return who->orden;
}
unsigned long graph_edgeCount(Graph who){
	if (who==NULL)
		return -1;
	return who->size;
}
unsigned long graph_outDegree(Graph who, unsigned long source){
    
}
boolean graph_hasEdge(Graph who, unsigned long source, unsigned long sink){
    
}

