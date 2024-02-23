#include <stdio.h>
#include <stdlib.h>
#include "NODE.h"
#include "LINKED_LIST.h"

struct Object* CREATE_LINKED_LIST()
{
    struct Object* NEW = (struct Object*)malloc(sizeof(struct Object));
    NEW->HEAD = NULL;
    NEW->size = 0;
    NEW->NodeType = LINKED_LIST;
    return NEW;
}

void ADD_LINKED_LIST(struct Object* list, void* data, int type)
{
    if(list == NULL)
    {
        return;
    }
    if(list->size == 0)
    {
        list->HEAD = CREATE_Node(data, type);
        list->size = 1;
        SET_Node_PREVIOUS(list->HEAD, 1, list->HEAD);
        SET_Node_NEXT(list->HEAD, 1, list->HEAD);        
    }
    else
    {
        struct Node* NEW = CREATE_Node(data, type);
        SET_Node_PREVIOUS(NEW, 1, list->HEAD->PREVIOUS[0]);
        SET_Node_NEXT(NEW, 1, list->HEAD); 
        SET_Node_PREVIOUS(list->HEAD, 1, NEW);
        SET_Node_NEXT(NEW->PREVIOUS[0], 1, NEW); 
        list->size++;   
    }
}

void REDUCE_LINKED_LIST(struct Object* list)
{
    if(list == NULL)
    {
        return;
    }
    struct Node* REAR = list->HEAD->PREVIOUS[0];
    SET_Node_PREVIOUS(list->HEAD, 1, REAR->PREVIOUS[0]);
    SET_Node_NEXT(REAR->PREVIOUS[0], 1, list->HEAD);
    FREE_Node(REAR);
    list->size--;
}

void PRINT_LINKED_LIST(struct Object* list)
{
    if(list == NULL)
    {
        return;
    }
    struct Node* REAR = list->HEAD->PREVIOUS[0];
    struct Node* CUR = list->HEAD;

    printf("list>>");
    do        
    {
        PRINT_Node(CUR);
        CUR = CUR->NEXT[0];
    }
    while(CUR != REAR);
    PRINT_Node(CUR);
    printf(">>\n");
}

void FREE_LINKED_LIST(struct Object* list)
{
    if(list == NULL)
    {
        return;
    }
    struct Node* REAR = list->HEAD->PREVIOUS[0];
    struct Node* CUR = REAR->PREVIOUS[0];
    do
    {
        FREE_Node(REAR);
        REAR = CUR;
        CUR = CUR->PREVIOUS[0];
    }
    while(CUR != list->HEAD);
    FREE_Node(REAR);
    free(list);
} 

