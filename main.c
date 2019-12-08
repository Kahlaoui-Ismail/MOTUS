#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ENTER 13

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
void Aleatoire_Lecture_Dicto(){  //Cette fonction est toujours incomplét, le mot n'est pas choisie d'une façon aléatoire
                  		 //et penser à retourner le mot choisie au lieu d'utiliser VOID.
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


casemot** Matrice_mot(){
    
    casemot **M;
    M = (casemot**)malloc(7*sizeof(casemot*));
    for (int i = 0 ; i < 7 ; i++){
        M[i] = (casemot*)malloc(8*sizeof(casemot));
    }
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 8; j++){
                M[i][j].val="."; // Initialisation de la matrice
                M[i][j].c.color="GRIS";//tous est en gris et contient la
            }                            // valeur "."
        }
    return M;
}


void initialiser_partie(){
    
}//pour commencer une nouvelle partie une fois le mot en question est trouvé

void Inserer_mot(int tentative,casemot** M){
    
    char *mot_a_trouver=Aleatoire_Lecture_Dicto();
    char *mot_saisie=saisir_mot();
    
    if(tentative==0){
        M=Matrice_mot();
    }
    else if(tentative==7){
        printf("Vous avez échouée");
        
    }
    else{
        int casecorrect=0;
        for(int i=0;i<8;i++){
            if(mot_a_trouver[i]==mot_saisie[i]){
                M[tentative][i].val=&mot_saisie[i];
                M[tentative][i].c.color="ROUGE";
                casecorrect++;
            }
            else if(strstr(mot_a_trouver,&mot_saisie[i])==NULL){//La
                M[tentative][i].val=&mot_saisie[i]; //lettre n'existe
                M[tentative][i].c.color="BLUE";//pas dans le mot à
            }                               //trouver
            else{
                M[tentative][i].val=&mot_saisie[i];
                M[tentative][i].c.color="JAUNE";
            }
        }
        if(casecorrect==8){// à la sortie de la boucle si le nombre
            printf("Vous avez gagné la partie");//de case coloré en ROUGE
        } // est égale à 8 -> mot correcte
    }
    
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
