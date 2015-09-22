#include "exptree.h"

struct exptree * exptree_create(int value)
{
	struct exptree * ret = new(struct exptree , 1);
	ret->height      = 1;
	ret->maxnodes    = 2;
	ret->nodes		 = 0;
	ret->_avltree    = avl_create(2);
	ret->subexptrees = new(struct exptree *, 2);
	ret->value 		 = value;
	ret->empty 		 = 0; 
	return &ret[0]; 
}
struct exptree * exptree_create_append(struct exptree * perent)
{
	struct exptree * ret = new(struct exptree , 1);
	ret->height      = perent->height   + 1;
	ret->maxnodes    = perent->maxnodes * 2;
	ret->nodes		 = 0; 
	ret->_avltree    = avl_create(ret->maxnodes);
	ret->subexptrees = new(struct exptree *, ret->maxnodes);
	ret->perent      = perent;
	ret->empty		 = 1;
	return &ret[0];
}
void exptree_insert(struct exptree * _exptree, int x)
{
	_exptree->subexptrees[_exptree->nodes] = exptree_create_append(_exptree);
	int realperent = avl_search(_exptree->perent->_avltree , x);
	int realperentkey = _exptree->perent->subexptrees[realperent]->value;
	if (_exptree->value == realperentkey)
	{
		
		avl_insert(_exptree->_avltree ,  x);
	}
	else if ( realperentkey < _exptree->value )
	{
		
	} 
	else if ( realperentkey > _exptree->value )
	{
		exptree_insert_dawn(_exptree , _exptree->value);
		avl_delete(_exptree->perent->_avltree, _exptree->value);
		avl_delete(_exptree->perent->_avltree, realperentkey);
		avl_insert(_exptree->perent->_avltree, x);
		avl_insert(_exptree->perent->_avltree, realperentkey);
		exptree_insert_up_right(_exptree->perent->subexptrees[realperent] , x);
	}
	_exptree->nodes++;
}
void exptree_insert_dawn(struct exptree * _exptree , int x)
{
	if (_exptree->empty)
	{
		_exptree->value = x;
		avl_insert(_exptree->perent->_avltree , x);
		_exptree->empty = 0;
	}
	else
	{
		int subtree = avl_search(_exptree->_avltree , x);
		exptree_insert_dawn(_exptree->subexptrees[subtree] , x);
	}
}
void exptree_insert_up_right(struct exptree * _exptree , int x)
{

}
void exptree_insert_up_left(struct exptree * _exptree , int x)
{

}
struct exptree * exptree_search(struct exptree * _exptree, int x)
{
	if (!_exptree || _exptree->value == x)
		return _exptree;
	
	int position = avl_search( _exptree->_avltree  , x);
	if (!position)
		return _exptree;
	exptree_search(_exptree->subexptrees[position] , x);
}
void exptree_delete(struct exptree * _exptree , int x)
{

}
