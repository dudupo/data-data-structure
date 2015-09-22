
struct stack
{
	int data;
	struct stack * next;
};

struct avltree
{
	struct stack *_stack;
	int *perent;
	int *keys;
	int *left;
	int *right;
	int *lenpathL;
	int *lenpathR;
	int root;
	int length;
	int maxsize;
};

struct avltree * avl_create(int maxsize);
void avl_insert(struct avltree  * _avltree, int x);
int avl_search(struct avltree  * _avltree, int x);
void avl_delete(struct avltree * _avltree, int x);
void avl_rotateL(struct avltree * _avltree, int node);
void avl_rotateR(struct avltree * _avltree, int node);
void avl_print(struct avltree * _avltree);
int avl_rotateifneeded(struct avltree * _avltree, int pos);
int avl_isleftchield(struct avltree * _avltree , int node);
int avl_greater(struct avltree * _avltree, int x);
//int avl_smaller(struct avltree * _avltree, int x);
#define new(type , n) (type*)malloc(sizeof(type) * n)
#define max(a,b) a > b ? a : b
#define swap(type ,a ,b)\
	type temp_swap = a;\
	a = b;\
	b = temp_swap;
	