#include "avltree.h"

struct avltree * avl_create(int maxsize)
{
	struct avltree * ret = new(struct avltree , 1);
	ret->keys   = new(int, maxsize);
	ret->left   = new(int, maxsize);
	ret->right  = new(int, maxsize);
	ret->perent = new(int, maxsize);
	ret->lenpathL = new(int, maxsize);
	ret->lenpathR = new(int, maxsize);
	ret->root   = 1;
	ret->maxsize= maxsize;
	ret->length = 1;
	ret->_stack = 0;
	return &ret[0];
}
void avl_insert(struct avltree * _avltree, int x)
{
	if (_avltree->length >= _avltree->maxsize)
		return;
	
	if (_avltree->length == 1)
		_avltree->keys[_avltree->root] = x;
	
	else
	{
		int pos  = _avltree->root;
		int done = 0;
		int navigate = 1;
		int index = _avltree->_stack ? _avltree->_stack->data\
		 : _avltree->length;
		while (!done)
		{
			if (x < _avltree->keys[pos])
			{
				navigate = (navigate * 2) + 1;
				if (_avltree->left[pos])
				{
					pos = _avltree->left[pos];
				}
				else
				{
					_avltree->left[pos] = index;
					_avltree->perent[_avltree->left[pos]] = pos;
					_avltree->lenpathL[pos] = 1;
					done = 1;
				}
			}
			else
			{
				navigate *= 2;
				if (_avltree->right[pos])
				{
					pos = _avltree->right[pos];
				}
				else
				{
					_avltree->right[pos] = index;
					_avltree->perent[_avltree->right[pos]] = pos;
					_avltree->lenpathR[pos] = 1;
					done = 1;
				}
			}
		}
		_avltree->keys[index] = x;
		
		// balance //

		while (pos != _avltree->root)
		{
			pos = avl_rotateifneeded(_avltree , pos);

			if (navigate % 2)
			{
				_avltree->lenpathL[_avltree->perent[pos]] = max(\
					_avltree->lenpathL[pos],_avltree->lenpathR[pos]);
				_avltree->lenpathL[_avltree->perent[pos]]++;
			}
			else
			{
				_avltree->lenpathR[_avltree->perent[pos]] = max(\
				 _avltree->lenpathL[pos], _avltree->lenpathR[pos]);
				_avltree->lenpathR[_avltree->perent[pos]]++;
			}
			pos = _avltree->perent[pos];
			navigate /= 2;
		}
		pos = avl_rotateifneeded(_avltree ,pos);
	}
	if (! _avltree->_stack)
		_avltree->length++;
	else
		_avltree->_stack = _avltree->_stack->next;
}

void avl_rotateR(struct avltree * _avltree, int node)
{
	int leftchiled = _avltree->left[node];
	if (avl_isleftchield(_avltree, node))
	{
		_avltree->left[_avltree->perent[node]] = leftchiled;
	}
	else
	{
		_avltree->right[_avltree->perent[node]] = leftchiled;
	}
	_avltree->perent[leftchiled] = _avltree->perent[node];
	_avltree->left[node] = _avltree->right[leftchiled];
	_avltree->perent[_avltree->left[node]] = node;
	_avltree->right[leftchiled] = node;
	_avltree->perent[node] = leftchiled;
	_avltree->root = node == _avltree->root ?\
	 _avltree->perent[node] : _avltree->root;

	_avltree->lenpathL[node] = _avltree->lenpathR[_avltree->perent[node]];
	_avltree->lenpathR[_avltree->perent[node]] = max(_avltree->lenpathL[node],\
	 _avltree->lenpathR[node]);
	_avltree->lenpathR[_avltree->perent[node]]++;
}

