#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"
#include <string.h>

int compareString(Type, Type);
void printString(Type data);

int compareString(Type data1, Type data2){
	char v1=*(char *)data1;
	char v2=*(char *)data2;
	return strcmp(v1,v2;
}
void printString(Type data){
	printf(" %s ", *(char *)data);
}
