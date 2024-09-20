#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root of the BST
 * @value: Value to insert
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value) {
    bst_t *new_node;

    // Create a new node if the tree is empty
    if (*tree == NULL) {
        new_node = binary_tree_node(NULL, value);
        if (new_node == NULL) {
            return (NULL);  // Memory allocation failed
        }
        *tree = new_node;  // Set as the root of the BST
        return (new_node);
    }

    // Traverse the tree
    if (value < (*tree)->n) {
        // Insert into the left subtree
        if ((*tree)->left == NULL) {
            new_node = binary_tree_node(*tree, value);  // Create a new node
            if (new_node) {
                (*tree)->left = new_node;  // Attach it to the left
            }
            return (new_node);
        } else {
            return bst_insert(&(*tree)->left, value);  // Recur left
        }
    } else if (value > (*tree)->n) {
        // Insert into the right subtree
        if ((*tree)->right == NULL) {
            new_node = binary_tree_node(*tree, value);  // Create a new node
            if (new_node) {
                (*tree)->right = new_node;  // Attach it to the right
            }
            return (new_node);
        } else {
            return bst_insert(&(*tree)->right, value);  // Recur right
        }
    }

    // Value already exists in the tree
    return (NULL);
}

