#ifndef __TREE__H__
#define __TREE__H__

#include <stdio.h>
#include <stdlib.h>

typedef struct TArbre
{
    char val;
    struct TArbre *fg;
    struct TArbre *fd;
    struct TArbre *parent;
}TArbre;
TArbre *arbreConsVide(char val);
int arbreEstVide(TArbre * ta);
TArbre *arbreCons(char c, TArbre * fg, TArbre * fd);
char arbreRacineLettre(TArbre *a);
TArbre *arbreFilsGauche(TArbre *a);
TArbre *arbreFilsDroit(TArbre *a);
void arbreSuppr(TArbre * ta);
void Affiche_arbre_prefix(TArbre *ta);
#endif // __TREE__H__
