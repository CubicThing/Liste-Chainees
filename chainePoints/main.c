/**********************\
    liste.c        *
\**********************/


#include "list.h"
#include "list.c"

int main (void)
{
  char choix;
  int *nom1;
  int *nom2;
  Liste *liste;
  //Element *courant;

  if ((liste = (Liste *) malloc (sizeof (Liste))) == NULL)
    return -1;
  if ((nom1 = (int *) malloc (50)) == NULL)
    return -1;

  //courant = NULL;
  choix = 'o';

  initialisation (liste);
  int pos, k;

  while (choix != 7){
      choix = menu (liste, &k);
      switch (choix){
        case 1:
          printf ("Entrez deux elements : ");
          scanf ("%d", nom1);
          scanf ("%d", nom2);
          if (liste->taille == 0)
            insListeVide(liste, nom1, nom2);
          else
            insDebutListe (liste, nom1, nom2);
          printf ("%d elements:deb=%s,fin=%s\n", liste->taille,
                  liste->debut->p, liste->fin->p);
          affiche (liste);
          break;
        case 2:
          printf ("Entrez un element : ");
          scanf ("%s", nom1);
          getchar ();
          insFinListe (liste, liste->fin, nom1);
          printf ("%d elements:deb=%s,fin=%s\n", liste->taille,
                  liste->debut->p, liste->fin->p);
          affiche (liste);
          break;
        case 3:
          printf ("Entrez un element : ");
          scanf ("%s", nom1);
          getchar ();
          do{
              printf ("Entrez la position : ");
              scanf ("%d", &pos);
     }
          while (pos < 1 || pos > liste->taille);
          getchar ();
          if (liste->taille == 1 || pos == liste->taille){
              k = 1;
              printf("-----------------------------------------------\n");
              printf("Insertion echouée.Utilisez le menu {1|2}  \n");
              printf("-----------------------------------------------\n");
              break;
     }
          insListe (liste, nom1, pos);
          printf ("%d elements:deb=%s,fin=%s\n", liste->taille,
                  liste->debut->p, liste->fin->p);
          affiche (liste);
          break;
        case 4:
          suppDebut (liste);
          if (liste->taille != 0)
            printf ("%d elements:deb=%s,fin=%s\n", liste->taille,
                    liste->debut->p, liste->fin->p);
          else
            printf ("liste vide\n");
          affiche (liste);
          break;
        case 5:
          do{
              printf ("Entrez la position : ");
              scanf ("%d", &pos);
     }
          while (pos < 1 || pos > liste->taille);
          getchar ();
          suppDansListe (liste, pos);
          if (liste->taille != 0)
            printf ("%d elements:deb=%s,fin=%s\n", liste->taille,
                    liste->debut->p, liste->fin->p);
          else
            printf ("liste vide\n");
          affiche (liste);
          break;
        case 6:
          detruire (liste);
          printf ("la liste a ete detruite : %d elements\n", liste->taille);
          break;
      }
  }
  return 0;
}
