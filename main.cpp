#include "jeu.h"

int main(){
    Jeu test(3);
    test.affichage_grille();

    Jeu fichier("grille/test1");
    fichier.affichage_grille();
}