#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle for
 *
 * Return: Pointer to the uncle node, or NULL if none exists
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return NULL;

    // Get the grandparent of the node
    binary_tree_t *grandparent = node->parent->parent;

    // Check if the parent is a left child
    if (node->parent == grandparent->left)
        return grandparent->right;  // Return the right uncle

    // The parent is a right child
    return grandparent->left;  // Return the left uncle
}

