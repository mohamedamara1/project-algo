#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"



TArbre arbreConsVide(void){
    return NULL;
}

int arbreEstVide(TArbre a){
    return (a==NULL);
}

TArbre arbreCons(char c, int n, TArbre fg, TArbre fd){
    TArbre newTree;
    newTree = (TArbre)malloc(sizeof (struct TElement));
    newTree->lettre     = c;
    newTree->nbOcc      = n;
    newTree->fg = fg;
    newTree->fd  = fd;
    return newTree;
}

char arbreRacineLettre(TArbre a){
    return a->lettre;
}

int arbreRacineNbOcc(TArbre a){
    return a->nbOcc;
}

TArbre arbreFilsGauche(TArbre a){
    return a->fg;
}


TArbre arbreFilsDroit(TArbre a){
    return a->fd;
}

void arbreSuppr(TArbre a){
    if (!arbreEstVide(a)){
        arbreSuppr(a->fg);
        a->fg = NULL;
        arbreSuppr(a->fd);
        a->fd = NULL;
        free(a);
        a=NULL;
    }
}
