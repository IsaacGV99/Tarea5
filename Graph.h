#ifndef GRAPH_H_
#define GRAPH_H_

typedef void* Type;
typedef int(*Comparator)(Type, Type);
typedef Type(*Clone)(Type);
typedef void (*MyFree)(Type);
typedef void (*MyPrint)(Type);

typedef struct strGraph *Graph;
typedef enum{false, true}boolean;

Graph graph_create(Comparator Cmp, Clone clone, MyFree myfree, MyPrint myprint);
void graph_destroy(Graph who);
boolean graph_addVertex(Graph who, Type data);
boolean graph_addEdge(Graph who, unsigned long source, unsigned long sink);
unsigned long graph_vertexCount(Graph who);
unsigned long graph_edgeCount(Graph who);
unsigned long graph_outDegree(Graph who, unsigned long source);
boolean graph_hasEdge(Graph who, unsigned long source, unsigned long sink);

#endif /* GRAPH_H_ */