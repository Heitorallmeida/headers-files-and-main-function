#include <stdio.h>
#include <stdlib.h>
#include "hash_tree.h"
#include "hash_table.h"

hash_tree* create_hash_tree()
{	
	int i;
	hash_tree *new_hash_tree = (hash_tree*) malloc(sizeof(hash_tree));
	for(i = 0;i < 257;++i)
	{
		new_hash_tree->trees[i] = NULL;
	}
	return new_hash_tree;

}

void put_from_tree(hash_tree *hashtree,unsigned char key,unsigned char comp)
{
	unsigned int  index;
	index = create_index(key); // cria chave baseada no caracter
	tree_element *new_element = (tree_element*) malloc(sizeof(tree_element));
	new_element->key = key;
	new_element->path_numofbits = comp;
	hashtree->trees[index] = new_element;	
}
