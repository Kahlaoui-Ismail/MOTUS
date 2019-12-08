#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ENTER 13

typedef enum {true, false} bool; // On va définir le type booléan pour faciliter la manipulation.

typedef struct Couleur{
    char couleur[7];
    //JAUNE,BLUE,ROUGE
}Clr;


typedef struct Case{
    char val;
    Couleur c;
}casemot;



/* random int between 0 and N : 
 int r = rand() % N;              */
void Aleatoire_Lecture_Dicto(){  
                   
   FILE *fPointer ; 
      
    
    char le_mot_aléatoire[9]; 
  
    
    filePointer = fopen("dictionnaire.txt", "r") ; 
    while(!feof(fpointer){                        //permet de lire le fichier ligne par ligne donc mot par mot  !!!!   
    fgets(le_mot_aléatoire,9,fpointer);
    puts(le_mot_aléatoire);
         
        fclose(filePointer) ; 
          
    } 
    return 0;   
          };


          
void Minuteur(int seconds){ // le temps de réflexion en seconds
    int mseconds;
    mseconds=1000000*seconds; // la fonction qu'on va employer mesure le temps en Microseconds, d'où la multiplication par 1M
    clock_t start=clock();    // Cette définition du temps peut varier d'une machine à une autre
    while(clock()<start+mseconds)
  ;
}
/*   AUTRE PROPOSITION POUR LA FONCTION MINUTEUR=> AFFICHE LE NOMBRE DE SECONDES RESTANTES 
VOID MINUTEUR (){
	unsigned int x_hours=0;
	unsigned int x_minutes=0;
	unsigned int x_seconds=0;
	unsigned int x_milliseconds=0;
	unsigned int totaltime=0,count_down_time_in_secs=0,time_left=0;

	clock_t x_startTime,x_countTime;
	count_down_time_in_secs=20;  // 1 minute is 60, 1 hour is 3600


    x_startTime=clock();  // start clock
    time_left=count_down_time_in_secs-x_seconds;   // update timer

	while (time_left>0)
	{
		x_countTime=clock(); // update timer difference
		x_milliseconds=x_countTime-x_startTime;
		x_seconds=(x_milliseconds/(CLOCKS_PER_SEC))-(x_minutes*60);
		x_minutes=(x_milliseconds/(CLOCKS_PER_SEC))/60;
		x_hours=x_minutes/60;
        time_left=count_down_time_in_secs-x_seconds; // subtract to get difference
        printf( "\nYou have %d seconds left ( %d )",time_left,count_down_time_in_secs);
	}
  
  printf( "\n\n\nTime's out\n\n\n");
  return 0;
}
*/


bool validate(char *mot){  //cette fonction vérifie le mot saisi dans la grille
    if(strlen(mot)!=9){    //Doit contenir 8 caractères alphabétiques et le caractère ENTER
        return false;
    }
    else{
        for(int i=0;i<strlen(mot)-2;i++){ // On vérifie que le 8 caractères sont alphabétique(la validation du caractère     ENTER
            if(isalpha(mot[i])==0){       // ENTER se fait dans la fonction saisir_mot()
                return false;
            }
        }
    }
    return true; //renvoie TRUE si seulement si les 8 caractères sont alphabétiques
}
          
char *saisir_mot(){
    char *mot ;
    int enter;
    mot=(char *)malloc(sizeof(char));

        
do{
        
        printf("Faites saisir un mot valide");
        scanf("%s",mot);
        enter=mot[8];
        }while(enter!=ENTER || validate(mot)==false); //Ne sortir de la boucle que si le mot tapée est valide et que 
          return mot;                                 //le caractère saisie dans la position 8 est bien le caractère
}                                                     // ENTER dont le code ASCII est 13


void Matrice_mot(){  // il faut définir une matrice initiale où les cases ont une couleur NULLE
    casemot M[7][8];//<!>TO DELETE<!> cette déclaration est erroné pour la corriger:il faut remplir casemot par les éléments M[i][i] telque chaque case ait sa couleur+val 
    /* à remplacer par*/
    char M[7][8];// attribution se fera après , c'est comme avoir une matrice de structures...
    char*mot_aléatoire;
    for(int i=0;i<7;++i){
        for(int j=0;i<7;++j){
            strcopy(M[i][j],*(mot_aléatoire+j));
            strcpy(casemot.val,M[i][j]);
            strcpy(casemot.couleur,NULLE);
    
                   // toute vérification, attribution de couleur se fait dans cette matrice 
}

void initialiser_partie(){
    
}//pour commencer une nouvelle partie une fois le mot en question est trouvé

void check_color_case(){
     if(lettre_bien_placée()==true){   //Reste  à définir les fonctions suivantes: lettre_bien_placée , lettre_non_existante, mot_trouvé
        couleur_lettre="rouge";
    }else{
        couleur_lettre="jaune";
    }
    if(lettre_non_existante()==true){
        couleur_lettre="bleue";}
    //prend 1 lettre saisie et le mot aléatoire
    //Attribuer JAUNE SI mal-placée
    //Attribuer ROUGE SI CORRECTE
    //Attribuer BLUE SI non existants
}

void score(){
    int score_partie=0;
    if(verifier_existance_dicto(char*mot_inseré)==false){
        score_partie-=4;//(-4) for a non existent word
      };
    if(lettre_bien_placée()==true){
        score_partie+=2;// !!!!!<?> pour le tableau des scores chaque niveau de difficulté a sa propre notation donc on optera pour la notation du niv facile....
    }else{
        score_partie+=1;
    }
    if(mot_trouvé()==true){
        score_partie+=6;
    }
    if(mot_déjà_proposé()==true){
        score_partie-=10;
}


boolean verifier_existance_dicto(){
    //parcourir le dictionnaire et vérifier l'existance du mot proposé
    Non existant = false;
    existant = true;
}

void MENU(){
    // Nouvellepartie(); Initialisation du partie.
    Minuteur();
    
    int i=0;
    while(i<7 && motvalide(saisir_mot())){
        
        saisir_mot();
        
        check(Aleatoire_Lecture_Dicto(),saisir_mot());
        Actualiser score();
            }
    i++;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
