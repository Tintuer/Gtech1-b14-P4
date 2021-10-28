#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NBL = 6
#define NBC = 7
#define tokken "OX"

char tab[NBL][NBC];

void init(void){ // initialisation du tableau
  for(int l=0; l<NBL; l++)
    {
      for(int c=0; c<NBC; c++)
	{
	  tab[l][c] = '.' ;
	}
    }
}

void showtab(void){ // affichage du tableau
  for(int l=0; l<NBL; l++)
    {
      printf("\n");
      for(int c=0; c<NBC; c++)
	{
	  printf("%c ",tab[l][c]);
	}
    }
}

int ask(void){ // demande de réponse du joueur
  int num;
  printf("\nDans quelle colonne veux-tu jouer ?\n");
  scanf ("%d",&num);
  return num;
}

int bottom(int col){ // vérification de la place sur une colonne
  int line = 0;
  while(line < NBL ){
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
  line = error(line);
  tab[line][col]= tokken[player];
}

int error(int col){
    int line;
    line = bottom(col);
    while(line == -1){
        printf("%c","Colonne pleine. \nVeuillez choisir une colonne valide :")
        scanf("%d",col);
        line = bottom(col);
    }
    return line;
}

int winhor(void){
    for(int i = 0; i<NBL; i++){
        for(int j = 0; j<NBC-3; j++){
            if(tab[i][j] == tokken[player] && tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2] && tab[i][j] == tab[i][j+3]){
                printf("%c","Bien joué tu as gagné")
                return 1;
            }
        }
    }
}

int winver(void){
    for(int i = 0; i<NBL-3; i++){
        for(int j = 0; j<NBC; j++){
            if(tab[i][j] == tokken[player] && tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j] && tab[i][j] == tab[i+3][j]){
                printf("%c","Bien joué tu as gagné")
                return 1;
            }
        }
    }
}

int windiag1(void){
    for(int i = 0; i<NBL-3; i++){
        for(int j = 0; j<NBC-3; j++){
            if(tab[i][j] == tokken[player] && tab[i][j] == tab[i+1][j+1] && tab[i][j] == tab[i+2][j+2] && tab[i][j] == tab[i+3][j+3]){
                printf("%c","Bien joué tu as gagné")
                return 1;
            }
        }
    }
}

int windiag2(void){
    for(int i = 3; i<NBL; i++){
        for(int j = 3; j<NBC; j++){
            if(tab[i][j] == tokken[player] && tab[i][j] == tab[i+1][j-1] && tab[i][j] == tab[i+2][j-2] && tab[i][j] == tab[i+3][j-3]){
                printf("%c","Bien joué tu as gagné")
                return 1;
            }
        }
    }
}

int main(void){ // fonction principale du jeu
  int counter = 0;
  int tokkenmax  =6*7;
  int player = 0;
  int victory = 0;
  init();
  while (counter<=tokkenmax && victory == 0){
    showtab();
    play(player,ask());
    victory = winhor();
    victory = winver();
    victory = windiag1();
    victory = windiag2();
    counter ++;
    player = !player;
  }
  if(counter > tokkenmax){
      printf("%c","draw");
  }
  return 0;

}
