#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: a double pointer to the root node of heap
 *
 * Return: the value stored in the root node
 *         0 on failure
 */
int heap_extract(heap_t **root)
{
    if (root == NULL || *root == NULL)
        return 0; // Return 0 on failure if root is NULL

    // Assuming you have a way to get the value from the root node
    int root_value = (*root)->n;

    // Logic to restructure the heap would go here
    // For example, replacing the root with the last element, 
    // then re-adjusting the heap.

    return root_value; // Return the value stored in the root node
}

