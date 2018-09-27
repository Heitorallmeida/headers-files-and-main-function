#include <stdio.h>
#include <stdlib.h>
#include "compress.h"
#include "tree.h"
#include "hash_tree.h"
#include "hash_table.h"

int is_bit_i_set(unsigned char comp,int i)
{
	unsigned char mask = 1<<i;
	return mask & comp;
}

int check_bit(tree *hufftree,unsigned char comp,int index)
{
	while(index>=0)
	{
		if(is_bit_i_set(comp,index))
		{
		//	printf("1");
			if(hufftree != NULL) hufftree = hufftree -> right;
		}
		else
		{
		//	printf("0");
			if(hufftree != NULL) hufftree = hufftree -> left;
		}
		index--;
	}
	if(hufftree == NULL) return 1;
	else return 0;
}

unsigned char print_compress(tree *hufftree, unsigned char comp, unsigned int *indexgeral,unsigned int *indexcurrent,unsigned char byteprevious, FILE *file_out)
{
	//printf("compress_7\n");
	unsigned char mask = 0;
	unsigned char byte = 0;
	unsigned int index = 7;
	unsigned int aux = 7;
	
	while(!(is_bit_i_set(comp,index)) && index > 0) index--;

	//printf("compress_8\n");
	index ++;
	//printf("compress_9\n");
	set_bit(mask,index);
	//printf("compress_10\n");
	while(!(check_bit(hufftree,comp,index))) index++;
	//printf("compress_11\n");
	index--;
	//printf("compress_12\n");
	aux = *indexgeral;
	//printf("compress_13\n");
	if(*indexcurrent > 0)
	{

		index = *indexcurrent;
	}
	//printf("compress_14\n");
	while(index >= 0 && aux >= 0)
	{
		if(is_bit_i_set(comp,index)) byte = set_bit(byte,aux);

		if(index > 0) index--;

		else{
			if(aux > 0) aux--;
			else aux = 7;
			*indexgeral = aux;
			*indexcurrent = index;
			return byte + byteprevious;
		}
		if(aux > 0) aux--;
		else
		{
			aux = 7;
			byte += byteprevious;
			fprintf(file_out,"%c",byte);
			//printf("%d", byte);
			*indexgeral = aux;
			*indexcurrent = index;
			byte = 0;
			byteprevious = 0;
		}
	}
}
void put_trash(FILE *file_out, unsigned int trash)
{
	unsigned int bin;
	if(trash == 0)
	{
		fprintf(file_out,"%s\n", );
	}
	
}
void compress(tree *hufftree, hash_tree *hashtree,char filename[], FILE *file_out)
{
	int index;
	unsigned int key;
	unsigned int *index_geral_freq,*index_current_freq;
	unsigned int value1,value2;
	unsigned char value;
	unsigned char byte=0;
	//printf("compress_1\n");
	index_geral_freq = &value1;
	index_current_freq = &value2;
	//printf("compress_2\n");
	FILE *file_in;
	FILE *trash;
	file_in = fopen(filename, "rb");
	//printf("compress_3\n");
	//printf("\n");
	*index_geral_freq = 7;
	*index_current_freq = 0;
	//printf("compress_4\n");
	while(!feof(file_in))
	{
		value = fgetc(file_in);
		key = create_index(value);
		//printf("compress_5\n");
		//printf("%x\n", key);
		//if(hashtree->trees[key] == NULL) printf("aff");
		//if(key !=255 && key !=10)
		//{
			//printf("compress_6\n");
			//printf("%x\n", byte);
			//printf("%x\n", hashtree->trees[key]->path_numofbits);
			///printf("%u\n", index_geral_freq);
		//	printf("%u\n", index_current_freq);
			byte = print_compress(hufftree,hashtree->trees[key]->path_numofbits,index_geral_freq,index_current_freq,byte, file_out);			
			
		//}

		if(*index_geral_freq == 7)
		{
			fprintf(file_out,"%c",byte);
			//printf("%d", byte);
			byte = 0;
		}
	}
	//printf("%d", *index_geral_freq);
	fprintf(file_out,"%c",byte);
	rewind(file_out);
	//////////////////////////////////////////put_trash(file_out, *index_geral_freq); vai usar essa função pra colocar o lixo
	fclose(file_out);
	fclose(file_in);
	//trash = fopen()
}
