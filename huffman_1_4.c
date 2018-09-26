#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "heap.h"
#include "tree.h"	
#include "hash_table.h"
#include "compress.h"
#include "change_structure.h"
#define MAX  1000000



int main()
{
	int i;
	unsigned char value;
	hash_table *hash = create_hash_table();
	heap *heap = create_heap();
	hash_tree* hash2 = create_hash_tree();
	tree *hufftree = NULL;
	int truesize;
	FILE *file_in;
	FILE *file_out;
	char filename[MAX], letter;
	


	//printf("Digite o nome do seu arquivo:\n");
	scanf(" %[^\n]s", filename);
	

	file_in = fopen(filename, "r");
	file_out = fopen("out.txt", "w+");
	while(!feof(file_in))
	{
		value = fgetc(file_in);
		//ler valores está funcionando
		//if(value != 0xff && value != 0xa && value != 0x9) 
		put(hash, value); // insere o elemento na hash
		//inserir na hash está funcionando
	}
	fclose(file_in);
	
	//print_hash(hash);

 	// transfere a hash para a heap
  	hashtoheap(heap,hash); // envia os elementos da hash para a heap
 
  	//ordena a heap
  	truesize = heap->size;
  	//parei aqui
	heapsort(heap); // ordena a heap
	heap->size = truesize;
  	//cria a arvore
  	hufftree = build_hufftree(hufftree, heap);
 
  	//imprimindo
  	//print_in_order(hufftree);
  	//tree para hash
  	treetohash(hufftree,hash2,0);
 
	//manda comprimir
  	compress(hufftree,hash2,filename);
 
	
  	return 0;
}
