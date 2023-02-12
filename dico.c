#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dico.h"
#include "arbreTerminalPrint.h"
#include <time.h>


/* ------------------------------------------------------- */
/* Ent�tes des fonctions locales � cette biblioth�que      */
/* ------------------------------------------------------- */

void _dicoAfficher(TArbre a, char prefixe[], int pos);
void _dicoInsererMot(char mot[], int debut, TArbre *pa);
int  _dicoNbOcc(char mot[], int debut, TArbre a);
int  _dicoNbMotsTotal(TArbre a);
int  _dicoNbMotsDifferents(TArbre a);




/* ------------------------------------------------------- */
/* Primitives de gestion d'un dictionnaire                 */
/* ------------------------------------------------------- */

void dicoAfficher(TArbre a)
{
  char buffer[100];

  _dicoAfficher(a, buffer, 0);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void dicoInsererMot(char mot[], TArbre *pa)
{
  _dicoInsererMot(mot, 0, pa);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int dicoNbOcc(char mot[], TArbre a)
{
  return _dicoNbOcc(mot, 0, a);
}

int dicoNbMotsTotal(TArbre a)
{
    char buffer[100];

    return _dicoNbMotsTotal(a);
}

int dicoNbMotsDifferents(TArbre a)
{
    char buffer[100];

    return _dicoNbMotsDifferents(a);
}

/* ------------------------------------------------------- */
/* Ent�tes des fonctions locales � cette biblioth�que      */
/* ------------------------------------------------------- */

void _dicoAfficher(TArbre a, char prefixe[], int pos)
{
  if (!arbreEstVide(a))
    {
      prefixe[pos] = arbreRacineLettre(a);

      if (arbreRacineLettre(a) == '\0')
	printf("\"%s\" [%d]\n", prefixe, arbreRacineNbOcc(a));

      _dicoAfficher(arbreFilsGauche(a), prefixe, pos+1);
      _dicoAfficher(arbreFilsDroit(a), prefixe, pos);
    }
}

int _dicoNbMotsTotal(TArbre a )
{
    if (a == NULL)
        return 0;

    if (arbreRacineLettre(a) == '\0'){
        return a->nbOcc + _dicoNbMotsTotal(a->fg) + _dicoNbMotsTotal(a->fd) ;
    }
    return _dicoNbMotsTotal(a->fg) + _dicoNbMotsTotal(a->fd);
}

int _dicoNbMotsDifferents(TArbre a )
{
    if (a == NULL)
        return 0;

    if (arbreRacineLettre(a) == '\0'){
        return 1 + _dicoNbMotsDifferents(a->fg) + _dicoNbMotsDifferents(a->fd) ;
    }
    return _dicoNbMotsDifferents(a->fg) + _dicoNbMotsDifferents(a->fd);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void _dicoInsererMot(char mot[], int debut, TArbre *pa)
{
  if (arbreEstVide(*pa))
    /* 1er cas: le dictionnaire est vide */
    {
      *pa = arbreCons(mot[debut], 0, arbreConsVide(), arbreConsVide());
      if (debut == strlen(mot))
	((*pa)->nbOcc)++;
      else
	_dicoInsererMot(mot, debut+1, &((*pa)->fg));
    }
  else if (mot[debut] < arbreRacineLettre(*pa))
    /* 2�me cas: le mot doit �tre plac� au d�but du dictionnaire */
    {
      *pa = arbreCons(mot[debut], 0, arbreConsVide(), *pa);
      if (debut == strlen(mot))
	((*pa)->nbOcc)++;
      else
	_dicoInsererMot(mot, debut+1, &((*pa)->fg));
    }
  else if (mot[debut] > arbreRacineLettre(*pa))
    /* 3�me cas: le mot ne commence pas par la m�me lettre que le */
    /* premier mot (courant) du dictionnaire */
    {
      _dicoInsererMot(mot, debut, &((*pa)->fd));
    }
  else
    /* 4�me cas: le mot � ins�rer commence par la m�me lettre que */
    /* le premier mot (courant) du dictionnaire */
    {
      if (debut == strlen(mot))
	((*pa)->nbOcc)++;
      else
	_dicoInsererMot(mot, debut+1, &((*pa)->fg));
    }
}

int piocherMot(char *motPioche)
{

    FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier

    int nombreMots = 0, numMotChoisi = 0, i = 0;

    int caractereLu = 0;

    dico = fopen("dico.txt", "r"); // On ouvre le dictionnaire en lecture seule

    // On vérifie si on a réussi à ouvrir le dictionnaire

    if (dico == NULL) // Si on n'a PAS réussi à ouvrir le fichier
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0; // On retourne 0 pour indiquer que la fonction a échoué
        // À la lecture du return, la fonction s'arrête immédiatement.
    }



    // On compte le nombre de mots dans le fichier (il suffit de compter les

    // entrées \n

    do
    {
        caractereLu = fgetc(dico);

        if (caractereLu == '\n')

            nombreMots++;

    } while(caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard



    // On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivé au bon mot

    rewind(dico);

    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }
    /* Le curseur du fichier est positionné au bon endroit.

    On n'a plus qu'à faire un fgets qui lira la ligne */

    fgets(motPioche, 100, dico);

    // On vire le \n à la fin

    motPioche[strlen(motPioche) - 1] = '\0';

    fclose(dico);



    return 1; // Tout s'est bien passé, on retourne 1

}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int _dicoNbOcc(char mot[], int debut, TArbre a)
{
  if (arbreEstVide(a))
    /* 1er cas: le dictionnaire est vide */
    return 0;
  else if (debut > strlen(mot))
    /* 2�me cas: le mot tel quel n'existe pas */
    return 0;
  else if (mot[debut] < arbreRacineLettre(a))
    /* 3�me cas: le mot cherch� aurait d� �tre avant dans le dico */
    return 0;
  else if (mot[debut] == arbreRacineLettre(a))
    /* 4�me cas: le mot commence par la m�me lettre que le premier */
    /* mot du dictionnaire */
    if (mot[debut] == '\0')
      return arbreRacineNbOcc(a);
    else
      return _dicoNbOcc(mot, debut+1, arbreFilsGauche(a));
  else
    /* 5 �me cas: le mot est �ventuellement plus loin dans le dico */
    return _dicoNbOcc(mot, debut, arbreFilsDroit(a));
}

