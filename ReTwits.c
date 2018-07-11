
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

typedef struct{
	char retweet_id[19];
	char tweet_id[19];
}ReTweets;

int compararF(Type, Type);
void printFunciton(Type);
unsigned long Indices(Type, unsigned long);

int main(){
	setvbuf(stderr, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	FILE *archivo;
	ReTweets* datos=(ReTweets*)malloc(sizeof(ReTweets));
	ReTweets* temp;
	archivo=fopen("RETWEETS.csv","r");
	if(archivo==NULL){
		printf("Error al abrir el archivo");
		return -1;
	}
	char c;
	unsigned long len=0;
	do{
		fscanf(archivo, "%[^,]", datos[len].retweet_id);
		c=fgetc(archivo);
		fscanf(archivo, "%[^\n]", datos[len].tweet_id);
		len++;
		temp=(ReTweets*)realloc(datos,sizeof(ReTweets)*(len+1));
		if(temp!=NULL)
			datos=temp;
		else{
			printf("Error al agrandar el archivo");
			return-1;
		}
		//printf("Extraido : %li\n",len);
	}while((c=fgetc(archivo))!=EOF);
	/*for(unsigned long i=0; i<len;i++){
		printf("%s %s\n", datos[i].retweet_id, datos[i].tweet_id);
	}*/
	Graph G1=graph_create(compararF,Indices, printFunciton);
	for(unsigned long i=0; i<len;i++){
		graph_addVertex(G1,datos[i].retweet_id);
		graph_addVertex(G1,datos[i].tweet_id);
		graph_addEdge(G1,datos[i].retweet_id,datos[i].tweet_id);

	}

	if(graph_hasEdge(G1,datos[100457].retweet_id,datos[100457].tweet_id))
		printf("Si lo tiene\n");
	if(graph_hasEdge(G1,datos[1].retweet_id,datos[1].tweet_id))
			printf("Si lo tiene\n");
	if(graph_hasEdge(G1,datos[32040].retweet_id,datos[32040].tweet_id))
			printf("Si lo tiene\n");
	if(graph_hasEdge(G1,datos[77551].retweet_id,datos[77551].tweet_id))
			printf("Si lo tiene\n");
	if(graph_hasEdge(G1,datos[405].retweet_id,datos[405].tweet_id))
			printf("Si lo tiene\n");
	if(graph_hasEdge(G1,datos[5478].retweet_id,datos[5478].tweet_id))
			printf("Si lo tiene\n");

	fclose(archivo);

	return 0;
}
int compararF(Type data1, Type data2){
	char* v1=(char*)data1;
	char* v2=(char*)data2;
	return strcmp(v1,v2);
}
void printFunciton(Type data){
	char* v=(char*)data;
	printf("%s\n",v);
}
unsigned long Indices(Type data, unsigned long size){
	char* id=(char*)data;
	unsigned long index=id[11];
	for(int i=1;i<7;i++){
		index*=10;
		index+=id[11+i]-48;
	}
	return index%size;

}
