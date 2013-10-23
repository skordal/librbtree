// librbtree - a red-black tree library
// Written by Kristian Klomsten Skordal 2013 <kristian.skordal@gmail.com>
// Report bugs and issues on <http://github.com/skordal/librbtree>

#ifndef SKORDAL_RBTREE_H
#define SKORDAL_RBTREE_H

// Red-black tree object:
struct rbtree;

// Key comparison type, returning -1 if a < b, 0 if they are equal and 1 if b < a:
typedef int (*rbtree_key_compare_func)(void *, void *);
// Key duplication function:
typedef void * (*rbtree_key_duplicate_func)(void *);
// Key free function:
typedef void (*rbtree_key_free_func)(void *);
// Node data free function:
typedef void (*rbtree_data_free_func)(void *);

// Constructs an empty red-black tree:
struct rbtree * rbtree_new(rbtree_key_compare_func key_compare, rbtree_key_free_func key_free,
	rbtree_key_duplicate_func key_dup);
// Frees a red-black tree and all nodes, optionally calling a user-specified
// function to free the data specified in the nodes.
void rbtree_free(struct rbtree * tree, rbtree_data_free_func free_func);

// Inserts a node in a red-black tree:
void rbtree_insert(struct rbtree * tree, void * key, void * data);
// Removes a node from a red-black tree, returning the data in the node:
void * rbtree_delete(struct rbtree * tree, void * key);

// Gets data from a node from a red-black tree, returning NULL if the key does
// not exist in the tree:
void * rbtree_lookup(struct rbtree * tree, void * key);

#endif

