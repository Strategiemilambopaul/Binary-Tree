#include <stdlib.h>
#include <stdio.h>

// Définition de la structure pour les nœuds
typedef struct noeud {
    int valeur; // étiquette du nœud
    struct noeud *gauche; // pointeur vers le fils gauche
    struct noeud *droit; // pointeur vers le fils droit
} noeud_t;

// Fonction qui crée un nouveau nœud avec une étiquette donnée
noeud_t *creer_noeud(int valeur) {
    // Allocation dynamique de mémoire pour le nœud
    noeud_t *nouveau_noeud = malloc(sizeof(noeud_t));
    // Vérification que l'allocation a réussi
    if (nouveau_noeud == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(1);
    }
    // Initialisation des champs du nœud
    nouveau_noeud->valeur = valeur;
    nouveau_noeud->gauche = NULL;
    nouveau_noeud->droit = NULL;
    // Retour du pointeur vers le nœud créé
    return nouveau_noeud;
}

// Fonction qui insère un nœud dans un arbre binaire de recherche
void insert_noeud(noeud_t **racine, int valeur) {
    // Si l'arbre est vide, on crée le nœud racine
    if (*racine == NULL) {
        *racine = creer_noeud(valeur);
    }
    // Sinon, on compare l'étiquette du nœud à insérer avec celle du nœud courant
    else {
        // Si l'étiquette est inférieure, on insère le nœud dans le sous-arbre gauche
        if (valeur < (*racine)->valeur) {
            insert_noeud(&(*racine)->gauche, valeur);
        }
        // Sinon, on insère le nœud dans le sous-arbre droit
        else {
            insert_noeud(&(*racine)->droit, valeur);
        }
    }
}

// Fonction qui affiche les étiquettes d'un arbre binaire de recherche selon le parcours préfixe
void prefixe(noeud_t *racine) {
    // Si l'arbre n'est pas vide, on affiche la racine, puis on parcourt récursivement le sous-arbre gauche, puis le sous-arbre droit
    if (racine != NULL) {
        printf("%d ", racine->valeur);
        prefixe(racine->gauche);
        prefixe(racine->droit);
    }
}

// Fonction qui affiche les étiquettes d'un arbre binaire de recherche selon le parcours infixe
void infixe(noeud_t *racine) {
    // Si l'arbre n'est pas vide, on parcourt récursivement le sous-arbre gauche, puis on affiche la racine, puis le sous-arbre droit
    if (racine != NULL) {
        infixe(racine->gauche);
        printf("%d ", racine->valeur);
        infixe(racine->droit);
    }
}

// Fonction qui affiche les étiquettes d'un arbre binaire de recherche selon le parcours postfixe
void postfixe(noeud_t *racine) {
    // Si l'arbre n'est pas vide, on parcourt récursivement le sous-arbre gauche, puis le sous-arbre droit, puis on affiche la racine
    if (racine != NULL) {
        postfixe(racine->gauche);
        postfixe(racine->droit);
        printf("%d ", racine->valeur);
    }
}

// Fonction qui libère la mémoire allouée pour un arbre binaire
void free_tree(noeud_t *racine) {
    // Si l'arbre n'est pas vide, on libère récursivement le sous-arbre gauche, le sous-arbre droit, et le nœud courant
    if (racine != NULL) {
        free_tree(racine->gauche);
        free_tree(racine->droit);
        free(racine);
    }
}
int rechercher(noeud_t *racine, int valeur ){
    while(racine){
        if(valeur==racine->valeur)
        return 1;
        if(valeur > racine->valeur)  
        racine=racine->droit;
        else
        racine=racine->gauche;
    }
    return 0;
}

// Fonction principale qui teste le code
int main() {
    // Création d'un arbre binaire de recherche vide
    noeud_t *racine = NULL;
    // Insertion de quelques nœuds

    int taille , n, valeur;
    int choix;
    printf("donnez la taille de la liste:\n ");
    scanf("%d", &taille);
    for(int i=0; i<taille; i++)
    {
        printf("Saisir un nombre: \n");
        scanf("%d", &n);
        insert_noeud(&racine, n);
    }
    // insert_noeud(&racine, 10);
    // insert_noeud(&racine, 5);
    // insert_noeud(&racine, 15);
    // insert_noeud(&racine, 3);
    // insert_noeud(&racine, 7);
    // insert_noeud(&racine, 12);
    // insert_noeud(&racine, 18);
    // Affichage des étiquettes selon les différents parcours
    printf("Parcours préfixe : ");
    prefixe(racine);
    printf("\n");
    printf("Parcours infixe : ");
    infixe(racine);
    printf("\n");
    printf("Parcours postfixe : ");
    postfixe(racine);
    printf("\n");
    printf("*****************************************************\n");
    do{ 
        printf("\nvoulez-vous rechercher un noeud dans votre arbre construit ?(0/1)\n");
        scanf("%d",&choix);
        printf("*****************************************************\n\n");
        if(choix == 0){
            printf("Merci !\n A la prochaine !<(^_^)>\n");
        }
        else
        {
            
            printf("entrer la valeur à rechercher dans l'arbre\n");
            scanf("%d",&valeur);
            if(rechercher(racine,valeur)){
                printf("l'element %d existe dans l'arbre", valeur);
            }else
            {
                printf("l'element %d n'existe pas dans l'arbre", valeur);
            }
        }
    }
    while(choix==1);
     // Libération de la mémoire
    free_tree(racine);
    return 0;
}

   
