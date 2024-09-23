#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: A pointer to the root node of the heap to convert
 * @size: An address to store the size of the array
 *
 * Return: The generated array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *array;
    size_t heap_size = 0;
    size_t i;

    if (!heap || !size)
        return (NULL);

    // First, we need to determine the size of the heap
    heap_size = binary_tree_size(heap); // Implement this function to get the size of the heap

    array = malloc(sizeof(int) * heap_size);
    if (!array)
        return (NULL);

    for (i = 0; i < heap_size; i++)
    {
        // Extract the maximum value from the heap
        array[i] = heap_extract(&heap); // Implement this function to extract the max
    }

    *size = heap_size;
    return (array);
}

