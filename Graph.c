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
		new->size_vertex=200;
		new->vertex=(Node*)calloc(new->size_vertex,sizeof(Node));
		new->orden=0;
		new->size=0;
		new->functionCmp=cmp;
		new->functionIndex=indice;
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
void graph_redimention(Graph who);
void graph_redimention(Graph who){
		if(who!=NULL){
		unsigned long newsize_vertex=(who->size_vertex)*1.2;
		printf("%li",who->size_vertex);
		printf("%li",newsize_vertex);
		Node* newVertex=(Node*)calloc(newsize_vertex,sizeof(Node));
		for(unsigned long i=0;i<who->size_vertex;i++){
			Node temp=who->vertex[i];
			if(temp!=NULL){
				temp->id=who->functionIndex(temp->data,newsize_vertex);
				while(newVertex[temp->id]!=NULL)
					temp->id++;
				newVertex[temp->id]=temp;
			}
		}
		who->size_vertex=newsize_vertex;
		free(who->vertex);
		who->vertex=newVertex;
		}
}

boolean graph_addVertex(Graph who, Type data){
	if (who==NULL)
		return false;
	/*if((who->size_vertex*4/5)<who->orden){
		printf("entro");
		graph_redimention(who);
	}*/
	unsigned long id;
	id=who->functionIndex(data,who->size_vertex);
	while(who->vertex[id]!=NULL){
		if(who->functionCmp(who->vertex[id]->data,data)==0)
			return false;
		id++;
		if(id==who->size_vertex)
			id-=who->size_vertex;
	}
	Node new=(Node)malloc(sizeof(struct strNode));
	if (new==NULL)
		return false;
	new->data=data;
	new->adjVertex=list_create();
	new->id=id;
	who->vertex[id]=new;
	who->orden++;
	return true;
}
boolean graph_addEdge(Graph who, Type source, Type sink){
    if (who==NULL)
		return false;
	unsigned long id;
	id=who->functionIndex(source,who->size_vertex);
	while(who->vertex[id]!=NULL){
		if(who->functionCmp(who->vertex[id]->data,source)==0){
			if(list_add(who->vertex[id]->adjVertex, sink)){
					who->size++;
					return true;
			}
			else{
				printf("No sirvio list_add\n");
				return false;
			}
		}
		id++;
		if(id==who->size_vertex)
			id-=who->size_vertex;
	}
	printf("No encontro nombre\n");
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
		id=who->functionIndex(source, who->size_vertex);
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
	if(who==NULL)
		return false;
	unsigned long id=who->functionIndex(source, who->size_vertex);
	while(who->functionCmp(who->vertex[id]->data,source)!=0){
		id++;
		if(id==who->size_vertex)
			id-=who->size_vertex;
	}
	List list_Vertex=who->vertex[id]->adjVertex;
	int i=1;
	Type temp;
	while(i<=list_size(list_Vertex)){
		temp=list_get(list_Vertex,i);
		if(who->functionCmp(temp,sink)==0)
			return true;
		i++;
	}
	return false;
}
void graph_print(Graph who){
	Node temp;
	printf("%li",who->orden);
	printf("%li",who->size_vertex);
	unsigned long id=0;
	if (who!=NULL){
		while (id<who->size_vertex){
			temp=who->vertex[id];
		if (temp!=NULL)
				who->functionPrint(temp->data);
		id++;
		}
	}
}

