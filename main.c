#include <stdio.h>
#include <stdiolib.h>

//Déclarer une cellule
struct Cellule
{
    int val;
    Cellule *suiv;
};

//déclarer Liste
typedef Cellule *Liste;

Liste ajouttete(Liste L, int x)
{
    Cellule *Q;
    Q=(Cellule*)malloc(sizeof(Cellule));
    Q->val=x;
    Q->suiv=L;
    L=Q;
        return L; 
}

void affiche (Liste L)
{
    while(L=NULL)
    {
        print(" %d |° |->",L->val);
        L=L->suiv;
    }
}

int main() {
    Liste L=NULL; 
    int x=25;
    L=ajouttete(L,x)
    affiche (L);
    
    return 0; 
}
