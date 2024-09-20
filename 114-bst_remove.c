#include "binary_trees.h"

/**
 * bst_min_value_node - Finds the node with the minimum value in a BST.
 * @node: The pointer to the root node of the subtree.
 * 
 * Return: A pointer to the node with the minimum value.
 */
bst_t *bst_min_value_node(bst_t *node)
{
    bst_t *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: A pointer to the root node of the BST.
 * @value: The value to be removed from the BST.
 * 
 * Return: A pointer to the new root node after the removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *temp = NULL;

    if (root == NULL)
        return (NULL);

    /* Traverse to find the node to be deleted */
    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        /* Node to be deleted found */

        /* Case 1: Node with only one child or no child */
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return (temp);
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return (temp);
        }

        /* Case 2: Node with two children */
        temp = bst_min_value_node(root->right);

        /* Replace root's value with the minimum value in the right subtree */
        root->n = temp->n;

        /* Delete the in-order successor */
        root->right = bst_remove(root->right, temp->n);
    }
    return (root);
}

