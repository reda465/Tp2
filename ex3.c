#include<stdio.h>
#include<stdlib.h>
typedef struct {
        int jour;
        int mois;
        int annee;
    }stDateNaisRepere;
typedef struct {
    char nom[50];
    int age;
    float note;
    stDateNaisRepere dateNaissance;
    
}stEtudiantRepere;
int lire_nbre_etudiant(){
    int taille;
    printf("entrez combien d'etidiant voulez vous entrer : ");
    scanf("%d",&taille);
    return taille;
}
void lireTableauEtudiant(stEtudiantRepere *etudiant_info,int num_etudiat){
    printf("\n******Entrez les informations d\'etudiant numéro : %d***********\n",num_etudiat+1);
    printf("entrez votre nom : \n");
    scanf("%s",etudiant_info->nom);
    printf("entrez votre age : \n");
    scanf("%d",&etudiant_info->age);
    printf("entrez votre note : \n");
    scanf("%f",&etudiant_info->note);
    printf("entrer votre jour de naissance : \n");
    scanf("%d",&etudiant_info->dateNaissance.jour);
    printf("entrer votre mois de naissance : \n");
    scanf("%d",&etudiant_info->dateNaissance.mois);
    printf("entrer votre annee de naissance : \n");
    scanf("%d",&etudiant_info->dateNaissance.annee);
}
void afficherEtudiant(stEtudiantRepere *etudiant_info){
    printf("***************************************************\n");
    printf("votre nom est : %s \n",etudiant_info->nom);
    printf("votre age est : %d \n", etudiant_info->age);
    printf("votre note est : %f \n", etudiant_info->note);
    printf("votre date de naissance est \n: %d , %d, %d ", etudiant_info->dateNaissance.annee,etudiant_info->dateNaissance.mois, etudiant_info->dateNaissance.jour);
}

int main(){
    int taille=lire_nbre_etudiant();
    stEtudiantRepere *tab=(stEtudiantRepere *)malloc(taille*sizeof(*tab));
    if(tab==NULL){
        printf("fail to mallocate memory");
        return 1;
    }
    for(int i=0;i<taille;i++){
    lireTableauEtudiant(&tab[i],i);}
    for(int i=0;i<taille;i++){
        afficherEtudiant(&tab[i]);
    }
    free(tab);
    
}
