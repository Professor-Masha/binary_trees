#include "binary_trees.h"

// Function declarations
avl_t *min_value_node(avl_t *node);
avl_t *rotate_right(avl_t *y);
avl_t *rotate_left(avl_t *x);
int binary_tree_balance(const avl_t *tree);

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: A pointer to the root node of the tree
 * @value: The value to remove from the tree
 *
 * Return: A pointer to the new root node of the tree after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *temp;

    if (root == NULL)
        return (NULL);

    // Perform the standard BST delete
    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        // Node with only one child or no child
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

        // Node with two children: Get the in-order successor
        temp = min_value_node(root->right);
        root->n = temp->n; // Copy the in-order successor's content
        root->right = avl_remove(root->right, temp->n); // Delete the in-order successor
    }

    // Update height and balance the tree
    int balance = binary_tree_balance(root);

    // Left Left Case
    if (balance > 1 && binary_tree_balance(root->left) >= 0)
        return rotate_right(root);

    // Left Right Case
    if (balance > 1 && binary_tree_balance(root->left) < 0)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    // Right Right Case
    if (balance < -1 && binary_tree_balance(root->right) <= 0)
        return rotate_left(root);

    // Right Left Case
    if (balance < -1 && binary_tree_balance(root->right) > 0)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

/**
 * min_value_node - Helper function to find the node with the minimum value
 * in a given subtree
 * @node: Pointer to the root node of the subtree
 *
 * Return: Pointer to the node with the minimum value
 */
avl_t *min_value_node(avl_t *node)
{
    avl_t *current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

