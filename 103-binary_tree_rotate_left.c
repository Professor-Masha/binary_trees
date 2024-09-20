#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * 
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL || tree->right == NULL)
        return (tree);

    new_root = tree->right; // The new root is the current right child
    tree->right = new_root->left; // The left child of new root becomes the right child of current root

    if (new_root->left != NULL) // If new root has a left child
        new_root->left->parent = tree; // Set its parent to the current root

    new_root->parent = tree->parent; // Set the new root's parent to the current root's parent

    if (tree->parent == NULL) // If current root is the root of the tree
        ; // Handle the case where we need to update the actual root pointer

    else if (tree == tree->parent->left) // Update parent's left child if needed
        tree->parent->left = new_root;

    else // Update parent's right child if needed
        tree->parent->right = new_root;

    new_root->left = tree; // Set the current root as the left child of the new root
    tree->parent = new_root; // Update the current root's parent to the new root

    return (new_root); // Return the new root of the tree
}

