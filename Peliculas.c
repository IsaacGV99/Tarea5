#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

void printString(Type data);
int compareString(Type data1, Type data2);
unsigned long indexString(Type data, unsigned long size);

struct strVertex{
	char texto1[50];
	char year[5];
	char texto2[200];
};
struct strEdge{
	struct strVertex actor;
	struct strVertex pelicula;
};

int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	FILE *vertex_personFile;
	FILE *vertex_moviesFile;
	FILE *edgesPersonFile;

	vertex_personFile=fopen("vertex_person.csv","r");
	vertex_moviesFile=fopen("vertex_movies.csv","r");
	edgesPersonFile=fopen("edges_PersonMovies.csv","r");

	if(vertex_personFile==NULL||vertex_moviesFile==NULL||edgesPersonFile==NULL){
		printf("Error en el archivo");
		return -1;
	}
	struct strVertex personData[105];
	struct strVertex moviesData[38];
	struct strEdge edgesData[173];

	int k=0;
	char c;
	do{
		fscanf(vertex_personFile, "%[^,]", personData[k].texto1);
		fseek(vertex_personFile,sizeof(char),SEEK_CUR);
		fscanf(vertex_personFile, "%[^,]", personData[k].year);
		fseek(vertex_personFile,sizeof(char),SEEK_CUR);
		fscanf(vertex_personFile, "%[^\n]", personData[k].texto2);
		k++;
	}while((c=fgetc(vertex_personFile))!=EOF);
	k=0;

	do{
		fscanf(vertex_moviesFile, "%[^,]", moviesData[k].texto1);
		fseek(vertex_moviesFile,sizeof(char),SEEK_CUR);
		fscanf(vertex_moviesFile, "%[^,]", moviesData[k].year);
		fseek(vertex_moviesFile,sizeof(char),SEEK_CUR);
		fscanf(vertex_moviesFile, "%[^\n]", moviesData[k].texto2);
		k++;
	}while((c=fgetc(vertex_moviesFile))!=EOF);

	char temp[50]="";
	fgets(temp,50,edgesPersonFile);
	k=0;
	do{
		fscanf(edgesPersonFile, "%[^,]", edgesData[k].actor.texto1);
		fseek(edgesPersonFile,sizeof(char),SEEK_CUR);
		fscanf(edgesPersonFile, "%[^\n]", edgesData[k].pelicula.texto1);

		k++;
	}while((c=getc(edgesPersonFile))!=EOF);

	Graph G1;
	G1=graph_create(compareString, indexString, printString);

	for(int i=0;i<102;i++){
		if(!graph_addVertex(G1,&personData[i]))
			printf("Error %d\n",i);
	}
	for(int i=0;i<38;i++){
		if(!graph_addVertex(G1,&moviesData[i]))
			printf("Error %d\n",i);
	}
	/*for(int i=0;i<172;i++){
		printf("%s\t%s\n",edgesData[i].actor.texto1,edgesData[i].pelicula.texto1);
	}*/


	for(int i=0;i<172;i++){
		if(!graph_addEdge(G1,&edgesData[i].actor,&edgesData[i].pelicula))
			printf("Error %d\n",i);
	}
	if(graph_hasEdge(G1,&personData[61],&moviesData[16]))
		printf("a huevo\n");
	graph_print(G1);
	graph_destroy(G1);

	fclose(vertex_personFile);
	fclose(vertex_moviesFile);
	fclose(edgesPersonFile);
	printf("success");

	return 0;
}
void printString(Type data){
	struct strVertex v1=*(struct strVertex *)data;
	printf(" %s ", v1.texto1);
	printf(" %s ", v1.year);
	printf(" %s\n", v1.texto2);
}
int compareString(Type data1, Type data2){
	char* v1=((struct strVertex *)data1)->texto1;
	//printf("%s\n",v1);
	char* v2=((struct strVertex *)data2)->texto1;
	//printf("%s\n",v2);
	return strcmp(v1,v2);
}

unsigned long indexString(Type data, unsigned long size){
	struct strVertex v=*(struct strVertex *)data;
	int k;
	unsigned long index=0;
	for(k=0;k<4;k++)
		index+=v.texto1[k];
	return index%size;
}
