#include "binary_trees.h"


/**
 * new_node - create a new node
 * @v: value of the node
 * @parent: parent node
 * Return: new node
 */
avl_t *new_node(int v, avl_t *parent)
{
	avl_t *n_n;

	n_n = malloc(sizeof(*n_n));
	if (!n_n)
		return (NULL);
	n_n->n = v;
	n_n->parent = parent;
	n_n->left = NULL;
	n_n->right = NULL;
	return (n_n);
}

/**
 * _to_avl - converts array to AVL
 * @array: sorted array
 * @s_idx: start index
 * @e_idx: end index
 * @parent: parent node
 * Return: new AVL tree
*/
avl_t *_to_avl(int *array, size_t s_idx, size_t e_idx, avl_t *parent)
{
	size_t pos_mid;
	avl_t *root;

	if (e_idx == ULONG_MAX || s_idx > e_idx)
		return (NULL);
	pos_mid = s_idx + (e_idx - s_idx) / 2;
	root = new_node(array[pos_mid], parent);
	if (root == NULL)
		return (NULL);

	root->left = _to_avl(array, s_idx, pos_mid - 1, root);
	root->right = _to_avl(array, pos_mid + 1, e_idx, root);
	return (root);
}

/**
 * sorted_array_to_avl - convert an array into an AVL
 * @array: is a pointer to the first element of the array
 * to be converted
 * @size: is the number of element in the array
 * Return: new AVL tree
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);
	return (_to_avl(array, 0, size - 1, NULL));
}
