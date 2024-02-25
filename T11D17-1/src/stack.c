#include "stack.h"

#include <stdlib.h>

#define SUCCESS 0
#define FAIL 1

void init(Stack* stack) { stack->top = NULL; }

int push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) return -1;
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    return SUCCESS;
}
