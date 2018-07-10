#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

int compararF(Type, Type);
//Type clonarF(Type);
void liberarF(Type);
void printFunciton(Type);
unsigned long Indices(Type);


int main(){
	 Graph g1=graph_create(compararF,Indices, printFunciton);
	int numeros[]={99,25,126,34,225,102,157,199};
	for(short i=0; i<8; i++){
	    if (graph_addVertex(g1, (numeros+i))==true)
	        printf("Valor introducido\n");
	}
	graph_print(g1);
	printf("%li\n", graph_vertexCount(g1));
	graph_addEdge(g1,numeros+2,numeros+1);
	printf("%li\n",graph_edgeCount(g1));
	if(graph_hasEdge(g1,numeros+2,numeros+1))
		printf("si lo tiene");
	graph_destroy(g1);

return 0;
}




int compararF(Type data1, Type data2){
    int v1=*((int*)data1); //Hacer un cast y accesar al valor
    //int v1*=(int*)data1;
    int v2=*((int*)data2);
    return v1-v2;
}

/*//Funcion para clonar los datos
Type clonarF(Type data){
    int val=*((int*)data);
    int *temp=(int*)malloc(sizeof(int));
    *temp=val;
    return temp;
}*/

//Funcion para liberar la memoria
void liberarF(Type data){
    free(data);
}

void printFunciton(Type data){
    printf(" %d \n", *((int*)data));
}
unsigned long Indices(Type data){
	int n=*(int*)data;
	return (unsigned long)n%100;
}



