#include<stdio.h>
int lire_combienDe_module(){
    int nbre_de_module=0;
printf("entrez combien de module vous contenez ");
    scanf("%d",&nbre_de_module);
    return nbre_de_module;
}
float sommeNoteRecursive(int nbre_deModule,const int valeur_fixe)
{
    int note;
    int i=nbre_deModule-1;
    int counter=valeur_fixe-i;
    if (nbre_deModule==0) return 0;
    printf("Pourquoiii note du module numéro : %d ",counter);
    scanf("%d",&note);
    return note+sommeNoteRecursive(i,valeur_fixe);
}
void EcrireLaSomme(float sum){
    printf("la moyness est : %f ",sum);
}
float calculerMoyenne(float somme,int nbre_deModule){
    return somme/nbre_deModule;
}
int main(){
    const int nbre_deModule=lire_combienDe_module();
    EcrireLaSomme(sommeNoteRecursive(nbre_deModule,nbre_deModule));
}