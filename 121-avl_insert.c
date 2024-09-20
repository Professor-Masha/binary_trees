#include "binary_trees.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* Remove binary_tree_balance function from here */

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + MAX(height(tree->left), height(tree->right)));
}

/**
 * rotate_left - Performs a left rotation on a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Pointer to the new root
 */
binary_tree_t *rotate_left(binary_tree_t *tree)
{
    binary_tree_t *new_root = tree->right;

    tree->right = new_root->left;
    if (new_root->left)
        new_root->left->parent = tree;
    
    new_root->parent = tree->parent;
    new_root->left = tree;
    tree->parent = new_root;

    return (new_root);
}

/**
 * rotate_right - Performs a right rotation on a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Pointer to the new root
 */
binary_tree_t *rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root = tree->left;

    tree->left = new_root->right;
    if (new_root->right)
        new_root->right->parent = tree;

    new_root->parent = tree->parent;
    new_root->right = tree;
    tree->parent = new_root;

    return (new_root);
}

/**
 * avl_insert - Inserts a value in an AVL Tree and ensures it remains balanced
 * @tree: Double pointer to the root node of the AVL tree for inserting the value
 * @value: Value to insert
 *
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node;

    /* If the tree is empty, create a new node */
    if (*tree == NULL)
        return (*tree = binary_tree_node(NULL, value));

    /* Insert the node as in a regular BST */
    if (value < (*tree)->n)
    {
        new_node = avl_insert(&(*tree)->left, value);
        (*tree)->left->parent = *tree;
    }
    else if (value > (*tree)->n)
    {
        new_node = avl_insert(&(*tree)->right, value);
        (*tree)->right->parent = *tree;
    }
    else
        return (NULL); /* Value already exists in the tree */

    /* Update balance and perform rotations if necessary */
    int balance = binary_tree_balance(*tree);

    /* Left Left Case */
    if (balance > 1 && value < (*tree)->left->n)
        return (rotate_right(*tree));

    /* Right Right Case */
    if (balance < -1 && value > (*tree)->right->n)
        return (rotate_left(*tree));

    /* Left Right Case */
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = rotate_left((*tree)->left);
        return (rotate_right(*tree));
    }

    /* Right Left Case */
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = rotate_right((*tree)->right);
        return (rotate_left(*tree));
    }

    return (new_node);
}

