#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define tokken "OX"
int col;

char tab[6][7];

void init(void){ // initialisation du tableau
  for(int l=0; l<6; l++)
    {
      for(int c=0; c<7; c++)
	{
	  tab[l][c] = '.' ;
	}
    }
}

void showtab(void){ // affichage du tableau
  for(int l=0; l<6; l++)
    {
      printf("\n");
      for(int c=0; c<7; c++)
	{
	  printf("%c ",tab[l][c]);
	}
    }
}

int valid(int number)
{
  if ( (number < 0) || (number > 6) )
    printf("SALE ENCULER");
    return 0;
  if (tab[6-1][number] != '.')
    return 0;
  return 1;
}

int ask(void){ // demande de réponse du joueur
  int num;
  printf("\nDans quelle colonne veux-tu jouer ?\n");
  scanf ("%d",&num);
  return num;
}

int bottom(int col){ // vérification de la place sur une colonne
  int line = 0;
  while(line <= 5 || line == 1){
    if(tab[line][col]  == '.'){
      line++;
    }
    else{
      line--;
      return line;
    }
  }
}

void play(int player,int col){ // place des tokkens dans le jeu
  int line = bottom(col);
  tab[line][col]= tokken[player];
}


int main(void){ // fonction principale du jeu
  int counter=0;
  int tokkenmax=6*7;
  int player = 0;
  init();
  while (counter<tokkenmax){
    showtab();
    play(player,ask());
    counter ++;
    player = !player;
  }
  printf("draw");
  return 0;

}
