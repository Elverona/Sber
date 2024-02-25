#include "bst.h"

#include <stdlib.h>

btree* bstree_create_node(int item) {
    btree* newNode = (btree*)malloc(sizeof(btree));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}