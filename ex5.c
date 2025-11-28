#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct{
    int notes[3];
}stnotes;//Une structure où aveclaquelle on va stocker les notes;

typedef struct {
        int jour;
        int mois;
        int annee;
    }stDateNaisRepere;//structure de date de naissance
typedef struct {
    char nom[50];
    char prenom[50];
    int age;
    stnotes note;
    float note_moyenne;
    stDateNaisRepere dateNaissance;
}stEtudiantRepere;//structure de l'etudiant qui contient aussi comme champs les notes et la date de naissance;
int lire_nbre_etudiant(){
    int taille;
    printf("entrez combien d'etudiant voulez-vous entrer : ");
    scanf("%d",&taille);
    return taille;
}//lire combien d'etudiant l'utilisateur va saisir;
void check_nbreEtudiant(int *nbre){
    while(*nbre<=0){
        printf("entrez une valeur positive s'il vous plait : \n");
        *nbre=lire_nbre_etudiant();
    }
}//faire une boucle while pour s'assurer que l'utilisateur va entrer une valeur positive;
void validerDateNaissance(stEtudiantRepere *e) {
    time_t t = time(NULL);
struct tm tm = *localtime(&t);
int anneeActuelle = tm.tm_year + 1900;
while(anneeActuelle-e->dateNaissance.annee!=e->age){
    printf("entrez votre annee de naissance : \n");
    scanf("%d",&e->dateNaissance.annee);
    printf("entrez votre age : \n");
    scanf("%d",&e->age);
}
} //verifier que la date de naissance et l'age saisi sont correctes;
void lireEtudiant(stEtudiantRepere *tab){
    printf("entrez votre nom : \n");
    scanf("%s",tab->nom);
    printf("entrez votre prenom : \n");
    scanf("%s",tab->prenom);
    printf("entrer votre jour de naissance : \n");
    scanf("%d",&tab->dateNaissance.jour);
    printf("entrer votre mois de naissance : \n");
    scanf("%d",&tab->dateNaissance.mois);
    printf("entrer votre annee de naissance : \n");
    scanf("%d",&tab->dateNaissance.annee);
    printf("entrez votre age : \n");
    scanf("%d",&tab->age);
    validerDateNaissance(tab);
    printf("entrez votre note des maths: \n");
    scanf("%d",&((*tab).note.notes[0]));
    printf("entrez votre note de physique: \n");
    scanf("%d",&(*tab).note.notes[1]);
    printf("entrez votre note de science: \n");
    scanf("%d",&(tab->note.notes[2]));
}//fonction qui reçoit un pointeur qui pointe dans la structure de chaque étudiants ;
void lireTableauEtudiant(stEtudiantRepere *tab,int nbreEtudiant){
    for(int i=0;i<nbreEtudiant;i++)
    {
    printf("\n      Entrez les informations d\'etudiant numero : %d         \n",i+1);
    lireEtudiant(&tab[i]);
    }
}//passer la structure de chaque étudiant à la fct lireEtudiant.
void afficher_points(stEtudiantRepere *tab){
    printf("la note des maths est : %d\n",tab->note.notes[0]);
    printf("la note de physique est : %d\n",tab->note.notes[1]);
    printf("la note des sciences est : %d\n",tab->note.notes[2]);
}//fct pour afficher les points de chaques  étudiants
void afficherEtudiant(stEtudiantRepere *etudiant_info){
    printf("\n***************************************************\n");
    printf("votre nom est : %s \n",etudiant_info->nom);
    printf("votre prenom est : %s \n",etudiant_info->prenom);
    printf("votre age est : %d \n", etudiant_info->age);
    afficher_points(etudiant_info);
    printf("votre date de naissance est :\n annee: %d",etudiant_info->dateNaissance.annee) ;
    printf("mois: %d",etudiant_info->dateNaissance.mois);
    printf("jour : %d \n", etudiant_info->dateNaissance.jour);
}//afficher les infos de chaque étudiant.
void afficherTableauEtudiant(stEtudiantRepere *tab,int nbreEtudiant){
    for(int i=0;i<nbreEtudiant;i++)
    {
        afficherEtudiant(&tab[i]);
    }
}//fct qui conssite à envoyer la structure correspondante à chaque étudiant à la fct afficherEtudiant pour l'afficher.
float calculerMoyennePonderee(stEtudiantRepere e){
        e.note_moyenne=(float)(e.note.notes[0]*2+e.note.notes[1]+e.note.notes[2])/4;/*la relation de calcul de
        la moyenne donnée dans l'exercice*/
        return e.note_moyenne;
    }
