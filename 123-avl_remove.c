#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: pointer to the root node of the tree
 * @value: value to remove
 * Return: pointer to the new root node after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *temp;

    if (!root)
        return NULL;

    if (value < root->n)
    {
        root->left = avl_remove(root->left, value);
    }
    else if (value > root->n)
    {
        root->right = avl_remove(root->right, value);
    }
    else
    {
        // Node with only one child or no child
        if (!root->left)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor
        temp = root->right;
        while (temp && temp->left)
            temp = temp->left;

        // Copy the in-order successor's content to this node
        root->n = temp->n;

        // Delete the in-order successor
        root->right = avl_remove(root->right, temp->n);
    }

    // Update the height of the current node
    root->height = 1 + MAX(height(root->left), height(root->right));

    // Rebalance the tree
    return rebalance(root);
}

/**
 * rebalance - Rebalances the AVL tree
 * @root: pointer to the root node of the tree
 * Return: pointer to the new root node after rebalancing
 */
avl_t *rebalance(avl_t *root)
{
    int balance = binary_tree_balance(root);

    // Left Left Case
    if (balance > 1 && binary_tree_balance(root->left) >= 0)
        return binary_tree_rotate_right(root);

    // Right Right Case
    if (balance < -1 && binary_tree_balance(root->right) <= 0)
        return binary_tree_rotate_left(root);

    // Left Right Case
    if (balance > 1 && binary_tree_balance(root->left) < 0)
    {
        root->left = binary_tree_rotate_left(root->left);
        return binary_tree_rotate_right(root);
    }

    // Right Left Case
    if (balance < -1 && binary_tree_balance(root->right) > 0)
    {
        root->right = binary_tree_rotate_right(root->right);
        return binary_tree_rotate_left(root);
    }

    return root; // Return the (unchanged) node pointer
}

