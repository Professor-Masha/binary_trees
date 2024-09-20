#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree
 */
static size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @depth: The depth of the current node
 * @level: The level of the leaf nodes
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
static int is_perfect(const binary_tree_t *tree, int depth, int level)
{
    if (tree == NULL)
        return 0;

    // If it's a leaf node, check if it is at the correct level
    if (tree->left == NULL && tree->right == NULL)
        return (depth == level) ? 1 : 0;

    // If it has one child, it's not perfect
    if (tree->left == NULL || tree->right == NULL)
        return 0;

    // Check both subtrees
    return is_perfect(tree->left, depth + 1, level) &&
           is_perfect(tree->right, depth + 1, level);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int depth = binary_tree_height(tree);
    return is_perfect(tree, 0, depth - 1);
}

