#include <stdio.h>
#include <stdlib.h>

int best_score(){ //cherche dans un fichier le meilleur score enregistré dans les parties précédentes
  FILE*fscore;
  fscore=fopen("scores.txt","r");
  max=0
  while(!feof(fptr)){
  fscanf(fptr,"%s", &num);
  
  if(max<num){
    max=num;
  }

}
int actual_score(){

  
}



void menu(){

  printf("\n********************WELCOME TO MOTUS******************\n\n");
  printf("\n              1- NEW GAME                  \n ");
  printf("\n              2- BEST SCORE                \n");
  printf("\n              2- QUIT THE GAME               \n\n ");
  printf("\n******************************************************\n");
  
}


int main(){
  menu();
  printf("enter your choice:");
  scanf("%d",&n);
  switch(n){
    case 1:
    printf("**********************WELCOME TO MOTUS*******************");
    
    case 2:
    printf("Your best score is:%d", bestscore());break;
    case 3:break;
    }
  return 0;

}