void avl_rotateL(struct avltree * _avltree, int node)
{
	int rightchield = _avltree->right[node];
	if (avl_isleftchield(_avltree , node))
	{
		_avltree->left[_avltree->perent[node]] = rightchield;
	}
	else
	{
		_avltree->right[_avltree->perent[node]] = rightchield;
	}
	_avltree->perent[rightchield] = _avltree->perent[node];
	_avltree->right[node] = _avltree->left[rightchield];
	_avltree->perent[_avltree->right[node]] = node;
	_avltree->left[rightchield] = node;
	_avltree->perent[node] = rightchield;
	_avltree->root = node == _avltree->root ?\
	 _avltree->perent[node] : _avltree->root;

	_avltree->lenpathR[node] = _avltree->lenpathL[_avltree->perent[node]];
	_avltree->lenpathL[_avltree->perent[node]] = max(_avltree->lenpathL[node],\
	 _avltree->lenpathR[node]);
	_avltree->lenpathL[_avltree->perent[node]]++;
}
int avl_rotateifneeded(struct avltree * _avltree, int pos)
{
	int difference =\
			 _avltree->lenpathL[pos] - _avltree->lenpathR[pos];

	if (difference > 1)
	{
		avl_rotateR(_avltree ,pos);
		pos = _avltree->perent[pos];
	}
	else if(difference < -1)
	{
		avl_rotateL(_avltree ,pos);
		pos = _avltree->perent[pos];
	}
	return pos;
}
int avl_isleftchield(struct avltree * _avltree , int node)
{
	return _avltree->left[_avltree->perent[node]] == node;
}
void avl_print(struct avltree * _avltree)
{
	int * qeue = new(int ,_avltree->maxsize);
	int * deep = new(int ,_avltree->maxsize);
	qeue[0] = _avltree->root;
	deep[0] = 0;
	int pos = 0;
	int len = 1;
	while (pos != len)
	{
		int l = _avltree->left[qeue[pos]];
		int r = _avltree->right[qeue[pos]];
		if (l){
			qeue[len] = l;
			deep[len++] = deep[pos]+1;
		}
		if (r) {
			qeue[len] = r;
			deep[len++] = deep[pos] +1;  
		}
		pos++;
	}
	printf("%5d", _avltree->keys[qeue[0]]);
	for (int i = 1 ; i < len;i++){
		if (deep[i] > deep[i-1])
			printf("\n");
		printf("%5d", _avltree->keys[qeue[i]]);
	}
	printf("\n");
}
int avl_search(struct avltree  * _avltree, int x)
{
	int pos  = _avltree->root;
	int ret  = pos;
	int done = 0;
	while (!done)
	{
		if (pos == 0 || _avltree->keys[pos] == x)
		{
			if (pos)
				ret = pos;
			done = 1;
		}
		else if (_avltree->keys[pos] > x)
		{
			pos = _avltree->left[pos];
		}
		else
		{
			ret = pos;
			pos = _avltree->right[pos];
		}
	}
	// not expected
	return ret;
}
//@todo::
void avl_delete(struct avltree * _avltree, int x)
{
	int pos = avl_search(_avltree , x);
	int position = pos; // orignal.
	int rightchield = _avltree->right[pos];
	int leftchiled  = _avltree->left[pos];
	
	if (leftchiled == 0 || rightchield == 0)
	{
		if (leftchiled == 0 && rightchield == 0)
		{
			_avltree->perent[pos] = 0;
		}
		else
		{
			if (leftchiled == 0)
			{
				
			}
			else
			{

			}
		}
	}
	else
	{

	}
}
int avl_greater(struct avltree * _avltree, int x)
{
	/*
		note that _avltree include varible x,
		and we seeking for the one who greater then him.
	*/
	int pos     = _avltree->root;
	int greater = _avltree->root;
	int done = 0;
	while (!done)
	{
		if (pos == 0)
		{
			done = 1;
		}
		else if (_avltree->keys[pos] == x)
		{
			pos = _avltree->right[pos];
		}
		else if (_avltree->keys[pos] > x)
		{
			greater = pos;
			pos = _avltree->left[pos];
		}
		else
		{
			pos = _avltree->right[pos];
		}
	}
	return greater;
}