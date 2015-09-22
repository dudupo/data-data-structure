#include <stdio.h>
#include <stdlib.h>
//#include "avltree.c"
#include "exptree.c"

void debug_avl()
{
	struct avltree avl = *avl_create(20000);
	avl_insert(&avl , 5);
	printf("root : %d \n" ,avl.keys[avl.root]);
	avl_insert(&avl , 3);
	avl_insert(&avl , 2);
	avl_insert(&avl , 1);
	avl_insert(&avl , 7);
	avl_insert(&avl , 8);
	avl_insert(&avl , 9);
	avl_insert(&avl , 10);
	avl_insert(&avl , 11);
	avl_insert(&avl , 12);
	avl_insert(&avl , 14);
	avl_insert(&avl , 15);
	avl_insert(&avl , 13);
	for (int i = 40; i < 900; i+=3)
		avl_insert(&avl , i);

	printf("root : %d \n" ,avl.keys[avl.root]);
	
	avl_print(&avl);
	int t = 12;
	printf("avl_searching for %i : %i\n",t , avl_search(&avl ,t));
	t = 40;
	printf("avl_searching for %i : %i\n",t , avl_search(&avl ,t));
	t = 41;
	printf("avl_searching for %i : %i\n",t , avl_search(&avl ,t));
}
void debug_exp()
{
	struct exptree * _exptree = exptree_create(5);
	printf("exp_tree have been created\n");
}
int main(int argc, char const *argv[])
{
	debug_avl();
	debug_exp();

	return 0;
}