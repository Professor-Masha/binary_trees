#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL || tree->left == NULL)
        return (tree);

    new_root = tree->left; // The new root is the current left child
    tree->left = new_root->right; // The right child of new root becomes the left child of current root

    if (new_root->right != NULL) // If new root has a right child
        new_root->right->parent = tree; // Set its parent to the current root

    new_root->parent = tree->parent; // Set the new root's parent to the current root's parent

    if (tree->parent == NULL) // If current root is the root of the tree
        ; // Update the actual root pointer if necessary

    else if (tree == tree->parent->right) // Update parent's right child if needed
        tree->parent->right = new_root;

    else // Update parent's left child if needed
        tree->parent->left = new_root;

    new_root->right = tree; // Set the current root as the right child of the new root
    tree->parent = new_root; // Update the current root's parent to the new root

    return (new_root); // Return the new root of the tree
}

