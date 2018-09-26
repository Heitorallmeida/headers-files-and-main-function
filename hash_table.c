#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

hash_table* create_hash_table()
{
	int i;
	hash_table *new_hash_table = (hash_table*) malloc(sizeof(hash_table));
	for(i = 0;i < 257; i++)
	{
		new_hash_table->table[i] = NULL;
	}
	return new_hash_table;
}

unsigned int create_index(unsigned char key)
{
	unsigned int convert = key;
	return convert % 257;
}

void put(hash_table *hashtable, unsigned char key)
{
	unsigned int  index;
	index = create_index(key); // cria chave baseada no caracter
	if(hashtable->table[index] != NULL) // caso esse espaço na hash seja diferente de nulo 
	{																													 // a frequencia é aumentada
		hashtable->table[index]->freq++;
		return;
	}
	else if(hashtable->table[index]==NULL) // se for igual a nulo ele cria um novo nó
	{
		//index = create_index(index+1); // falta
		element *new_element = (element*) malloc(sizeof(element));
		new_element->key = key;
		new_element->freq = 1;
		hashtable->table[index] = new_element;
	}
}
int get(hash_table *hashtable,unsigned char key)
{
	unsigned char  index;
	index = create_index(key);
	while(hashtable->table[index]!=NULL)
	{
		if(hashtable->table[index]->key==key)
		{
			return hashtable->table[index]->freq;
		}
		index = create_index(index+1);
	}
	return 0;
}

void remove_ht(hash_table *hashtable, unsigned char key)
{
	unsigned char index;
	index = create_index(key);
	while(hashtable->table[index]!=NULL)
	{
		if(hashtable->table[index]->key==key)
		{
			free(hashtable->table[index]);
			hashtable->table[index]->key = -1;
		}
		index = create_index(index+1);
	}
}

void print_hash(hash_table *hashtable)
{
	int index;
	for(index=0;index < 257;index++)
	{
		if(hashtable->table[index]!=NULL) printf("%x = %d\n", hashtable->table[index]->key, hashtable->table[index]->freq);
	}
	printf("\n");
}
