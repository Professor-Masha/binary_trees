#include "binary_trees.h"

/**
 * min_value_node - Finds the node with the smallest value in a tree.
 * @node: Pointer to the root of the tree.
 * Return: Pointer to the node with the smallest value.
 */
avl_t *min_value_node(avl_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * remove_node - Helper function to remove a node from an AVL tree.
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove.
 * Return: Pointer to the new root of the tree after removal.
 */
avl_t *remove_node(avl_t *root, int value)
{
	avl_t *temp;

	if (!root)
		return (root);

	if (value < root->n)
		root->left = remove_node(root->left, value);
	else if (value > root->n)
		root->right = remove_node(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;
			if (!temp)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			temp = min_value_node(root->right);
			root->n = temp->n;
			root->right = remove_node(root->right, temp->n);
		}
	}

	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove in the tree.
 * Return: Pointer to the new root node after deletion.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);

	root = remove_node(root, value);

	/* Rebalance the tree */
	if (root)
		root = binary_tree_balance(root);

	return (root);
}

