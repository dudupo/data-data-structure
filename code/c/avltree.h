
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

struct avltree create_avltree(int maxsize);
void insert(struct avltree  * _avltree, int x);
int search(struct avltree  * _avltree, int x);
void _delete(struct avltree * _avltree, int x);
void rotateL(struct avltree * _avltree, int node);
void rotateR(struct avltree * _avltree, int node);
void printavl(struct avltree * _avltree);
int rotateifneeded(struct avltree * _avltree, int pos);
int isleftchield(struct avltree * _avltree , int node);

#define new(type , n) (type*)malloc(sizeof(type) * n)
#define max(a,b) a > b ? a : b