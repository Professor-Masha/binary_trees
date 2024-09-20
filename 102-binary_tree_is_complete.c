#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * count_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The number of nodes in the tree
 */
int count_nodes(const binary_tree_t *tree) {
    if (tree == NULL)
        return 0;
    return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

/**
 * is_complete_util - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @number_nodes: Total number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete_util(const binary_tree_t *tree, int index, int number_nodes) {
    if (tree == NULL)
        return 1;

    if (index >= number_nodes)
        return 0;

    return is_complete_util(tree->left, 2 * index + 1, number_nodes) &&
           is_complete_util(tree->right, 2 * index + 2, number_nodes);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree) {
    if (tree == NULL)
        return 0;

    int number_nodes = count_nodes(tree);
    return is_complete_util(tree, 0, number_nodes);
}

