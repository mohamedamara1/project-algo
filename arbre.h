struct TElement {
  char lettre;
  int  nbOcc;
  struct TElement* fg;
  struct TElement* fd;
};

typedef struct TElement* TArbre;

/* -------------------------------------------------------*/ 
/* Primitives de gestion des arbres */ 
/* -------------------------------------------------------*/ 

TArbre arbreConsVide(void);
int    arbreEstVide(TArbre a);
TArbre arbreCons(char c, int n, TArbre fg, TArbre fd);
char   arbreRacineLettre(TArbre a);
int    arbreRacineNbOcc(TArbre a);
TArbre arbreFilsGauche(TArbre a);
TArbre arbreFilsDroit(TArbre a);
void   arbreSuppr(TArbre a);
