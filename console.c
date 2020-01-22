#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototype.h"

int x;
int y;
int z;
char* Mot_aleatoire;

int best_score(){ //cherche dans un fichier le meilleur score enregistré dans les parties précédentes
  FILE*fscore;
  fscore=fopen("‎⁨/Users/soufianehajazi/Desktop/TP2/TP-structures.c/score.txt","r");
  int max=0;
  int num;
  while(!feof(fscore)){
  fscanf(fscore,"%d", &num);
  
  if(max<num){
    max=num;
  }
}
return max;


}


void start_game(){
    
    
    do{
        printf("\nFaites rentrer la taille du mot\n");
        printf("\n 1) 6letters       2) 7letters     3) 8letters\n\t4)  9letters       5) 10letters");
        scanf("%d",&x);}
    while(x<1 || x>5);
    do{
        printf("\nFaites rentrer le temps de réflexion\n");
        printf("\n 1) 10 seconds      2) 15 seconds     3) 20 seconds\n");
        scanf("%d",&y);}
    while(y<1 || y>3);
    do{
        printf("\nFaites rentrer la difficulté de vocabulaire\n");
        printf("\n 1) Facile      2) Difficile     3)  Trés difficile\n");
        scanf("%d",&z);}
    while(z<1 || z>3);
    
    

}


void Afficher_grille(){
    for(int i=0;i<8;i++){
        for(int j=0;j<=x+1;j++){
            if(i==0 || i==9){
                printf("#");//La 1ère et la dernière ligne de la matrice
            }
            else{
                if(j==0 || j==x+1){
                    printf("#");//Les bordures de la grille
                }else{
                    printf("*");//Le contenue de la grille initié par des '*'
                }
            }
        }
      printf("\n");
    }
}

char* Initialiser_grille(){
    time_t t;
    Mot_aleatoire=Aleatoire_Lecture_Dicto();
    char* Mot_depart;//Le mot initiale, Ex : m**u*
    srand((unsigned) time(&t));//Initialisation du générateur des nombres aléatoires
    int pos[3];//variable qui sert à stocker les positions à remplir par des lettres au départ
    if(z==1){//Niveau facile, on initialise le mot de départ par 3 lettres
        pos[0]=rand()%x;
        pos[1]=rand()%x;
        pos[2]=rand()%x;
        for(int i=0;i<x;i++){
            if(i==pos[0] || i==pos[1] || i==pos[2]){
                Mot_depart=Mot_aleatoire;
            }
            else{
                Mot_aleatoire++;
                strcat(Mot_depart,"*");
            }
        }
    }
    if(z==2){//Niveau difficile,on initialise le mot de départ par 2 lettres
        pos[0]=rand()%x;
        pos[1]=rand()%x;
        for(int i=0;i<x;i++){
            if(i==pos[0] || i==pos[1]){
                Mot_depart=Mot_aleatoire;
            }
            else{
                Mot_aleatoire++;
                strcat(Mot_depart,"*");
            }
        }
    }
    if(z==3){//Niveau trés difficile, on initialise le mot de départ  par une seule lettre
        pos[0]=rand()%x;
        for(int i=0;i<x;i++){
            if(i==pos[0]){
                Mot_depart=Mot_aleatoire;
            }
            else{
                Mot_aleatoire++;
                strcat(Mot_depart,"*");
            }
        }
    }
    return Mot_depart;
}

void menu(){

  printf("\n********************WELCOME TO MOTUS******************\n\n");
  printf("\n              1- NEW GAME                  \n ");
  printf("\n              2- BEST SCORE                \n");
  printf("\n              3- QUIT THE GAME               \n\n ");
  printf("\n******************************************************\n");
  
}


int main(){
  int n;
  
    

  menu();
 
  printf("enter your choice:");
  scanf("%d",&n);
  switch(n){
    case 1:
    printf("**********************WELCOME TO MOTUS*******************");
      start_game();
      Afficher_grille();
      break;
    
    case 2: printf("ur best score: %d",best_score());
   break;
    case 3:break;
    }
  return 0;

}
