//
// Created by Mega-PC on 2/12/2023.
//
// Program to print binary tree in 2D
#include <malloc.h>
#include <stdio.h>
#include "arbre.h"
#define COUNT 4

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct TElement* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->fd, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%c\n", root->lettre);

    // Process left child
    print2DUtil(root->fg, space);
}

// Wrapper over print2DUtil()
void print2D(struct TElement* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

// Driver program to test above functions
