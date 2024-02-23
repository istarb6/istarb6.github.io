#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "NODE.h"
#include "LINKED_TREE.h"

struct Object* CREATE_LINKED_TREE()
{
    struct Object* NEW = (struct Object*)malloc(sizeof(struct Object));
    NEW->HEAD = NULL;
    NEW->size = 0;
    NEW->NodeType = LINKED_TREE;
    return NEW;
}

int GET_FREE_STACK()
{

}

void PUSH_FREE_STACK()
{

}

struct Node* POP_FREE_STACK()
{

}

void REDUCE_LINKED_TREE(struct Object* tree)
{
    if(tree == NULL)
    {
        return;
    }
    struct Node* REAR = tree->HEAD->PREVIOUS[0];
    SET_Node_PREVIOUS(tree->HEAD, 1, REAR->PREVIOUS[0]);
    SET_Node_NEXT(REAR->PREVIOUS[0], 1, tree->HEAD);
    PUSH_FREE_STACK(REAR);
    struct Node* STACK_HEAD;
    int i;
    do
    {
        STACK_HEAD = POP_FREE_STACK();
        for(i = 0; i < STACK_HEAD->DIMENTION; i++)
        {
            if(STACK_HEAD->PREVIOUS[i] != NULL)
            {
                PUSH_FREE_STACK(STACK_HEAD->PREVIOUS[i]);
            }
            if(STACK_HEAD->NEXT[i] != NULL)
            {
                PUSH_FREE_STACK(STACK_HEAD->NEXT[i]);
            }
        }
    } while (GET_FREE_STACK()>0);
    tree->size--;
}

struct Node* LINKE_TREE_NODE(struct Node* ROOT, int leaf_num, ...)
{
    SET_Node_Dimention_Sequence(ROOT, -leaf_num);
    va_list leaves;
    va_start(leaves,leaf_num);
    int i;
    struct Node* LEAF;
    for(i=0; i<leaf_num; i++)
    {
        LEAF = va_arg(leaves, struct Node*);
        ROOT->NEXT[i] = LEAF;
    }
    va_end(leaves);
    return ROOT;
}