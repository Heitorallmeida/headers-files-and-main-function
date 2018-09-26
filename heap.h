#ifndef HEAP_H
#define HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "heap.h"
typedef struct heap heap;
typedef struct tree tree;
struct heap
{
	int begin;
    int size;// tamanho
    tree *tree[257];
};

heap* create_heap();//cria a heap

void enqueue(heap *heap, int element,unsigned char data);//coloca no array as frequencias e seus respectivos elementos

void build_heap(heap *heap);//constroi a heap

int get_parent_i(heap *heap,int i);//obtém o indice do pai

int get_left_i(heap *heap,int i);//obtém o indice da esquerda

int get_right_i(heap *heap,int i);//obtém o indice da direita

void heapfy(heap *heap,int i);//da min heapify para que a cabeça do array seja a menor frequencia sempre

void heapsort(heap *heap);//ordena as frequencias

#endif