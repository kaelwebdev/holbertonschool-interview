#include "binary_trees.h"

/**
 * binary_tree_node - create a binary tree node
 * @parent: address of the root or other node
 * @value: value of the new node
 * Return: a pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *n_n = calloc(1, sizeof(binary_tree_t));

	if (n_n == NULL)
		return (NULL);

	n_n->left = NULL;
	n_n->right = NULL;
	n_n->n = value;
	n_n->parent = parent;

	return (n_n);
}
