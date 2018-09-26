#ifndef  HASH_TREE_H
#define HASH_TREE_H
typedef struct hash_tree hash_tree;
typedef struct tree_element tree_element;

struct tree_element
{
	unsigned char key;//elemento que vem da arvore
	unsigned char path_numofbits;//caminho na arvore
};

struct hash_tree
{
	tree_element *trees[257];//array de ponteiros para cada estrutura tree_element
};

hash_tree* create_hash_tree();

//void put_in_tree(hash_tree *hashtree,unsigned char key,unsigned char comp);
void put_from_tree(hash_tree *hashtree,unsigned char key,unsigned char comp);


#endif