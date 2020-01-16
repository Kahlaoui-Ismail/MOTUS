#include <stdio.h>
#include <stdlib.h>

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
    int x;
    
    printf("\nPLEASE CHOOSE THE NUMBER OF WORDS\n");
    printf("\n 1) 6letters       2) 7letters     3) 8letters\n");
    scanf("%d",&x);
    

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
      start_game();break;
    
    case 2: printf("ur best score: %d",best_score());
   break;
    case 3:break;
    }
  return 0;

}
