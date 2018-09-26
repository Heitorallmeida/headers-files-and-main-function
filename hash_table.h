#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <stdio.h>
#include <stdlib.h>
typedef struct hash_table hash_table;
typedef struct element element;
struct element
{
	unsigned char key;//elementos do arquivo lido
	unsigned int freq;//valores de frequencias
};

struct hash_table
{
	element *table[257]; //array de ponteiros para cada estrutura element
};


hash_table* create_hash_table();

unsigned int create_index(unsigned char key);

void put(hash_table *hashtable, unsigned char key);

int get(hash_table *hashtable,unsigned char key);

void remove_ht(hash_table *hashtable, unsigned char key);

void print_hash(hash_table *hashtable);


#endif