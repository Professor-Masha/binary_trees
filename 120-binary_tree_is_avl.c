#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * is_bst - Helper function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum allowed value for a node
 * @max: Maximum allowed value for a node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (is_bst(tree->left, min, tree->n) &&
            is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    /* Check if tree is a valid BST */
    if (!is_bst(tree, INT_MIN, INT_MAX))
        return (0);

    /* Get the heights of left and right subtrees */
    left_height = height(tree->left);
    right_height = height(tree->right);

    /* Check if the difference in heights is more than 1 */
    if (abs(left_height - right_height) > 1)
        return (0);

    /* Recursively check if the left and right subtrees are AVL */
    if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
        return (0);

    return (1);
}

