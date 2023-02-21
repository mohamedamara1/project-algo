
#include <stdio.h>
#include <string.h>
#include "dico.h"
#include "arbreTerminalPrint.h"
#include "arbreAfficherVertical.h"

/* ------------------------------------------------------- */
int main(){
    TArbre dico;
    dico = arbreConsVide();
    int choice = -1;
    char buffer[100];

    while (choice != 0){
        printf("Welcome user, please choose a number to proceed\n");
        printf("1 - Create dictionary from text file\n");
        printf("2 - Create dictionary from user input\n");
        printf("3 - Print dictionary\n");
        printf("4 - Print number of different words in dictionary\n");
        printf("5 - Print total number of words\n");
        printf("6 - Print number of occurrences of a given word by you\n");
        if (scanf("%d", &choice) != 1) { // Check if input is valid
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue; // Restart the loop
        }

        switch(choice){
            case 1 :
                printf("Creating dictionary from text file\nEnter text file name\n");
                break;
            case 2 :
                printf("Creating dictionary from strings entered by the user \nPress q to stop inserting\n");
                getchar();
                char input[100];
                char stopString[] = "q\n";
                while (1) {
                    printf("Enter a string:");
                    fgets(input, sizeof(input), stdin);

                    if (strcmp(input, stopString) == 0) {
                        printf("Stopping...\n");
                        break;
                    }
                    strcpy(buffer, input);
                    printf("Input string is: %s", input);
                    dicoInsererMot(buffer,  &dico);
                }
                break;

            case 3:
                printf("Printing dictionary\n");
                print2D(dico);
                break;
            case 4 :
                printf("Printing number of different words in the dictionary..\n%d\n", dicoNbMotsDifferents(dico));
                break;
            case 5 :
                printf("Printing total number of words in the dictionary..\n");
                printf("%d\n", dicoNbMotsTotal(dico));
                break;
            case 6 :
                printf("You chose printing number of occurrences of a given word by you..\nEnter the word:\n");
                getchar();
                fgets(buffer, sizeof(buffer), stdin);
                printf("Number of occurrences: %d\n", dicoNbOcc(buffer, dico));


                break;
            default :
                printf("No chosen number\n");
        }
    }
    printf("You chose option number %d\n", choice);


    return 0;
}