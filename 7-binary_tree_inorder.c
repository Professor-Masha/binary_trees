#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: The value in the node is passed as a parameter to this function
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);   /* Traverse the left subtree */
	func(tree->n);                           /* Visit the root node */
	binary_tree_inorder(tree->right, func);  /* Traverse the right subtree */
}

