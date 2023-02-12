
#include <stdio.h>
#include <string.h>
#include "dico.h"
#include "arbreTerminalPrint.h"
/* ------------------------------------------------------- */
int main(){

    TArbre dico;
    char buffer[100];
    dico = arbreConsVide();
    strcpy(buffer, "gal");
    dicoInsererMot(buffer, &dico);
    dicoAfficher(dico);
    printf("\n");

    strcpy(buffer, "mu");
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
    strcpy(buffer, "al");
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
    printf("Nb mots total : %d\n", dicoNbMotsTotal(dico));
    printf("Nb mots differents : %d\n", dicoNbMotsDifferents(dico));



    print2D(dico);

    return 0;
}