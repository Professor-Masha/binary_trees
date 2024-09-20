#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/* Queue structure to hold nodes for level-order traversal */
typedef struct queue_node {
    binary_tree_t *tree_node;
    struct queue_node *next;
} queue_node_t;

typedef struct queue {
    queue_node_t *front;
    queue_node_t *rear;
} queue_t;

/* Function to create a new queue */
queue_t *create_queue() {
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue)
        return NULL;
    queue->front = queue->rear = NULL;
    return queue;
}

/* Function to check if the queue is empty */
int is_empty(queue_t *queue) {
    return queue->front == NULL;
}

/* Function to enqueue a node */
void enqueue(queue_t *queue, binary_tree_t *node) {
    queue_node_t *new_node = malloc(sizeof(queue_node_t));
    if (!new_node)
        return;
    new_node->tree_node = node;
    new_node->next = NULL;

    if (queue->rear) {
        queue->rear->next = new_node;
    } else {
        queue->front = new_node; // If queue was empty
    }
    queue->rear = new_node;
}

/* Function to dequeue a node */
binary_tree_t *dequeue(queue_t *queue) {
    if (is_empty(queue))
        return NULL;

    queue_node_t *temp = queue->front;
    binary_tree_t *node = temp->tree_node;
    queue->front = queue->front->next;

    if (!queue->front)
        queue->rear = NULL; // Queue is now empty

    free(temp);
    return node;
}

/* Function to destroy the queue */
void destroy_queue(queue_t *queue) {
    while (!is_empty(queue)) {
        dequeue(queue);
    }
    free(queue);
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to the function to call for each node's value
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int)) {
    queue_t *queue;
    binary_tree_t *current;

    if (tree == NULL || func == NULL)
        return;

    queue = create_queue();  // Initialize the queue
    enqueue(queue, (binary_tree_t *)tree);  // Add the root to the queue

    while (!is_empty(queue)) {  // While there are nodes to process
        current = dequeue(queue);  // Get the front node
        func(current->n);  // Call the function with the node's value

        // Enqueue left child
        if (current->left)
            enqueue(queue, current->left);

        // Enqueue right child
        if (current->right)
            enqueue(queue, current->right);
    }

    destroy_queue(queue);  // Free the queue resources
}

