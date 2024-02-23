#include <stdio.h>
#include <stdlib.h>
#include "NODE.h"

void CREATE_Node_Dimention_Sequence(struct Node* node)
{
    node->PREVIOUS = (struct Node**)malloc(sizeof(struct Node*) * 1);
    node->NEXT = (struct Node**)malloc(sizeof(struct Node*) * 1);
    node->PREVIOUS[0] = NULL;
    node->NEXT[0] = NULL;
    node->DIMENTION = 1;
}

void SET_Node_Dimention_Sequence(struct Node* node, int dimention)
{
    if(node->DIMENTION > dimention)
    {
        return;
    }
    else
    {
        node->PREVIOUS = (struct Node**)realloc(node->PREVIOUS, sizeof(struct Node*) * dimention);
        node->NEXT = (struct Node**)realloc(node->PREVIOUS, sizeof(struct Node*) * dimention);
        int i;
        for(i = node->DIMENTION; i<dimention; i++)
        {
            node->PREVIOUS[i] = NULL;
            node->NEXT[i] = NULL;
        }
        node->DIMENTION = dimention;
    }
}

struct Node* CREATE_Node(void* Data, int DataType)
{
    struct Node* New_Node = (struct Node*)malloc(sizeof(struct Node));

    CREATE_Node_Dimention_Sequence(New_Node);

    New_Node->DataType = DataType;
    New_Node->DATA = Data;

    return New_Node;
}

void SET_Node_PREVIOUS(struct Node* CUR_node, int dimention, struct Node* PRE_node)
{
    if(CUR_node->DIMENTION < dimention)
    {
        SET_Node_Dimention_Sequence(CUR_node, dimention);
    }
    CUR_node->PREVIOUS[dimention-1] = PRE_node;
}

void SET_Node_NEXT(struct Node* CUR_node, int dimention, struct Node* NEX_node)
{
    if(CUR_node->DIMENTION < dimention)
    {
        SET_Node_Dimention_Sequence(CUR_node, dimention);
    }
    CUR_node->NEXT[dimention-1] = NEX_node;
}

void PRINT_Node(struct Node* node)
{
    if(node == NULL)
    {
        return;
    }
    switch(node->DataType)
    {
        case VOID:
        {
            printf("-NONE-");
            break;
        }
        case INT:
        {
            printf("- %d -", *((int*)node->DATA));
            break;
        }
        case CHAR:
        {
            printf("- %c- ", *((char*)node->DATA));
            break;
        }
        case FLOAT:
        {

            break;
        }
        case DOUBLE:
        {

            break;
        }
        default:
        {
            printf("error type!");
        }
    }
}

void FREE_Node(struct Node* node)
{
    if(node == NULL)
    {
        return;
    }
    free(node->PREVIOUS);
    free(node->NEXT);
    free(node);
}
