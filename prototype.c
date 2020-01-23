//
//  prototype.c
//
//
//  Created on 1/21/20.
//

#include "prototype.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ENTER 13




/* random int between 0 and N :
 int r = rand() % N;              */
char* Aleatoire_Lecture_Dicto(){
    char* num;
    num=(char*)malloc(sizeof(char));
 
    FILE *fp;
    time_t t;
    srand((unsigned) time(&t));
    int rnd =rand()%11726;// 11726 : nombre de mots contenues dans le dictionnaire

    fp=fopen("Dictionnaire8.txt","r");
    if(fp==NULL){
        printf("Error! opening file");
    }
    else{
        
        fseek(fp,9*rnd,SEEK_SET);
        fscanf(fp,"%s",num);
        //fscanf(fp,"%s",num);
        //printf("%s",num);
        //strcpy(numf,num);
                
        }
    fclose(fp);
    return num;
}

int Best_score(){//cherche dans un fichier le meilleur score enregistré dans les parties précédentes
    FILE* fscore;
    fscore=fopen("/Users/soufianehajazi/Desktop/score.txt","r");
    int max=0;
    int num;
    while(!feof(fscore)){
        fscanf(fscore,"%d", &num);
        if(max<num){
          max=num;
        }
    }
    fclose(fscore);
    return max;
}



          
void Timer1(int seconds){ // le temps de réflexion en seconds
    int mseconds;
    mseconds=1000000*seconds; // la fonction qu'on va employer mesure le temps en Microseconds, d'où la multiplication par 1M
    clock_t start=clock();    // Cette définition du temps peut varier d'une machine à une autre
    while(clock()<start+mseconds);
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


bool validate(char *mot,int longeur){  //cette fonction vérifie le mot saisi dans la grille
    if(strlen(mot)!=longeur){    //Doit contenir 8 caractères alphabétiques et le caractère ENTER
        return false;
    }
    else{
        for(int i=0;i<longeur;i++){ // On vérifie que le 8 caractères sont alphabétique(la validation du caractère     ENTER
            if(isalpha(mot)==0){
                mot++;// ENTER se fait dans la fonction saisir_mot()
                return false;
            }
        }
    }
    return true; //renvoie TRUE si seulement si tous les caractères sont alphabétiques
}
          
char *saisir_mot(int longeur){
    char *mot ;
   // int enter;
    mot=(char *)malloc(sizeof(char));

        
do{
        
        printf("Faites saisir un mot valide\n");
        scanf("%s",mot);
       // enter=mot[8];
        }while( validate(mot,longeur)==false); //Ne sortir de la boucle que si le mot tapée est valide et que
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

////void score(){
//    int score_partie=0;
//    if(verifier_existance_dicto(saisir_mot())==false){
//        score_partie-=4;//(-4) for a non existent word
//      };
//    if(lettre_bien_placée()==true){
//        score_partie+=2;// !!!!!<?> pour le tableau des scores chaque niveau de difficulté a sa propre notation donc on optera pour la notation du niv facile....
//    }else{
//        score_partie+=1;
//    }
//    if(mot_trouvé()==true){
//        score_partie+=6;
//    }
//    if(mot_déjà_proposé()==true){
//        score_partie-=10;
////}

}
bool Verifier_existance_dicto(char* mot){
    //parcourir le dictionnaire et vérifier l'existance du mot proposé
    char* temp;
    FILE* fp;
    fp=fopen("Dictionnaire8.txt","r");
    while(feof(fp)!=0){
        fscanf(fp,"%s",temp);
        if(temp==mot){
            return true;
        }
    }
    return false;
}

void MENU(){
    // Nouvellepartie(); Initialisation du partie.
    Timer1(10);
    
    int i=0;
    while(i<7 && motvalide(saisir_mot())){
        
        saisir_mot();
        
        check(Aleatoire_Lecture_Dicto(),saisir_mot());
        score();
            }
    i++;
    
}




