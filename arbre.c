#include "arbre.h"

TArbre *arbreConsVide(char val)
{
    TAbre *ta = malloc(sizeof(*ta));
    if(ta == NULL)
    {
        fprintf(stderr,"Erreur allocation memoire.\n");
        exit(EXIT_FAILURE);
    }

    ta->val = val;
    ta->fg = NULL;
    ta->fd = NULL;
    ta->parent = NULL;

    printf("Creation de %c\n", ta->val);

    return ta;
}

int arbreEstVide(TArbre * ta)
{
    if (ta == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


void arbreSuppr(TArbre * ta)
{
    if (arbreEstVide(ta)==0)
        return;

    printf("Suppression de %c\n", ta->val);

    arbreSuppr(ta->fg);
    arbreSuppr(ta->fd);

    free(ta);

}


TArbre *arbreCons(char c, TArbre * fg, TArbre * fd)
{
    TArbre *ta = arbreConsVide(c);
    ta->fg=fg;
    ta->fd=fd;

    if(arbreEstVide(fg) == 1)
    {
        fg->parent = ta;
    }

    if(arbreEstVide(fd) == 1)
    {
        fd->parent = ta;
    }

    return ta;
}


char arbreRacineLettre(TArbre *a)
{
    if ( arbreEstVide(a)==0)
    {
        return;
    }
    else
    {
        return a->val;
    }
}


TArbre *arbreFilsGauche(TArbre *a)
{
    if(arbreEstVide(a)==0)
    {
        return;
    }
    else
    {
        return a->fg;
    }
}

TArbre *arbreFilsDroit(TArbre *a)
{
    if(arbreEstVide(a)==0)
    {
        return;
    }
    else
    {
        return a->fd;
    }
}

void Affiche_arbre_prefix(TArbre *ta)
{
    if(arbreEstVide(ta)==0)
        return;

    if(arbreEstVide(ta->parent)==1)
        printf("(%c) -> (%c)\n",ta->parent->, ta->val);
    else
        printf("(%c)\n", ta->val);

    if(arbreEstVide(ta->fg)==1)
    {
        Affiche_arbre_prefix(ta->fg);
    }
    if(arbreEstVide(ta->fd)==1)
    {
        Affiche_arbre_prefix(ta->fd);
    }
}




