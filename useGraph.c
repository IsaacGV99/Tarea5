#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#include <string.h>

int compareString(Type, Type);
void printString(Type data);


struct strPerson{
	char[20] actor;
	int year;
	char[50] movie;
};
struct strMovie{
	char[20] movie;
	int year;
	char[50] sinapsis;
};

int main(){
	FILE *vertex_personFile;
	FILE *vertex_moviesFile;
	FILE *edgesPersonFile;
	vertex_personFile=fopen("vertex_person.csv","r");
	vertex_moviesFile=fopen("vertex_movies.csv","r");
	edgesPersonFile=fopen("edgesPerson.csv","r");
	if(vertex_personFile==NULL||vertex_moviesFile==NULL||edgesPersonFile==NULL)
		printf("Error al abrir el archivo\n");
	else{
		char buff[100];
		int i=0;
		while(buff!=","){
			fscanf(vertex_personFile, "%c",&buff[i]);
			i++;
		}				 
	}
	return 0;
}


int compareString(Type data1, Type data2){
	struct strPerson v1=*(struct strPerson *)data1;
	struct strPerson v2=*(struct strPerson *)data2;
	return strcmp(v1.actor,v2.actor);
}
void printString(Type data){
	struct strPerson v1=*(struct strPerson *)data;
	printf(" %s ", v1.actor);
	printf(" %d ", v1.year);
	printf(" %s ", v1.movie);
}
