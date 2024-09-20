#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, or NULL if none exists
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    if (first == NULL || second == NULL)
        return NULL;

    // Create a temporary pointer to traverse up the tree for the first node
    const binary_tree_t *temp_first = first;
    
    // Create a temporary pointer to traverse up the tree for the second node
    const binary_tree_t *temp_second = second;

    // Create a list to store ancestors of the first node
    while (temp_first != NULL)
    {
        // Check for each ancestor of the first node
        temp_second = second;
        while (temp_second != NULL)
        {
            // If an ancestor of the first node matches the second node, return it
            if (temp_first == temp_second)
                return (binary_tree_t *)temp_first;
            temp_second = temp_second->parent; // Move up the second node's ancestors
        }
        temp_first = temp_first->parent; // Move up the first node's ancestors
    }

    return NULL; // No common ancestor found
}

