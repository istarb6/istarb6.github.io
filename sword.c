/*
User-defined Stack for C Programing Language 

By:IstarB6

Stack is a common type of linear data structure 
follows the LIFO (Last In First Out) principle. 
It is implemented using a dynamic array.

Function List:
init() - Initialize the stack.
elim() - Destroy the stack.
conallo() - Dynamic array size management function.
push() - Push an element onto the stack.
pop() - Pop an element from the stack.
gettop() - View the top element of the stack.
nempty() - Check if the stack is not empty.
*/
#include <stdlib.h>
#include <string.h>

typedef struct stackhead stackhead;

void Stackinit(stackhead* head);
void Stackelim(stackhead* head);
void Stackconallo(stackhead* head);
void Stackpush(stackhead* head, void* data, size_t size);
void* Stackpop(stackhead* head);
void* Stackgettop(stackhead* head);
int Stacknempty(stackhead* head);

struct stackhead
{
    void** container;
    int top;
    int arrsize;
    void(*elim)(stackhead* head);
    void(*conallo)(stackhead* head);
    void(*push)(stackhead* head, void* data, size_t size);
    void*(*pop)(stackhead* head);
    void*(*gettop)(stackhead* head);
    int(*nempty)(stackhead* head);
};

void Stackinit(stackhead* head)
{
    if (head == NULL)
    {
        return;
    }
    head->top = -1;
    head->arrsize = 0;
    head->container = (void**)malloc(4 * sizeof(void*));
    head->elim = Stackelim;
    head->conallo = Stackconallo;
    head->push = Stackpush;
    head->pop = Stackpop;
    head->gettop = Stackgettop;
    head->nempty = Stacknempty;
}

void Stackelim(stackhead* head)
{
    if (head == NULL)
    {
        return;
    }
    free(head->container);
}

void Stackconallo(stackhead* head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->top == head->arrsize - 1)
    {
        head->container = (void**)realloc(head->container, (head->arrsize * 4) * sizeof(void*));
        if (realloc_result == NULL) 
        {
            free(head->container);
            return;
        }
        head->arrsize = head->arrsize + 4;
    }
    else if (head->top < head->arrsize - 4)
    {
        head->container = (void**)realloc(head->container, (head->arrsize + 4) * sizeof(void*));
        if (realloc_result == NULL) 
        {
            free(head->container);
            return;
        }
        head->arrsize = head->arrsize - 4;
    }
}

void Stackpush(stackhead* head, void* data, size_t size)
{
    if (head == NULL)
    {
        return;
    }
    head->top = head->top + 1;
    head->container[head->top] = malloc(size);
    memcpy(head->container[head->top], data, size);
    Stackconallo(head);
}

void* Stackpop(stackhead* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (Stacknempty(head) < 0)
    {
        return NULL;
    }
    void* temp = head->container[head->top];
    head->top = head->top - 1;
    Stackconallo(head);
    return temp;
}

int Stacknempty(stackhead* head)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->top < 0)
    {
        return -1;
    }
    return 1;
}

void* Stackgettop(stackhead* head)
{
    return head->container[head->top];
}