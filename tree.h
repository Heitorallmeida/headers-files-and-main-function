#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "tree.h"
typedef struct tree tree;
typedef struct heap heap;

struct tree
{
	unsigned char data;//item
	unsigned int freq;//frequencia
	tree *left;
	tree *right;
};

tree* create_empty_tree(int freq, int data);

tree* create_huff_tree(tree *left, tree *right);

int is_empty(tree *hufftree);

tree* dequeuehp(heap *heap);

void print_in_order(tree *hufftree);

tree* build_hufftree(tree *hufftree, heap *heap);

unsigned char set_bit(unsigned char c, unsigned int i);

unsigned char set_xor_bit(unsigned char c, unsigned int i);




#endif