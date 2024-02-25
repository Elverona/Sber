#include <stdio.h>

#include "bst.h"

int main() {
    btree* node1 = bstree_create_node(10);
    if (node1 != NULL) {
        printf("Create node: %d\n", node1->item);
    }
    return 0;
}