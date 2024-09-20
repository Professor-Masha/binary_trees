#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    /* Check if parent is NULL */
    if (parent == NULL)
        return (NULL);

    /* Create the new node */
    new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL);

    /* If the parent already has a right child */
    if (parent->right != NULL)
    {
        /* Set the new node's right child to the current right child */
        new_node->right = parent->right;
        parent->right->parent = new_node;
    }

    /* Assign the new node as the right child of the parent */
    parent->right = new_node;

    return (new_node);
}

