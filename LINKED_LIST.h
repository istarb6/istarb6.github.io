#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

struct Object* CREATE_LINKED_LIST();
void ADD_LINKED_LIST(struct Object* list, void* data, int type);
void REDUCE_LINKED_LIST(struct Object* list);
void PRINT_LINKED_LIST(struct Object* list);
void FREE_LINKED_LIST(struct Object* list);

#endif