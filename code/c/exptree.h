#include "avltree.c"


struct entrypoint
{
	struct exptree * root;
	struct exptree * entry;
};
struct exptree
{
	int height;
	int nodes;
	int maxnodes;
	int value;
	int empty;
	struct avltree *  _avltree;
	struct exptree ** subexptrees;
	struct exptree *  perent;
};
struct exptree * exptree_create(int value);
struct exptree * exptree_create_append(struct exptree * perent);
void exptree_insert(struct exptree * _exptree , int x);
void exptree_insert_dawn(struct exptree * _exptree , int x);
void exptree_insert_up_right(struct exptree * _exptree , int x);
void exptree_insert_up_left(struct exptree * _exptree , int x);
struct exptree * exptree_search(struct exptree * _exptree , int x);
void exptree_delete(struct exptree * _exptree , int x);


