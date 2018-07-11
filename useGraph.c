#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#include <string.h>

int compareString(Type, Type);
void printString(Type data);


struct strVertex{
	char texto1[20];
	int year;
	char texto2[50];
};


int main(){
	FILE *vertex_personFile;
	FILE *vertex_moviesFile;
	FILE *edgesPersonFile;
	vertex_personFile=fopen("vertex_person.csv","r");
	vertex_moviesFile=fopen("vertex_movies.csv","r");
	edgesPersonFile=fopen("edges_PersonMovies.csv","r");
	if(vertex_personFile==NULL||vertex_moviesFile==NULL||edgesPersonFile==NULL)
		printf("Error al abrir el archivo\n");
	else{
		char buff[20]="";
		char buff2[10];
		char buff3[100];
		int i=0;
		char c;
		//!feof(vertex_personFile)
		while((c=fgetc(vertex_personFile))!=','&&i<20&&c!=EOF){
			buff[i]=c;
			i++;
		}
		while((c=fgetc(vertex_personFile))!=','&&i<20&&c!=EOF){
			buff[i]=c;
			i++;
		}

		printf("%s",buff);
		/*
		fscanf(vertex_personFile, "%c",&buff);
		printf("%c",buff);
		printf("success");
		*/
		/*
		int i=0;
		while(!feof(vertex_personFile)){
			while(buff[i]!=','){
				fscanf(vertex_personFile, "%c",&buff[i]);
				printf("%c",buff[i]);
				i++;
			}
			while(buff[i]!=','){
				fscanf(vertex_personFile, "%c",&buff2[i]);
				i++;
			}
			while(buff[i]!='\n'){
				fscanf(vertex_personFile, "%c",&buff3[i]);
				i++;
			}
			printf("%s",buff);
			printf("%s",buff2);
			printf("%s",buff3);
		}

	*/
	}

	return 0;
}


int compareString(Type data1, Type data2){
	struct strVertex v1=*(struct strVertex *)data1;
	struct strVertex v2=*(struct strVertex *)data2;
	return strcmp(v1.texto1,v2.texto1);
}
void printString(Type data){
	struct strVertex v1=*(struct strVertex *)data;
	printf(" %s ", v1.texto1);
	printf(" %d ", v1.year);
	printf(" %s ", v1.texto2);
}
