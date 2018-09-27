#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "heap.h"

tree* create_empty_tree(int freq, int data)
{
	tree *new_tree = (tree*) malloc(sizeof(tree));
	new_tree->freq = freq;
	new_tree->data = data;
	new_tree->right = NULL;
	new_tree->left = NULL;
	return new_tree;
}

tree* create_huff_tree(tree *left, tree *right)
{
	tree *new_tree = (tree*) malloc(sizeof(tree));
	new_tree->left = left;
	new_tree->right = right;
	new_tree->freq = left->freq + right->freq;
	new_tree->data = 19;
	return new_tree;
}

int is_empty(tree *hufftree)
{
	if(hufftree == NULL)return 1;
	else return 0;
}

tree* dequeuehp(heap *heap)
{
        tree *item = heap->tree[heap->size];
        heap->size--;
        heapfy(heap,heap->begin);
        return item;
    
}

void print_in_order(tree *hufftree, FILE *file_out)
{
	
	if(!is_empty(hufftree))
	{
		if(hufftree->left == NULL && hufftree->right == NULL) fprintf(file_out,"%c",hufftree->data);
		else fprintf(file_out,"*");
		print_in_order(hufftree->left, file_out);
		print_in_order(hufftree->right, file_out);
	}
	
}

tree* build_hufftree(tree *hufftree, heap *heap)
{
	tree *aux = NULL;
	tree *aux2 = NULL;
	int truesize;
	while(heap->begin < heap->size)
    {

  		aux = NULL;
  		aux2 = NULL;

       
        aux = dequeuehp(heap);
        truesize = heap->size;
        heapsort(heap);
        heap->size = truesize;
        
        aux2 = dequeuehp(heap);
        truesize = heap->size;
        heapsort(heap);
        heap->size = truesize;
		
		if(aux2->data == 19 && aux->data != 19)
		{
			hufftree = create_huff_tree(aux2, aux);
		}
		else
		{
			hufftree = create_huff_tree(aux, aux2);
		}
		heap->tree[++heap->size] = hufftree;
        truesize = heap->size;
        heapsort(heap);
        heap->size = truesize;
    }
   
    return hufftree;
}

unsigned char set_bit(unsigned char c, unsigned int i)
{
	unsigned char mask = 1 << i;
	return mask | c;
}

unsigned char set_xor_bit(unsigned char c, unsigned int i)
{
	unsigned char mask = 1 << i;
	return mask ^ c;
}
