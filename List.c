#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct strNode{
	Type data;
	struct strNode *next;
	struct strNode *prior;
};
typedef struct strNode* Node;
struct strList{
	Node First;
	Node Last;
	int size;
};
List list_create(){
	List new=(List)malloc(sizeof(struct strList));
	if(new!=NULL){
		new->First=NULL;
		new->Last=NULL;
		new->size=0;
	}
	return new;
}
int list_size(List who){
	return who->size;
}
Bool list_add(List who, Type data){
	Node newNode=(Node)malloc(sizeof(struct strNode));
	if (newNode==NULL)
		return Error;
	newNode->data=data;
	newNode->next=NULL;
	if(list_size(who)==0){
		who->First=newNode;
		newNode->prior=NULL;
	}
	else{
		newNode->prior=who->Last;
		who->Last->next=newNode;
	}
	who->Last=newNode;
	who->size++;
	return Correcto;
}
Bool list_insert(List who, int p, Type data){
	if(p>list_size(who)+1||p<1)
		return Error;
	Node newNode=(Node)malloc(sizeof(struct strNode));
	if (newNode==NULL)
		return Error;
	newNode->data=data;
	if(p==1){
		newNode->prior=NULL;
		newNode->next=who->First;
		if(who->First==NULL)
			who->Last=newNode;
		else
			who->First->prior=newNode;
		who->First=newNode;
	}
	else{
		Node tempNode=who->First;
		for(int i=1;i<p-1;i++)
			tempNode=tempNode->next;
		newNode->prior=tempNode;
		newNode->next=tempNode->next;
		tempNode->next=newNode;
		if(newNode->next!=NULL)
			newNode->next->prior=newNode;
		else
			who->Last=newNode;
	}
	who->size++;
	return Correcto;
}

Type list_remove(List who, int p){
	if(p>list_size(who)||p<1)
		return NULL;
	Type data;
	Node tempNode=who->First;
	for(int i=1;i<p;i++)
		tempNode=tempNode->next;
	data=tempNode->data;
	if(tempNode->prior!=NULL)
		tempNode->prior->next=tempNode->next;
	else
		who->First=tempNode->next;
	if(tempNode->next!=NULL)
		tempNode->next->prior=tempNode->prior;
	else
		who->Last=tempNode->prior;
	who->size--;
	free(tempNode);
	return data;
}
Type list_get(List who, int p){
	if(p>list_size(who)||p<1)
		return NULL;
	Node tempNode=who->First;
	for(int i=1;i<p;i++)
		tempNode=tempNode->next;
	return tempNode->data;
}
void list_set(List who, Type data, int p){
	if(p<=list_size(who)&&p>0){
		Node tempNode=who->First;
		for(int i=1;i<p;i++)
			tempNode=tempNode->next;
		tempNode->data=data;
	}
}
void list_destroy(List who){
	Type temp;
	while(list_size(who)!=0)
		temp=list_remove(who,1);
	free(who);
}
