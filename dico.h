#include "arbre.h"

/* ------------------------------------------------------- */
/* Primitives de gestion d'un dictionnaire                 */
/* ------------------------------------------------------- */

void dicoAfficher(TArbre a);
void dicoInsererMot(char mot[], TArbre *pa);
int  dicoNbOcc(char mot[], TArbre a);
int dicoNbMotsDifferents(TArbre a);
int dicoNbMotsTotal(TArbre a);
int piocherMot(char *motPioche);
int nombreAleatoire(int nombreMax);

