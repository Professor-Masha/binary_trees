#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    // If tree is NULL, return 0
    if (tree == NULL)
        return 0;

    // If it's a leaf node, return 1 (it is full)
    if (tree->left == NULL && tree->right == NULL)
        return 1;

    // If both children are present, check recursively
    if (tree->left != NULL && tree->right != NULL)
        return binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);

    // If one child is missing, return 0 (not full)
    return 0;
}