void saisir_tableauNote(stEtudiantRepere *tab,int nbreEtudiant){
    for(int i=0;i<nbreEtudiant;i++){
        tab[i].note_moyenne=calculerMoyennePonderee(tab[i]);
    }
}//fct qui stocke la valeur de note moyenne de chaque étudiant.
float sommeNoteRecursive(stEtudiantRepere *tab,int nbreEtudiant,int x)
{
    int counter=nbreEtudiant-x;
    if (counter==nbreEtudiant) return 0;
    return (tab+counter)->note_moyenne+sommeNoteRecursive(tab,nbreEtudiant,x-1);
}//fct qui calculer la somme des notes de la classe
float calculerMoyenne(float somme,int nbreEtudiant){
    return (float)somme/nbreEtudiant;
}//calculer la moyenne de la classe
int ajoutDePersonne(){
    int reponse;
    printf("\nvoulez-vous ajouter des personnes : 1-->oui/0-->non\n");
    scanf("%d",&reponse);
    return reponse;
}//fct qui demande à l'utilisateur est ce qu'il veut ajouter autre étudiant;
int ajouter_ouNon(int reponse){
    if(reponse!=0){
        int nbre_ajoute=0;
        printf("combien de personne voulez-vous ajouter\n");//lire le nbre d'etudiant à ajouter.
        scanf("%d",&nbre_ajoute);
        return nbre_ajoute;
    }
    else{
        printf("          FIN            ");
        return 0;
    }
}//fct qui analyse la reponse de l'utilisateur et décide l'ajout ou non d'un nouvel étudiant.
int main(){
    int nbreEtudiant_ajoute=0;//initialisation de variable pour ne pas avoir des valeurs aléatoire.
    int nbreEtudiant=lire_nbre_etudiant();
    check_nbreEtudiant(&nbreEtudiant);//verifier est ce que le nbre est positif
    stEtudiantRepere *tab=(stEtudiantRepere *)malloc(nbreEtudiant*sizeof(*tab));/*construire un tableu de type
     enEtudiantRepere en utilisant malloc*/
    if(tab==NULL){
        printf("fail to mallocate memory");
        return 1;
    }//au cas d'echec de construction de ce tableau afficher un message et arreter le programme;
    lireTableauEtudiant(tab,nbreEtudiant);//lire les informations
    afficherTableauEtudiant(tab,nbreEtudiant);//afficher les informations de chaque étudiant
    saisir_tableauNote(tab,nbreEtudiant);
    printf("\nla moyenne de la classe :%f",calculerMoyenne(sommeNoteRecursive(tab,nbreEtudiant,nbreEtudiant),nbreEtudiant));
    do{
    nbreEtudiant_ajoute=ajouter_ouNon(ajoutDePersonne());//lire combien d'etudiant à ajouter
    if(nbreEtudiant_ajoute==0){
        break;
    }
    int nouveau_nbreEtudiant=nbreEtudiant+nbreEtudiant_ajoute;//determiner la nouvel taille de tableau
    stEtudiantRepere *Ntab=(stEtudiantRepere*)realloc(tab,nouveau_nbreEtudiant*sizeof(*Ntab));/*renover le tableau 
    en utilisant realloc qui cous permettra d'ajouter des nouveaux étudiants*/
    tab=Ntab;//resaisi l'adresse de tab;
    if(Ntab==NULL){
        printf("memory failed to aoizdllocate");
        return 1;
    }
    for(int i=nbreEtudiant;i<nouveau_nbreEtudiant;i++)
    {
    lireEtudiant((Ntab+i));
    Ntab[i].note_moyenne=calculerMoyennePonderee(Ntab[i]);
    }
        printf("\nla classe a un moyenne zeid, est%f",calculerMoyenne(sommeNoteRecursive(Ntab,nouveau_nbreEtudiant,nouveau_nbreEtudiant),nouveau_nbreEtudiant));

}while(nbreEtudiant_ajoute);
free(tab);//liberer le tableau;
 return 0;
}