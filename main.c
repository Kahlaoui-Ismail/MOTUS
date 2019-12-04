#include <stdio.h>

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
   
   FILE *filePointer ; 
      
    // Declare the variable for the data to be read from file 
    char le_mot_aléatoire[50]; 
  
    
    filePointer = fopen("dictionnaire.txt", "r") ; 
      
   
    if ( filePointer == NULL ) 
    { 
        printf( "dictionnaire.txt file failed to open." ) ; 
    } 
    else
    { 
          
        printf("The file is now opened.\n") ; 
          
        // Read the dataToBeRead from the file 
        //<!> fgets() permet de lire le fichier char par char....
        while( fgets ( dataToBeRead, 50, filePointer ) != NULL ) 
        { 
          
            // Print the dataToBeRead  
            printf( "%s" , dataToBeRead ) ; 
         } 
          
         
        fclose(filePointer) ; 
          
    } 
    return 0;   
}


void  Minuteur(){
    time.h
};

void saisir_mot(){
    char mot[8];
    char ascii(ENTER);
    //Vérifier la taille du mot avec l'utilisateur.
}


void Matrix(){
    casemot M[7][8];
    
    
    //
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
