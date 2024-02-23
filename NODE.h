#ifndef __NODE_H
#define __NODE_H

enum Data_TypeList
{
    VOID,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    NODE,
    LINKED_LIST,
    LINKED_TABLE,
    LINKED_TREE,
    BINEARY_TREE
};

#define IS_Node_Type(Type) (True if(Type == LINKED_LIST | LINKED_STACK | LINKED_QUEUE))

struct Node
{
    int DIMENTION;
    struct Node** PREVIOUS;
    struct Node** NEXT;

    int DataType;
    void* DATA;
};

struct Object
{
    int NodeType;
    int size;
    struct Node* HEAD;
};

struct Node* CREATE_Node(void* Data, int DataType);
void FREE_Node(struct Node* node);
void PRINT_Node(struct Node* node);
void CREATE_Node_Dimention_Sequence(struct Node* node);
void FREE_Node_Dimention_Sequence(struct Node* node);
void SET_Node_PREVIOUS(struct Node* CUR_node, int dimention, struct Node* PRE_node);
void SET_Node_NEXT(struct Node* CUR_node, int dimention, struct Node* NEX_node);
struct Node* GET_Node_PREVIOUS();
struct Node* GET_Node_NEXT();

#endif

/*
240221
初步实现了链表的基本功能，但是还需要做进一步优化，如将链表设置为循环路逻辑
未来还可以对代码做出改进，如实现链表节点存储不同类型数据的功能（同一链表同种类型，不同链表可以不同）
在实现链表节点存储不同类型数据的功能的基础之上，可以探究多维度的节点的实现，进而构造table
*/
/*
240222
实现了存储不同数据类型的链表
对于table的实现，框架还不清晰，暂时不做
对树的销毁机制做出了大致框架
对树的生成机制需要探究可变函数参数的用法才能做进一步实现
*/