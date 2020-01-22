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
    x=x+5;
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
    for(int i=0;i<=9;i++){
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


char** Initialiser_grille(){
    time_t t;
    char c;
    Mot_aleatoire=(char*)malloc(x*sizeof(char));
    Mot_aleatoire=Aleatoire_Lecture_Dicto();
    char **M;
    M = (char**)malloc(8*sizeof(char*));
    for (int i = 0 ; i < 8 ; i++){
        M[i] = (char*)malloc(x*sizeof(char));
    }
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < x; j++){
            *(M+i*x+j)="*";//Initialisation de la matrice
        }
    }
    srand((unsigned) time(&t));//Initialisation du générateur des nombres aléatoires
    int pos[3];//variable qui sert à stocker les positions à remplir par des lettres au départ
    if(z==1){//Niveau facile, on initialise le mot de départ par 3 lettres
        pos[0]=rand()%x;
        pos[1]=rand()%x;
        pos[2]=rand()%x;
        for(int i=0;i<x;i++){
            if(i==pos[0] || i==pos[1] || i==pos[2]){
                *(M+i)=Mot_aleatoire;
                Mot_aleatoire++;
            }
            else{
                *(M+i)="*";
                Mot_aleatoire++;
            }
        }
    }
    if(z==2){//Niveau difficile,on initialise le mot de départ par 2 lettres
        pos[0]=rand()%x;
        pos[1]=rand()%x;
        for(int i=0;i<x;i++){
            if(i==pos[0] || i==pos[1]){
                *(M+i)=&Mot_aleatoire[i];
            }
            else{
                *(M+i)="*";
            }
        }
    }
    if(z==3){//Niveau trés difficile, on initialise le mot de départ  par une seule lettre
        pos[0]=rand()%x;
        for(int i=0;i<x;i++){
            if(i==pos[0]){
                c=Mot_aleatoire[i];
                *(M+i)=c;
                //sortir de la boucle à ce niveau.
            }
            else{
                *(M+i)="*";
            }
        }
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=x+1;j++){
            if(i==0 || i==9){
                printf("#");//La 1ère et la dernière ligne de la matrice
            }
            else{
                if(j==0 || j==x+1){
                    printf("#");//Les bordures de la grille
                }else{
                    printf("%s",*(M+(i-1)*x+(j-1)));//Le contenue de la grille initié par des '*'
                }
            }
        }
      printf("\n");
    }
    return M;
    
}
char** Update_grille(int tentative,char **M){

    char* mot_saisie;
    do{
        mot_saisie=saisir_mot(x);
        for(int i=0;i<9;i++){
            for(int j=0;j<=x+1;j++){
                if(i==0 || i==8){
                    printf("#");//La 1ère et la dernière ligne de la matrice
                }
                else if(i==tentative){
                    if(j==0 || j==x+1){
                        printf("#");//Les bordures de la grille
                    }else{
                        if(mot_saisie[j-1]==Mot_aleatoire[j-1]){
                            *(M+i*x+j)=&Mot_aleatoire[j-1];
                            printf("%c",*(M+i*x+j));
                        }else{
                            printf("%c",*(M+i*x+j));
                        }
                    }
                }else{
                    printf("%c",*(M+i*x+j));
                }
            }
            printf("\n");
        }
        tentative++;
    }while(tentative<8 || strcmp(mot_saisie, Mot_aleatoire)!=0);
    return M;
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
    char** M;
  
    

  menu();
 
  printf("enter your choice:");
  scanf("%d",&n);
  switch(n){
    case 1:
    printf("**********************WELCOME TO MOTUS*******************");
          start_game();
          Afficher_grille();
          M=Initialiser_grille();
          Update_grille(1, M);
      break;
    
    case 2: printf("ur best score: %d",best_score());
   break;
    case 3:break;
    }
  return 0;

}

