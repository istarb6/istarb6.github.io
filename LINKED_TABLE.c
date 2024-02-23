#include <stdio.h>
#include <stdlib.h>
#include "NODE.h"
#include "LINKED_TABLE.h"

struct Object* CREATE_LINKED_TABLE()
{
    struct Object* NEW = (struct Object*)malloc(sizeof(struct Object));
    NEW->HEAD = NULL;
    NEW->size = 0;
    NEW->NodeType = LINKED_TABLE;
    
    return NEW;
}