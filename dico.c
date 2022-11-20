#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dico.h"



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
/*
void arbreSupprUtilDoublePointer(TArbre a){
    if (!arbreEstVide(a)){
    arbreSupprUtil(a->fg);
    arbreSupprUtil(a->fd);
    free(a);
  }
}

void arbreSupprDoublePointer(TArbre* p){
  arbreSupprUtil(*p);
  *p = NULL;
}
*/
void arbreSuppr(TArbre a){
    if (!arbreEstVide(a)){
    arbreSuppr(a->fg);
    a->fg = NULL;
    arbreSuppr(a->fd);
    a->fd = NULL;
    free(a);
  }
}

/* ------------------------------------------------------- */
/* Ent�tes des fonctions locales � cette biblioth�que      */
/* ------------------------------------------------------- */

void _dicoAfficher(TArbre a, char prefixe[], int pos);
void _dicoInsererMot(char mot[], int debut, TArbre *pa);
int  _dicoNbOcc(char mot[], int debut, TArbre a);



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
    if (arbreEstVide(a))
    {
	return 0;
    }    
    else
    { 
       return (dicoNbMotsTotal(a->left) + dicoNbMotsTotal(a->right) + 1);
    }
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

/* ------------------------------------------------------- */
int main(){

  TArbre treeOne = arbreCons('e', 15, NULL, NULL);
  TArbre treeTwo = arbreCons('f', 16, NULL, NULL);
  TArbre treeThree = arbreCons('g', 17, treeOne, treeTwo);
  arbreSuppr(treeTwo);
  treeTwo = NULL;
 // arbreSuppr(treeTwo);
  int vide = arbreEstVide(treeTwo);


  TArbre dico;
  char buffer[100];
  dico = arbreConsVide();
  strcpy(buffer, "gallon");
  dicoInsererMot(buffer, &dico);
  dicoAfficher(dico);
  printf("\n");

  strcpy(buffer, "munier");
  dicoInsererMot(buffer, &dico);
  dicoAfficher(dico);
  printf("\n");
  strcpy(buffer, "abenia");
  dicoInsererMot(buffer, &dico);
  dicoAfficher(dico);
  printf("\n");
  strcpy(buffer, "munier");
  dicoInsererMot(buffer, &dico);
  dicoAfficher(dico);
  printf("\n");
  strcpy(buffer, "mumu");
  dicoInsererMot(buffer, &dico);
  dicoAfficher(dico);
  printf("\n");
  strcpy(buffer, "alpha");
  dicoInsererMot(buffer, &dico);
  strcpy(buffer, "alphabeta");
  dicoInsererMot(buffer, &dico);
  strcpy(buffer, "al");
  dicoInsererMot(buffer, &dico);
  dicoAfficher(dico);
  printf("\n");
  printf("\"%s\" \t -> %d\n", "gallon", dicoNbOcc("gallon",dico));
  printf("\"%s\" \t\t -> %d\n", "mumu", dicoNbOcc("mumu",dico));
  printf("\"%s\" \t -> %d\n", "munier", dicoNbOcc("munier",dico));
  printf("\"%s\" \t -> %d\n", "gastro", dicoNbOcc("gastro",dico));
  printf("\"%s\" \t -> %d\n", "lespine", dicoNbOcc("lespine",dico));
  printf("\"%s\" \t\t -> %d\n", "aaa", dicoNbOcc("aaa",dico));
  printf("\n");

  return 0;
}
