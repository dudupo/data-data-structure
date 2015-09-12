#include <stdio.h>
#include <stdlib.h>
#include "avltree.c"

int main(int argc, char const *argv[])
{
	struct avltree avl = create_avltree(20000);
	insert(&avl , 5);
	printf("root : %d \n" ,avl.keys[avl.root]);
	insert(&avl , 3);
	insert(&avl , 2);
	insert(&avl , 1);
	insert(&avl , 7);
	insert(&avl , 8);
	insert(&avl , 9);
	insert(&avl , 10);
	insert(&avl , 11);
	insert(&avl , 12);
	insert(&avl , 14);
	insert(&avl , 15);
	insert(&avl , 13);
	for (int i = 40; i < 900; i+=3)
		insert(&avl , i);

	printf("root : %d \n" ,avl.keys[avl.root]);
	
	printavl(&avl);
	int t = 12;
	printf("searching for %i : %i\n",t , search(&avl ,t));
	t = 41;
	printf("searching for %i : %i\n",t , search(&avl ,t));
	return 0;
}