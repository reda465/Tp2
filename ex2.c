#include<stdio.h>
typedef struct {
        int jour;
        int mois;
        int annee;
    }stDateNaisRepere;
typedef struct {
    char nom[50];
    short age;
    float note;
    stDateNaisRepere dateNaissance;
    
}stEtudiantRepere;
int lire_nbre_etudiant(){
    int taille;
    printf("entrez combien d'etidiant voulez vous entrer : ");
    scanf("%d",&taille);
    return taille;
}
stEtudiantRepere lireEtudiant(stEtudiantRepere etudiant_info){
    printf("entrez votre nom : \n");
    fgets(etudiant_info.nom,50,stdin);
    printf("entrez votre age : \n");
    scanf("%d",&etudiant_info.age);
    printf("entrez votre note : \n");
    scanf("%f",&etudiant_info.note);
    /*printf("entrer votre jour de naissance : \n");
    scanf("%d",&etudiant_info.dateNaissance.jour);*/
    printf("entrer votre mois de naissance : \n");
    scanf("%d",&etudiant_info.dateNaissance.mois);
    printf("entrer votre annee de naissance : \n");
    scanf("%d",&etudiant_info.dateNaissance.annee);
    return etudiant_info;
}
void afficherEtudiant(stEtudiantRepere etudiant_info){
    printf("***************************************************\n");
    printf("votre nom est : %s \n",etudiant_info.nom);
    printf("votre age est : %d \n", etudiant_info.age);
    printf("votre note monsieur est : %f \n", etudiant_info.note);
    printf("votre date de naissance est \n: %d , %d, %d ", etudiant_info.dateNaissance.annee,etudiant_info.dateNaissance.mois, etudiant_info.dateNaissance.jour);
}

int main(){
    stEtudiantRepere etudiant;
    afficherEtudiant(lireEtudiant(etudiant));
}
