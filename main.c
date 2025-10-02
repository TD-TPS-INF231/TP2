#include <stdio.h>
#include <stdlib.h>



typedef struct liste
{
    char element;
    struct liste *suiv;
    struct liste *prec;
} liste;


void insert_tete(liste **l, char v)
{
    liste *p = (liste *)malloc(sizeof(liste));
    if (p == NULL)
    {
        printf("erreur d'allocation mémoire\n");}
        if(*l == NULL){ 
   
    p->element = v;
    p->suiv = p;
    p->prec = p;
    *l = p;
     }
else
{
    liste *queue = (*l)->prec;

    p->suiv = *l;
    p->prec = queue;

    queue->suiv = p;
    (*l)->prec = p;

    *l = p; 
}
free(p);
}


void insert_queue(liste **tete, char val)
{
    liste *nouveau = (liste *)malloc(sizeof(liste));
    if (nouveau == NULL)
    {
        printf("Erreur d'allocation mémoire\n");
    }

    nouveau->element = val;

    if (*tete == NULL)
    {
        nouveau->suiv = nouveau;
        nouveau->prec = nouveau;
        *tete = nouveau;
    }
    else
    {
        liste *dernier = (*tete)->prec;

        nouveau->suiv = *tete;
        nouveau->prec = dernier;
        dernier->suiv = nouveau;
        (*tete)->prec = nouveau;
    }
    free(nouveau);
}


void afficher_liste(liste *tete)
{
    if (tete == NULL)
    {
        printf("La liste est vide.\n");
        return;
    }

    liste *p = tete;
    do
    {
        printf("%c ", p->element);
        p = p->suiv;
    } while (p != tete);
    printf("\n");
}


int main()
{
    liste *tete, *queue;
    int choix;
    char val;
    do
    {
        printf("--Menu--\n");
        printf("5.projet5\n");
        printf("0.Quitter\n");
        printf("entrer votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 5:
            printf("--Petit Menu--\n");
            printf("1.insertion en queue\n");
            printf("2.insertion en tete\n");
            printf("entrer votre choix : ");
            scanf("%d", &choix);
            switch (choix)
            {
            case 1:
                printf("Insertion en queue de liste doublement circulaire\n");
                printf("Entrer l'élément à insérer : ");
                getchar();
                scanf("%c", &val);
                insert_queue(&tete, val);
                printf("Élément inséré.\n");
                printf("Liste actuelle : ");
                afficher_liste(tete);
                break;
            case 2:
                printf("Insertion en tête de liste doublement circulaire\n");
                printf("Entrer l'élément à insérer : ");
                getchar();
                scanf("%c", &val);
                insert_tete(&queue, val);
                printf("Élément inséré.\n");
                printf("Liste actuelle : ");
                afficher_liste(queue);
                break;
            default:
                break;
            }

            break;

        case 0:
            printf("fin du programme\n");
            break;

        default:
            printf("choix invalide\n");
            break;
        }
    } while (choix != 0);
    return 0;
}