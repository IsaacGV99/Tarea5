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
	Index functionIndex;
	//Clone functionClone;
	//MyFree functionFree;
	MyPrint functionPrint;
};

Graph graph_create(Comparator cmp,Index indice /*Clone clone, MyFree myfree*/, MyPrint myprint){
	Graph new=(Graph)malloc(sizeof(struct strGraph));
	if(new!=NULL){
		new->vertex=(Node*)calloc(100,sizeof(Node);
		new->size_vertex=100;
		new->orden=0;
		new->size=0;
		new->functionCmp=cmp;
		new->fuctionIndex=indice;
		//new->functionClone=clone;
		//new->functionFree=myfree;
		new->functionPrint=myprint;
	}
	return new;
}
					  
void graph_destroy(Graph who){
	//lista, nodo, graph
	Node temp;
	unsigned long id=0;
	if (who!=NULL){
		while(id<who->size_vertex){
			temp=who->vertex[id];
			if(temp!=NULL){
				if (temp->adjVertex!=NULL)
					list_destroy(temp->adjVertex);
				free(temp);
			}
			id++;
		}
		free(who);
	}
}

boolean graph_addVertex(Graph who, Type data){    
	if (who==NULL)
		return false;
	unsigned long id;
	id=who->fuctionIndex(data);
	Node new=(Node)malloc(sizeof(struct strNode);
	new->data=data;
	new->adjVertex=list_create();
	if(who->vertex[id]==NULL){
		who->vertex[id]=new;
	}
	else{
		while(who->vertex[id]!=NULL){
			id++;
			if(id=who->size_vertex)
				id-=who->size_vertex;			
		}
		who->vertex[id]=new;
	}
	who->orden++;
	return true;
}
boolean graph_addEdge(Graph who, Type source, Type sink){
    	if (who==NULL)
		return false;
	unsigned long id;
	id=who->fuctionIndex(source);
	while(who->functionCmp(who->vertex[id]->data,source)!=0){
		id++;
		if(id=who->size_vertex)
			id-=who->size_vertex;
	}
	if(list_add(who->vertex[id]->adjVertex, sink))
		return true;
	return false;
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
	Node temp;
	unsigned long id;
	if (who!=NULL){
		id=who->functionIndex(source); 
		temp=who->vertex[id];
		while(who->functionCmp(source, temp->data)!=0){
			id++;
			//Si el id, sobrepasa el tamaño de la lista de los vertices
			//se reinicia el id restandole el tamñao de la lista.
			if(id==who->size_vertex)
				id-=who->size_vertex;
			temp=who->vertex[id];
		}
		return list_size(temp->adjVertex);		
	}
	return -1;
}
boolean graph_hasEdge(Graph who, Type source, Type sink){
    
}
			      
boolean graph_print(Graph who, MyPrint printFunction){
    
}
			      

