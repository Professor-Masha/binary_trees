#include "binary_trees.h"

/**
 * create_avl - Recursively creates an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array
 * @start: Start index of the current subarray
 * @end: End index of the current subarray
 *
 * Return: Pointer to the root node of the AVL tree
 */
static avl_t *create_avl(int *array, size_t start, size_t end)
{
    if (start > end)
        return (NULL);

    size_t mid = (start + end) / 2;
    avl_t *node = binary_tree_node(NULL, array[mid]); // Create a new node

    if (!node)
        return (NULL);

    // Recursively build the left and right subtrees
    node->left = create_avl(array, start, mid - 1);
    node->right = create_avl(array, mid + 1, end);

    if (node->left)
        node->left->parent = node; // Set parent for left child
    if (node->right)
        node->right->parent = node; // Set parent for right child

    return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return create_avl(array, 0, size - 1);
}

