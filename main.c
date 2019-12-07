#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {true, false} bool;

typedef struct Couleur{
    char couleur[7];
    //JAUNE,BLUE,ROUGE
}Clr;


typedef struct Case{
    char val;
    Couleur c;
}casemot;

bool validate(char *mot){
    if(strlen(mot)!=9){
        return false;
    }
    else{
        for(int i=0;i<strlen(mot)-2;i++){
            if(isalpha(mot[i])==0){
                return false;
            }
        }
    }
    return true;
}

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

bool validate(char *mot){
    if(strlen(mot)!=9){
        return false;
        }
    else{
        for(int i=0;i<strlen(mot)-2;i++){
            if(isalpha(mot[i])==0){
                return false;
            }
        }
    }
        return true;
}
          
void  Minuteur(){
    time.h
};

          
char *saisir_mot(){
    char *mot ;
    int enter;
    mot=(char *)malloc(sizeof(char));
    //char ascii(ENTER);
        
do{
        
        printf("Faites saisir un mot valide");
        scanf("%s",mot);
        enter=mot[8];
        }while(enter!=13 || validate(mot)==false); //Ne sortir de la boucle que si le mot tapée est valide
          return mot;
}


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
