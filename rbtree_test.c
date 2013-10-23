// librbtree - a red-black tree library
// Written by Kristian Klomsten Skordal 2013 <kristian.skordal@gmail.com>
// Report bugs and issues on <http://github.com/skordal/librbtree>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "rbtree.h"

int main(int argc, char * argv[])
{
	struct rbtree * test_tree = NULL;

	printf("Creating test tree... ");
	test_tree = rbtree_new((rbtree_key_compare_func) strcmp, free, (rbtree_key_duplicate_func) strdup);
	if(test_tree == NULL)
	{
		printf("failed!\n");
		abort();
	} else
		printf("ok\n");


	printf("Inserting values into red-black tree:\n");

	printf("\tABC = 1\n");
	rbtree_insert(test_tree, "ABC", "1");

	printf("\tDEF = 2\n");
	rbtree_insert(test_tree, "DEF", "2");

	printf("\tQWE = 72\n");
	rbtree_insert(test_tree, "QWE", "72");

	printf("\tFSG = 24\n");
	rbtree_insert(test_tree, "FSG", "24");

	printf("\tOFS = 84\n");
	rbtree_insert(test_tree, "OFS", "84");

	printf("Lookup of OFS = %s\n", (char *) rbtree_lookup(test_tree, "OFS"));
	printf("Lookup of QWE = %s\n", (char *) rbtree_lookup(test_tree, "QWE"));
	printf("Lookup of IGS = %s\n", (char *) rbtree_lookup(test_tree, "IGS"));
	printf("Lookup of ABC = %s\n", (char *) rbtree_lookup(test_tree, "ABC"));

	printf("Lookup of DEF = %s\n", (char *) rbtree_lookup(test_tree, "DEF"));
	printf("Removal of DEF = %s\n", (char *) rbtree_delete(test_tree, "DEF"));
	printf("Lookup of DEF = %s\n", (char *) rbtree_lookup(test_tree, "DEF"));
	printf("lookup up FSG = %s\n", (char *) rbtree_lookup(test_tree, "FSG"));
	printf("Lookup of ABC = %s\n", (char *) rbtree_lookup(test_tree, "ABC"));

	printf("Freeing test tree... ");
	rbtree_free(test_tree, NULL);
	printf("ok\n");

	return 0;
}

