#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "prototype.h"

int x;
int y;
int z;
char* Mot_aleatoire;
int score=0;


 // On va définir le type booléan pour faciliter la manipulation.

int best_score(){ //cherche dans un fichier le meilleur score enregistré dans les parties précédentes
  FILE*fscore;
  fscore=fopen("‎⁨./Scores/score.txt","r");
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
        printf("\n1) 6letters       2) 7letters     3) 8letters\n4)  9letters       5) 10letters \n");
        scanf("%d",&x);}
    while(x<1 || x>5);
    x=x+5;
    do{
        printf("\nFaites rentrer le temps de réflexion\n");
        printf("\n1) 10 seconds      2) 20 seconds     3) 30 seconds\n");
        scanf("%d",&y);}
    while(y<1 || y>3);
    y=y*10;
    do{
        printf("\nFaites rentrer la difficulté de vocabulaire\n");
        printf("\n1) Facile      2) Difficile     3)  Trés difficile\n");
        scanf("%d",&z);}
    while(z<1 || z>3);
    
    

}


void Afficher_grille(){
    for(int i=0;i<=9;i++){
        for(int j=0;j<=x+1;j++){
            if(i==0 || i==9){
                printf("# \t");//La 1ère et la dernière ligne de la matrice
            }
            else{
                if(j==0 || j==x+1){
                    printf("# \t");//Les bordures de la grille
                }else{
                    printf("* \t");//Le contenue de la grille initié par des '*'
                }
            }
        }
      printf("\n");
    }
}

