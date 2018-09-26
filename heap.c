#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "tree.h"


heap* create_heap()
{
    heap *new_heap = (heap*) malloc(sizeof(heap));
    new_heap->begin = 1;
    new_heap->size = 0;
    return new_heap;
}

void enqueue(heap *heap,int freq,unsigned char data)
{
  //  printf("ok2\n");
	tree *new_tree = create_empty_tree(freq, data);
	heap->tree[++heap->size] = new_tree;
}

void build_heap(heap *heap)
{
    int i;
    for(i = (heap->size)/2;i;i--)
    {
        heapfy(heap,i);
    }
}

int get_parent_i(heap* heap,int i)
{
    int result = i/2;
    return result;
}

int get_left_i(heap* heap,int i)
{
    int result = 2*i;
    return result;
}

int get_right_i(heap* heap,int i)
{
    int result = 2*i + 1;
    return result;
}

void heapfy(heap* heap,int i)
{
    int smallest,left_index,right_index;
    tree *auxz = NULL;
  	left_index = get_left_i(heap,i); // encontra o filho esquerdo
    right_index = get_right_i(heap,i); // encontra o filho direito
    
  	if((left_index <= heap->size) &&  (heap->tree[left_index]->freq < heap->tree[i]->freq)) // Verifica se o filho esquerdo é valdio
    {																																						// e se sua frequencia é menor que a  
        smallest = left_index;																									// do pai
    }
    else
    {
        smallest = i;                                                         // assume que o menor é o pai
    }
    if((right_index <= heap->size) && (heap->tree[right_index]->freq < heap->tree[smallest]->freq)) // verifica se o direito é menor 
    {																																										// que o menor
        smallest = right_index;
    }
    if((heap->tree[i]->freq != heap->tree[smallest]->freq))                               // se a frequencia do indice 
    {																																					// não for a menor ele realiza a troca
        
    	auxz = heap->tree[i];
        heap->tree[i] = heap->tree[smallest];
        heap->tree[smallest] = auxz;
        heapfy(heap,smallest);
    }
}

void heapsort(heap* heap)
{
	tree *hufftree = NULL;
	tree *left = NULL;
	tree *right = NULL;
	tree *aux = NULL;
	build_heap(heap); // constroi a heap
     
  	int current,last,current2;
    for(current = heap->size;current >= heap->begin;current--)
    {
     //   printf("%d\n", heap->tree[heap->begin]->freq);
        aux = heap->tree[current];
        heap->tree[current] = heap->tree[heap->begin];
        heap->tree[heap->begin] = aux;
        heap->size--;
        heapfy(heap,heap->begin);
    } 
 
}