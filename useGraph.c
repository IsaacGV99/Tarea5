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

int compareString(Type data1, Type data2){
	struct strPerson v1=*(struct strPerson *)data1;
	struct strPerson v2=*(struct strPerson *)data2;
	return strcmp(v1.actor,v2.actor);
}
void printString(Type data){
	struct strPerson v1=(struct strPerson *)data;
	printf(" %s ", v1.actor);
	printf(" %d ", v1.year);
	printf(" %s ", v1.movie);
}
