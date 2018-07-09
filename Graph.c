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
	unsigned long size_vertex;
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
		new->vertex=(Node*)calloc(100,sizeof(Node);
		new->size_vertex=100;
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

		id=who->index(data);
		Node new=(Node)malloc(sizeof(struct strNode);
		new->data=data;
		new->adjVertex=list_create();
		if(who->vertex[id]==NULL){
		    who->vertex[id]=new;
		}
		else{
			boolean b_espacio=false;
			while(who->vertex[id]!=NULL&&id<who->size_vertex){
		    		id++;
				if(who->vertex[id]==NULL)
					b_espacio=true;	
			}
			if(b_espacio){
				
			}
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
unsigned long graph_outDegree(Graph who, Type source){
    
}
boolean graph_hasEdge(Graph who, Type source, Type sink){
    
}

