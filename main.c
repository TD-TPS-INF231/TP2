
#include <stdio.h>
#include <stdlib.h>

/* Structure d'un noeud de la liste chaînée (singly linked list) */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Crée un nouveau noeud contenant 'value' */
Node* create_node(int value) {
    Node n = (Node)malloc(sizeof(Node));
    if (!n) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    n->data = value;
    n->next = NULL;
    return n;
}

/* Ajoute à la fin de la liste (push back) */
void append(Node **head_ref, int value) {
    Node *new_node = create_node(value);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node *cur = *head_ref;
    while (cur->next) cur = cur->next;
    cur->next = new_node;
}

/* Affiche la liste sur une seule ligne */
void print_list(Node *head) {
    if (!head) {
        printf("(liste vide)\n");
        return;
    }
    Node *cur = head;
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(" -> ");
        cur = cur->next;
    }
    printf("\n");
}

/* Supprime toutes les occurrences de 'target' et retourne la nouvelle tête */
Node* delete_occurrences(Node *head, int target) {
    Node *tmp;

    /* 1) Supprimer les têtes successives contenant target */
    while (head && head->data == target) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    /* Si la liste est maintenant vide, on retourne NULL */
    if (!head) return NULL;

    /* 2) Parcourir le reste de la liste */
    Node *prev = head;
    Node *cur = head->next;
    while (cur) {
        if (cur->data == target) {
            /* Supprimer 'cur' */
            prev->next = cur->next;
            free(cur);
            cur = prev->next; /* avancer cur (prev reste inchangé) */
        } else {
            /* avancer prev et cur */
            prev = cur;
            cur = cur->next;
        }
    }

    return head;
}

/* Libère toute la mémoire de la liste */
void free_list(Node *head) {
    Node *cur = head;
    while (cur) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

/* Programme principal : lecture, suppression, affichage */
int main(void) {
    Node *head = NULL;
    int n;

    printf("Combien d'elements dans la liste ? ");
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Entrée invalide.\n");
        return EXIT_FAILURE;
    }

    printf("Entrez %d entiers (séparés par des espaces ou retours ligne) :\n", n);
    for (int i = 0; i < n; ++i) {
        int x;
        if (scanf("%d", &x) != 1) {
            fprintf(stderr, "Erreur de lecture.\n");
            free_list(head);
            return EXIT_FAILURE;
        }
        append(&head, x);
    }

    printf("\nListe avant suppression :\n");
    print_list(head);

    int target;
    printf("Valeur à supprimer (toutes les occurrences) : ");
    if (scanf("%d", &target) != 1) {
        fprintf(stderr, "Erreur de lecture.\n");
        free_list(head);
        return EXIT_FAILURE;
    }

    head = delete_occurrences(head, target);

    printf("\nListe après suppression des occurrences de %d :\n", target);
    print_list(head);

    free_list(head);
    return 0;
}