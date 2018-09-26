#ifndef COMPRESS_H
#define COMPRESS_H
#include "tree.h"
#include "hash_tree.h"
#include "hash_table.h"
int is_bit_i_set(unsigned char comp,int i);

int check_bit(tree *hufftree,unsigned char comp,int index);

unsigned char print_compress(tree *hufftree, unsigned char comp, unsigned int *indexgeral,unsigned int *indexcurrent,unsigned char byteprevious);

void compress(tree *hufftree, hash_tree *hashtree,char filename[]);

#endif 