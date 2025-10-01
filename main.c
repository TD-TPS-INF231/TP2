#include <stdio.h>
#include <stdlib.h>

// Structure d'un élément de la liste
typedef struct Element {
    int valeur;
    struct Element* suivant;
} Element;

// Structure de la liste
typedef struct {
    Element* tete;
} ListeCirculaire;

// Fonction pour créer un nouvel élément
Element* creerElement(int valeur) {
    Element* nouveau = (Element*)malloc(sizeof(Element));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    nouveau->valeur = valeur;
    nouveau->suivant = NULL;
    return nouveau;
}

// Fonction pour initialiser une liste vide
ListeCirculaire* initialiserListe() {
    ListeCirculaire* liste = (ListeCirculaire*)malloc(sizeof(ListeCirculaire));
    if (liste == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    liste->tete = NULL;
    return liste;
}

// Fonction pour insérer en tête
void insererTete(ListeCirculaire* liste, int valeur) {
    Element* nouveau = creerElement(valeur);
    
    if (liste->tete == NULL) {
        // Liste vide - l'élément pointe vers lui-même
        nouveau->suivant = nouveau;
        liste->tete = nouveau;
    } else {
        // Chercher le dernier élément
        Element* courant = liste->tete;
        while (courant->suivant != liste->tete) {
            courant = courant->suivant;
        }
        
        // Insérer en tête
        nouveau->suivant = liste->tete;
        liste->tete = nouveau;
        courant->suivant = nouveau; // Le dernier pointe vers la nouvelle tête
    }
    
    printf("Element %d insere en tete\n", valeur);
}

// Fonction pour insérer en queue
void insererQueue(ListeCirculaire* liste, int valeur) {
    Element* nouveau = creerElement(valeur);
    
    if (liste->tete == NULL) {
        // Liste vide - l'élément pointe vers lui-même
        nouveau->suivant = nouveau;
        liste->tete = nouveau;
    } else {
        // Chercher le dernier élément
        Element* dernier = liste->tete;
        while (dernier->suivant != liste->tete) {
            dernier = dernier->suivant;
        }
        
        // Insérer après le dernier
        dernier->suivant = nouveau;
        nouveau->suivant = liste->tete;
    }
    
    printf("Element %d insere en queue\n", valeur);
}

// Fonction pour afficher la liste
void afficherListe(ListeCirculaire* liste) {
    if (liste->tete == NULL) {
        printf("La liste est vide\n");
        return;
    }
    
    printf("Liste circulaire : ");
    Element* courant = liste->tete;
    
    do {
        printf("%d", courant->valeur);
        if (courant->suivant != liste->tete) {
            printf(" -> ");
        }
        courant = courant->suivant;
    } while (courant != liste->tete);
    
    printf(" -> (retour au debut)\n");
}

// Fonction pour libérer la mémoire
void libererListe(ListeCirculaire* liste) {
    if (liste->tete == NULL) {
        free(liste);
        return;
    }
    
    Element* courant = liste->tete;
    Element* aSupprimer;
    
    do {
        aSupprimer = courant;
        courant = courant->suivant;
        free(aSupprimer);
    } while (courant != liste->tete);
    
    free(liste);
}

// Programme principal de test
int main() {
    ListeCirculaire* maListe = initialiserListe();
    
    printf("=== Liste circulaire simplement chainee ===\n\n");
    
    // Test d'insertion en tête
    insererTete(maListe, 10);
    afficherListe(maListe);
    
    insererTete(maListe, 20);
    afficherListe(maListe);
    
    insererTete(maListe, 30);
    afficherListe(maListe);
    
    printf("\n");
    
    // Test d'insertion en queue
    insererQueue(maListe, 5);
    afficherListe(maListe);
    
    insererQueue(maListe, 2);
    afficherListe(maListe);
    
    printf("\n");
    
    // Test avec une nouvelle liste
    printf("Creation d'une nouvelle liste...\n");
    ListeCirculaire* autreListe = initialiserListe();
    
    insererQueue(autreListe, 100);
    afficherListe(autreListe);
    
    insererTete(autreListe, 200);
    afficherListe(autreListe);
    
    // Libération de la mémoire
