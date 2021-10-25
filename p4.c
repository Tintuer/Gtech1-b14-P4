#include <stdio.h>
#include <stidlib.h>

#define NBL  6
#define NBC  7
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
      for(int c=0; c<NBC; c++)
	{
	  printf("%c",tab[l][c]);
	}
    }
}

int ask(void){ // demande de réponse du joueur
  int num;
  printf("%c","Dans quelle colonne veux-tu jouer ?\n");
  scanf ("%d",&num);
  return num;
}

int bottom(int col){ // vérification de la place sur une colonne
      int ligne = 0
	while(ligne <= 5 || ligne == 1){
	  if(tab[ligne][col]  == '.'){
	    ligne++;
	  }
	  else{
	                ligne--
			  return ligne;
	  }
	}
}

void play(int joueur,int ,int col){ // place des tokkens dans le jeu
      tab[ligne][col]= tokken[joueur]
	}

int main(void){ // fonction principale du jeu
      int compteur=0
	    int tokkenmax=NBL*NBC
	init();
      showtab();
      while (compteur<tokkenmax){

      }
      return 0;

}




system ("cls") //wipe the console !
