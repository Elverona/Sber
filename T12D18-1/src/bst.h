#ifndef BST_H
#define BST_H

typedef struct btree {
    int item;
    struct btree* left;
    struct btree* right;
} btree;

btree* bstree_create_node(int item);

#endif