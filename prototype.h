//
//  prototype.h
//
//
//  Created on 1/21/20.
//

#ifndef prototype_h
#define prototype_h


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


typedef enum {true, false} bool; // On va définir le type booléan pour faciliter la manipulation.

typedef struct Clr{
    char* color;
    //JAUNE,BLUE,ROUGE,GRIS
}Couleur;


typedef struct Case{
    char* val;
    Couleur c;
}casemot;

/* random int between 0 and N :
 int r = rand() % N;              */
char* Aleatoire_Lecture_Dicto(void);

int Best_score(void);//cherche dans un fichier le meilleur score enregistré dans les parties précédentes


void Timer1(int seconds); // le temps de réflexion en seconds



bool validate(char *mot,int longeur); //cette fonction vérifie le mot saisi dans la grille
    //renvoie TRUE si seulement si les 8 caractères sont alphabétiques

          
char *saisir_mot(int longeur);
    //Ne sortir de la boucle que si le mot tapée est valide et que
    //le caractère saisie dans la position 8 est bien le caractère   // ENTER dont le code ASCII est 13


casemot** Matrice_mot(void);
    



void initialiser_partie(void);
    
//pour commencer une nouvelle partie une fois le mot en question est trouvé

void Inserer_mot(int tentative,casemot** M);

//void score(void);

bool Verifier_existance_dicto(char* mot);
    //parcourir le dictionnaire et vérifier l'existance du mot proposé
   


void MENU(void);
    // Nouvellepartie(); Initialisation du partie.
  
    


#endif /* prototype_h */