char* Aleatoire_Lecture_Dicto(){
    char* num;
    num=(char*)malloc(sizeof(char));
 
    FILE *fp = NULL;
    time_t t;
    srand((unsigned) time(&t));
    int rnd =rand()%11726;// 11726 : nombre de mots contenues dans le dictionnaire
    if(x==6){
        fp=fopen("./Dictionnaires/Dictionnaire6.txt","r");
        if(fp==NULL){
            printf("Error! opening file");
        }
        else{
            fseek(fp,7*rnd,SEEK_SET);
            fscanf(fp,"%s",num);
                    
            }
    }
    
    if(x==7){
        fp=fopen("./Dictionnaires/Dictionnaire7.txt","r");
        if(fp==NULL){
            printf("Error! opening file");
        }
        else{
            fseek(fp,8*rnd,SEEK_SET);
            fscanf(fp,"%s",num);
                    
            }
    }
    if(x==8){
        fp=fopen("./Dictionnaires/Dictionnaire8.txt","r");
        if(fp==NULL){
            printf("Error! opening file");
        }
        else{
            fseek(fp,9*rnd,SEEK_SET);
            fscanf(fp,"%s",num);
                    
            }
    }
    if(x==9){
        fp=fopen("./Dictionnaires/Dictionnaire9.txt","r");
        if(fp==NULL){
            printf("Error! opening file");
        }
        else{
            fseek(fp,10*rnd,SEEK_SET);
            fscanf(fp,"%s",num);
                    
            }
    }
    if(x==10){
        fp=fopen("./Dictionnaires/Dictionnaire10.txt","r");
        if(fp==NULL){
            printf("Error! opening file");
        }
        else{
            fseek(fp,11*rnd,SEEK_SET);
            fscanf(fp,"%s",num);
                    
            }
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
bool verifier_existance_dicto(char* mot_saisie){
    //parcourir le dictionnaire et vérifier l'existance du mot proposé
    char* temp;
    FILE* fp1;
    char* filename;
    switch(x){
            case 6 : filename="./Dictionnaires/Dictionnaire6.txt";break;
            case 7 : filename="./Dictionnaires/Dictionnaire7.txt";break;
            case 8 : filename="./Dictionnaires/Dictionnaire8.txt";break;
            case 9 : filename="./Dictionnaires/Dictionnaire9.txt";break;
            case 10 : filename="./Dictionnaires/Dictionnaire10.txt";break;
    }
    fp1=fopen(filename,"r");
    if(fp1==NULL){
        printf("Error! opening file");
    }
    temp=(char*)malloc(sizeof(char));
    while(!feof(fp1)){
        fscanf(fp1, "%s",temp);
        if(temp==mot_saisie){
            return true;
        }
    }
    return false;
}
    

int Minuteur(int seconds){ // le temps de réflexion en seconds
    int mseconds;
    mseconds=1000000*seconds; // la fonction qu'on va employer mesure le temps en Microseconds, d'où la multiplication par 1M
    clock_t start=clock();    // Cette définition du temps peut varier d'une machine à une autre
    while(clock()<start+mseconds);
    return 0;
}

char *saisir_mot(int longeur){
    char *mot;
    mot=(char*)malloc(sizeof(char));
    
    time_t seconds;
    seconds = time(NULL);
    //mot=(char*)malloc(x*sizeof(char));
   // int enter;

        
do{
        
        
        printf("Faites saisir un mot valide\n");
        scanf("%s",mot);
       // enter=mot[8];
        }while(strlen(mot)!=longeur && time(NULL)<seconds+y);
            if(time(NULL)>seconds+y){
                return "NO";
            }else{
                return mot;
            }//Ne sortir de
                    //la boucle que si le mot tapée est valide
            
}


    
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
            *(M+i*x+j)='*';//Initialisation de la matrice
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
                *(M+i)=*(Mot_aleatoire+i);
            }
            else{
                *(M+i)='*';
            }
        }
    }
    if(z==2){//Niveau difficile,on initialise le mot de départ par 2 lettres
        pos[0]=rand()%x;
        pos[1]=rand()%x;
        for(int i=0;i<x;i++){
            if(i==pos[0] || i==pos[1]){
                *(M+i)=*(Mot_aleatoire+i);
            }
            else{
                *(M+i)='*';
            }
        }
    }
    if(z==3){//Niveau trés difficile, on initialise le mot de départ  par une seule lettre
        pos[0]=rand()%x;
        for(int i=0;i<x;i++){
            if(i==pos[0]){
                *(M+i)=*(Mot_aleatoire+i);
                //sortir de la boucle à ce niveau.
            }
            else{
                *(M+i)='*';
            }
        }
    }
    for(int i=0;i<=9;i++){
        for(int j=0;j<=x+1;j++){
            if(i==0 || i==9){
                printf("# \t");//La 1ère et la dernière ligne de la matrice
                if(j==x+1 && i==0){
                    printf("\t Score : %d",score);
                }
            }
            else{
                if(j==0 || j==x+1){
                    printf("# \t");//Les bordures de la grille
                }else{
                    c=*(M+(i-1)*x+(j-1));
                    printf("%c",c);
                    printf("\t");
                }
            }
        }
      printf("\n");
    }
    return M;
    
}
char** Update_grille(char **M,int tentative){
    char c;
    char* mot_saisie;
    mot_saisie=(char*)malloc(x*sizeof(char));
    do{
        mot_saisie=saisir_mot(x);
        if(strcmp(mot_saisie,"NO")==0){
            printf("Votre temps est déjà épuisée \n");
                for(int j=0;j<x;j++){
                    *(M+tentative*x+j)=*(M+(tentative-1)*x+j);
                }
        }
        else{
            for(int i=0;i<9;i++){
                for(int j=0;j<x;j++){
                    if(i==tentative){
                        if(*(mot_saisie+j)==*(Mot_aleatoire+j)){
                            *(M+i*x+j)=*(Mot_aleatoire+j);
                            score+=2;
                        }
                    }
                }
            }
        }
        for(int i=0;i<=9;i++){
            for(int j=0;j<=x+1;j++){
                if(i==0 || i==9){
                    printf("# \t");//La 1ère et la dernière ligne de la matrice
                    if(j==x+1 && i==0){
                        printf("\t Score : %d",score);
                    }
                }
                else{
                    if(j==0 || j==x+1){
                        printf("# \t");//Les bordures de la grille
                    }else{
                        c=*(M+(i-1)*x+(j-1));
                        printf("%c",c);
                        printf("\t");
                    }
                }
            }
          printf("\n");
        }
        if(strcmp(mot_saisie,"NO")!=0){
            for(int i=0;i<x;i++){
                for(int j=0;j<x;j++){
                    if(*(M+tentative*x+i)!='*'){
                        break;
                    }
                    else{
                        if(*(Mot_aleatoire+i)==*(mot_saisie+j)){
                            printf("La lettre '%c' existe mais mal placée \n",*(Mot_aleatoire+i));
                            score+=1;
                            break;
                        }
                    }
                }
            }
        }
        if(verifier_existance_dicto(mot_saisie)==false && strcmp(mot_saisie,"NO")!=0){
            score-=4;//(-4) for a non existent word
        }
        tentative++;
    }while(tentative<8 && strcmp(mot_saisie, Mot_aleatoire)!=0);
    if(tentative<8){
        printf("Félicitaion! Vous avez deviné le mot correct");
        score+=6;
    }
    else{
        printf("Désolé! Vous n'avez pas deviné le mot correct \n");
        printf("Le mot correct était %s \n ",Mot_aleatoire);
    }
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
    int tentative=1;
  
    

  menu();
 
  printf("enter your choice:");
  scanf("%d",&n);
  switch(n){
    case 1:
    printf("**********************WELCOME TO MOTUS*******************");
          start_game();
          //Afficher_grille();
          M=Initialiser_grille();
          Update_grille(M,tentative);
      break;
    
    case 2: printf("ur best score: %d",best_score());
            break;
    case 3:break;
    }
}
    




