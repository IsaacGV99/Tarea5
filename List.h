#ifndef LIST_H_
#define LIST_H_

typedef void* Type;
typedef struct strList* List;
typedef enum{Error,Correcto}Bool;

List list_create();
int list_size(List who);
Bool list_add(List who, Type data);
Type list_get(List who, int p);
void list_set(List who, Type, int p);
Type list_remove(List who, int p);
Bool list_insert(List who, int p, Type value);
void list_destroy(List who);
#endif /* LIST_H_ */
