
#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#include <string.h>

int compareString(Type, Type);
void printString(Type data);
unsigned long indexString(Type data, unsigned long size);
unsigned long horner(char *c,int base, int longitud,unsigned long size);
int valueof(char c);


struct strVertex{
	char texto1[20];
	char year[5];
	char texto2[100];
};

struct strEdge{
	char texto1[100];
	char texto2[100];
};



int main(){

	FILE *vertex_personFile;
	FILE *vertex_moviesFile;
	FILE *edgesPersonFile;

	vertex_personFile=fopen("vertex_person.csv","r");
	vertex_moviesFile=fopen("vertex_movies.csv","r");
	edgesPersonFile=fopen("edges_PersonMovies.csv","r");

	struct strVertex personData[102];
	struct strVertex moviesData[38];
	struct strEdge edgesData[173];

	if(vertex_personFile==NULL||vertex_moviesFile==NULL||edgesPersonFile==NULL)
		printf("Error al abrir el archivo\n");
	else{
		int k=0;
		char c;
		while(!feof(vertex_personFile)){
			char buff[20]="";
			char buff2[5]="";
			char buff3[100]="";
			int i=0;
			while((c=fgetc(vertex_personFile))!=','&&i<20&&c!=EOF){
				buff[i]=c;
				i++;
			}
			i=0;
			while((c=fgetc(vertex_personFile))!=','&&i<5&&c!=EOF){
				buff2[i]=c;
				i++;
			}
			i=0;
			while((c=fgetc(vertex_personFile))!='\n'&&i<100&&c!=EOF){
				buff3[i]=c;
				i++;
			}
			strcpy(personData[k].texto1,buff);
			strcpy(personData[k].year,buff2);
			strcpy(personData[k].texto2,buff3);
			k++;
		}
		k=0;
		while(!feof(vertex_moviesFile)){
			char buff[20]="";
			char buff2[5]="";
			char buff3[100]="";
			int i=0;
			while((c=fgetc(vertex_moviesFile))!=','&&i<20&&c!=EOF){
				buff[i]=c;
				i++;
			}
			i=0;
			while((c=fgetc(vertex_moviesFile))!=','&&i<5&&c!=EOF){
				buff2[i]=c;
				i++;
			}
			i=0;
			while((c=fgetc(vertex_moviesFile))!='\n'&&i<100&&c!=EOF){
				buff3[i]=c;
				i++;
			}
			strcpy(moviesData[k].texto1,buff);
			strcpy(moviesData[k].year,buff2);
			strcpy(moviesData[k].texto2,buff3);
			k++;
		}
		while(!feof(edgesPersonFile)){
			char buff[100]="";
			char buff2[100]="";
			char temp[50]="";
			int i=0;
			while((c=fgetc(edgesPersonFile))!='\n'&&i<50&&c!=EOF){
				temp[i]=c;
				i++;
			}
			i=0;
			while((c=fgetc(edgesPersonFile))!=','&&i<100&&c!=EOF){
				buff[i]=c;
				i++;
			}
			i=0;
			while((c=fgetc(edgesPersonFile))!='\n'&&i<100&&c!=EOF){
				buff2[i]=c;
				i++;
			}
			strcpy(edgesData[k].texto1,buff);
			strcpy(edgesData[k].texto2,buff2);
			k++;
		}
	}
	int i=0;
	for(i=0;i<102;i++)
		printString(&personData[i]);







	/*
	Graph G1;
	G1=graph_create(compareString, indexString, printString);

	int i;
	for(i=0;i<102;i++){
		if(graph_addVertex(G1,&personData[i]))
			printf("añadido\n");
	}

	for(i=0;i<38;i++){
		if(graph_addVertex(G1,&moviesData[i]))
			printf("añadido\n");
	}

	//graph_addEdge(G1,&edgesData[0].texto1,&edgesData[0].texto2);
	printf("%li",	graph_vertexCount(G1));


	graph_addVertex(G1,&personData[0]);
	graph_addVertex(G1,&personData[1]);


	graph_print(G1);
	graph_destroy(G1);
	*/
	printf("success");
	return 0;
}


int compareString(Type data1, Type data2){
	char* v1=(char *)data1;
	char* v2=(char *)data2;
	return strcmp(v1,v2);
}
void printString(Type data){
	struct strVertex v1=*(struct strVertex *)data;
	printf(" %s ", v1.texto1);
	printf(" %s ", v1.year);
	printf(" %s\n", v1.texto2);
}
unsigned long indexString(Type data, unsigned long size){
	struct strVertex v=*(struct strVertex *)data;
	int k;
	unsigned long index=0;
	for(k=0;k<4;k++){
		index+=v.texto1[k];
	}
	return index%size;
}
/*
unsigned long horner(char *c,int base, int longitud,unsigned long size){
	long h=valueof(c[0]);
	int k;
	for(k=1;k<longitud;k++){
		h+=((((h%size)*(base%size)%size)%size)+(valueof(c[k])%size))%size;
	}
	return h;
}
int valueof(char c){
	return (c-65);
}
*/
