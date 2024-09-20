#include "binary_trees.h"
#include <limits.h>  // Include this header for INT_MIN and INT_MAX

/**
 * is_bst_util - Utility function to check if a binary tree is a BST
 * @tree: Pointer to the current node
 * @min: Minimum value for the current subtree
 * @max: Maximum value for the current subtree
 *
 * Return: 1 if the subtree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (is_bst_util(tree->left, min, tree->n) &&
            is_bst_util(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    return (is_bst_util(tree, INT_MIN, INT_MAX));
}

