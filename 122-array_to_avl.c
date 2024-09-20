#include "binary_trees.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* Function prototypes */
static avl_t *insert(avl_t **tree, int value);
static int height(const avl_t *tree);
static int get_balance(const avl_t *tree);

/* Function to get the height of a tree */
static int height(const avl_t *tree)
{
    if (!tree)
        return 0;
    return MAX(height(tree->left), height(tree->right)) + 1;
}

/* Function to get the balance factor of a tree */
static int get_balance(const avl_t *tree)
{
    if (!tree)
        return 0;
    return height(tree->left) - height(tree->right);
}

/* Function to insert a value into the AVL tree */
static avl_t *insert(avl_t **tree, int value)
{
    if (!tree)
        return NULL;

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    if (value < (*tree)->n)
        (*tree)->left = insert(&(*tree)->left, value);
    else if (value > (*tree)->n)
        (*tree)->right = insert(&(*tree)->right, value);
    else
        return *tree;  // Duplicate values are not allowed

    /* Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = get_balance(*tree);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && value < (*tree)->left->n)
        return binary_tree_rotate_right(*tree);

    // Right Right Case
    if (balance < -1 && value > (*tree)->right->n)
        return binary_tree_rotate_left(*tree);

    // Left Right Case
    if (balance > 1 && value > (*tree)->left->n)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        return binary_tree_rotate_right(*tree);
    }

    // Right Left Case
    if (balance < -1 && value < (*tree)->right->n)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        return binary_tree_rotate_left(*tree);
    }

    return *tree;  // Return the (unchanged) node pointer
}

/* Function to build the AVL tree from the array */
avl_t *array_to_avl(int *array, size_t size)
{
    avl_t *tree = NULL;
    size_t i;

    for (i = 0; i < size; i++)
    {
        insert(&tree, array[i]);
    }

    return tree;
}

