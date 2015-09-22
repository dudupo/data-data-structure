
if __name__ == '__main__':
	preffix = "./code/c/" 
	files = ["avltree.c", "avltree.h", "debug_main.c"]
	names = {
		"create_avltree" : "avl_create", 
		"insert" : "avl_insert",
		"search" : "avl_search",
		"delete" : "avl_delete",
		"rotateL" : "avl_rotateL",
		"rotateR" : "avl_rotateR",
		"printavl" : "avl_print" ,
		"rotateifneeded" : "avl_rotateifneeded",
		"isleftchield"   : "avl_isleftchield"}

	
	for _file in files:
		content = open(preffix + _file , 'r').read()
		for name , avl_name in names.items():
			content = content.replace(name , avl_name)
		open(preffix + _file , 'w').write(content)

