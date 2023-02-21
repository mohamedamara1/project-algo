//
// Created by Mega-PC on 2/21/2023.
//
#include "arbre.h"
#include <malloc.h>
#include <stdio.h>
#include <math.h>

int height(TArbre root) {
    if (root == NULL)
        return 0;
    return fmax(height(root->fg), height(root->fd)) + 1;
}

int getcol(int h) {
    if (h == 1)
        return 1;
    return getcol(h - 1) + getcol(h - 1) + 1;
}

void printTree(char **M, TArbre root, int col, int row, int height) {
    if (root == NULL)
        return;
    M[row][col] = root->lettre;
    printTree(M, root->fg, col - pow(2, height - 2), row + 1, height - 1);
    printTree(M, root->fd, col + pow(2, height - 2), row + 1, height - 1);
}

void TreePrinter(struct TElement* tree) {
    int h = height(tree);
    int col = getcol(h);
    char **M = (char **)malloc(h * sizeof(char *));
    for (int i = 0; i < h; i++) {
        M[i] = (char *)malloc(col * sizeof(char));
    }
    printTree(M, tree, col / 2, 0, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < col; j++) {
            if (M[i][j] == 0)
                printf("  ");
            else
                printf("%c ", M[i][j]);
        }
        printf("\n");
    }
}