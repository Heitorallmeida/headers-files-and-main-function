#include <stdio.h>
#include <stdlib.h>
#include "change_structure.h"
#include "heap.h"
#include "hash_table.h"
#include "tree.h"
#include "hash_tree.h"



void hashtoheap(heap *heap,hash_table *hashtable)
{

	int i;
	//print_hash(hash);
	for(i = 0;i < 257;i++)
	{
       if(hashtable->table[i]!=NULL) 
       {
       		//printf("ok1\n");
		    enqueue(heap,hashtable->table[i]->freq,hashtable->table[i]->key);//enfileira na heap primeiro a frequencia depois o valor
       }
	}
}

void treetohash(tree *hufftree, hash_tree *hashtree, unsigned char comp)
{
	if(hufftree == NULL) return;
	else if(hufftree->left == NULL && hufftree->right == NULL)
	{
		put_from_tree(hashtree,hufftree->data,comp);
		return;
	}
	else
	{
		comp = comp<<1;
		treetohash(hufftree->left,hashtree,comp);
		comp = set_bit(comp,0);
		treetohash(hufftree->right,hashtree,comp);
		comp = comp>>1;
	}
	return;

}