#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one child in a binary tree
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: Number of nodes with at least one child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    // Count this node if it has at least one child
    size_t count = (tree->left != NULL || tree->right != NULL) ? 1 : 0;

    // Recursively count nodes in the left and right subtrees
    return count + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
}

